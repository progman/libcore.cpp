//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.3.4
// Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#define _LARGE_FILE_API

#include <algorithm>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "libcore.hpp"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#if (INTPTR_MAX != INT32_MAX) && (INTPTR_MAX != INT64_MAX)
#error "need 32-bit or 64-bit"
#endif
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
static uint8_t hex2bin_table[] =
{
//	0x00  0x01  0x02  0x03  0x04  0x05  0x06  0x07  0x08  0x09  0x0A  0x0B  0x0C  0x0D  0x0E  0x0F
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0x00
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0x10
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0x20
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0x30
	0xff, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0x40
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0x50
	0xff, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0x60
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0x70
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0x80
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0x90
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0xA0
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0xB0
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0xC0
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0xD0
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // 0xE0
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff  // 0xF0
};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/*
static const char *byte2str_table[] =
{
	  "0",   "1",   "2",   "3",   "4",   "5",   "6",   "7",   "8",   "9",  "10",  "11",  "12",  "13",  "14",  "15",
	 "16",  "17",  "18",  "19",  "20",  "21",  "22",  "23",  "24",  "25",  "26",  "27",  "28",  "29",  "30",  "31",
	 "32",  "33",  "34",  "35",  "36",  "37",  "38",  "39",  "40",  "41",  "42",  "43",  "44",  "45",  "46",  "47",
	 "48",  "49",  "50",  "51",  "52",  "53",  "54",  "55",  "56",  "57",  "58",  "59",  "60",  "61",  "62",  "63",
	 "64",  "65",  "66",  "67",  "68",  "69",  "70",  "71",  "72",  "73",  "74",  "75",  "76",  "77",  "78",  "79",
	 "80",  "81",  "82",  "83",  "84",  "85",  "86",  "87",  "88",  "89",  "90",  "91",  "92",  "93",  "94",  "95",
	 "96",  "97",  "98",  "99", "100", "101", "102", "103", "104", "105", "106", "107", "108", "109", "110", "111",
	"112", "113", "114", "115", "116", "117", "118", "119", "120", "121", "122", "123", "124", "125", "126", "127",
	"128", "129", "130", "131", "132", "133", "134", "135", "136", "137", "138", "139", "140", "141", "142", "143",
	"144", "145", "146", "147", "148", "149", "150", "151", "152", "153", "154", "155", "156", "157", "158", "159",
	"160", "161", "162", "163", "164", "165", "166", "167", "168", "169", "170", "171", "172", "173", "174", "175",
	"176", "177", "178", "179", "180", "181", "182", "183", "184", "185", "186", "187", "188", "189", "190", "191",
	"192", "193", "194", "195", "196", "197", "198", "199", "200", "201", "202", "203", "204", "205", "206", "207",
	"208", "209", "210", "211", "212", "213", "214", "215", "216", "217", "218", "219", "220", "221", "222", "223",
	"224", "225", "226", "227", "228", "229", "230", "231", "232", "233", "234", "235", "236", "237", "238", "239",
	"240", "241", "242", "243", "244", "245", "246", "247", "248", "249", "250", "251", "252", "253", "254", "255"
};
*/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert uint to string
 * \param[out] result string result
 * \param[in] source uint source
 * \param[in] fill_count fill count
 * \param[in] fill_char char for fill
 * \param[in] flag_plus enable '+' before string
 * \return flag correct convertion
 */
bool libcore::uint2str(std::string &result, uint64_t source, uint8_t fill_count, char fill_char, bool flag_plus)
{
//0         1         2         3
//0123456789012345678901234567890123456789
//+000000000000000000000000001917
//18446744073709551615
//-9223372036854775806
//+9223372036854775807
	char s[32];
	char *p = s + (sizeof(s) - 1);


	*p = '\0';
	p--;


	for (;;)
	{
		*p = (source % 10) + '0';
		p--;
		source /= 10;
		if (source == 0) break;
	}


	if (fill_count != 0)
	{
		if (fill_count > (sizeof(s) - 2))
		{
			fill_count = (sizeof(s) - 2);
		}
		int max = fill_count - (sizeof(s) - (p - s)) + 2;
		for (int j=0; j < max; j++)
		{
			*p = fill_char;
			p--;
		}
	}


	if (flag_plus != false)
	{
		*p = '+';
		p--;
	}


	result = ++p;


	return true;
}
/*
bool libcore::uint2str(std::string &result, uint64_t source, uint8_t zero_count)
{
	char buf[128], format[128];

	if (zero_count == 0)
	{
#if (INTPTR_MAX == INT32_MAX)
		sprintf(buf, "%llu", source);
#endif
#if (INTPTR_MAX == INT64_MAX)
		sprintf(buf, "%lu", source);
#endif
	}
	else
	{
#if (INTPTR_MAX == INT32_MAX)
		sprintf(format, "%%0%ullu", zero_count);
		sprintf(buf, format, source);
#endif
#if (INTPTR_MAX == INT64_MAX)
		sprintf(format, "%%0%ulu", zero_count);
		sprintf(buf, format, source);
#endif
	}

	result = buf;

	return true;
}
*/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert sint to string
 * \param[out] result string result
 * \param[in] source int source
 * \param[in] fill_count fill count
 * \param[in] fill_char char for fill
 * \param[in] flag_plus enable '+' before string
 * \return flag correct convertion
 */
bool libcore::sint2str(std::string &result, int64_t source, uint8_t fill_count, char fill_char, bool flag_plus)
{
	if (source >= 0)
	{
		return libcore::uint2str(result, source, fill_count, fill_char, flag_plus);
	}


	source = -source;


//0         1         2         3
//0123456789012345678901234567890123456789
//+000000000000000000000000001917
//18446744073709551615
//-9223372036854775806
//+9223372036854775807
	char s[32];
	char *p = s + (sizeof(s) - 1);


	*p = '\0';
	p--;


	for (;;)
	{
		*p = (source % 10) + '0';
		p--;
		source /= 10;
		if (source == 0) break;
	}


	if (fill_count != 0)
	{
		if (fill_count > (sizeof(s) - 2))
		{
			fill_count = (sizeof(s) - 2);
		}
		int max = fill_count - (sizeof(s) - (p - s)) + 2;
		for (int j=0; j < max; j++)
		{
			*p = fill_char;
			p--;
		}
	}


	*p = '-';
	p--;


	result = ++p;


	return true;
}
/*
bool libcore::sint2str(std::string &result, int64_t source, uint8_t zero_count)
{
	char buf[128], format[128];

	if (zero_count == 0)
	{
#if (INTPTR_MAX == INT32_MAX)
		sprintf(buf, "%lld", source);
#endif
#if (INTPTR_MAX == INT64_MAX)
		sprintf(buf, "%ld", source);
#endif
	}
	else
	{
#if (INTPTR_MAX == INT32_MAX)
		sprintf(format, "%%0%ulld", zero_count);
		sprintf(buf, format, source);
#endif
#if (INTPTR_MAX == INT64_MAX)
		sprintf(format, "%%0%uld", zero_count);
		sprintf(buf, format, source);
#endif
	}

	result = buf;

	return true;
}
*/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp 0x[0-9a-fA-F]+
 * \param[in] pstr string
 * \param[in] size size string
 * \param[in] flag_prefix must prefix '0x'
 * \return flag correct check
 */
bool libcore::is_hex(const char *pstr, size_t size, bool flag_prefix)
{
	if (pstr == NULL) return false;
	if (size == 0) return false;


	if (size == size_t(-1))
	{
		if (*pstr == 0) return false;
		if ((pstr[0] == '0') && (pstr[1] == 'x'))
		{
			pstr++;
			pstr++;
		}
		else
		{
			if (flag_prefix == true)
			{
				return false;
			}
		}


		const char *pstr_start = pstr;
		for (;; pstr++)
		{
			uint8_t ch = *pstr;

			if (ch == 0)
			{
				break;
			}

			if (::hex2bin_table[ch] == 0xff)
			{
				return false;
			}
		}
		if (pstr == pstr_start)
		{
			return false;
		}
	}
	else
	{
		if ((size > 1) && (pstr[0] == '0') && (pstr[1] == 'x'))
		{
			pstr++;
			pstr++;
			size--;
			size--;
			if (size == 0) return false;
		}
		else
		{
			if (flag_prefix == true)
			{
				return false;
			}
		}


		const char *pstr_end = pstr + size;
		for (; pstr != pstr_end; pstr++)
		{
			uint8_t ch = *pstr;

			if (::hex2bin_table[ch] == 0xff)
			{
				return false;
			}
		}
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp 0x[0-9a-fA-F]+
 * \param[in] str string
 * \param[in] flag_prefix must prefix '0x'
 * \return flag correct check
 */
bool libcore::is_hex(const std::string &str, bool flag_prefix)
{
	return libcore::is_hex(str.c_str(), str.size(), flag_prefix);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp [+]?[0-9]+
 * \param[in] pstr string
 * \param[in] size size string
 * \return flag correct check
 */
bool libcore::is_udec(const char *pstr, size_t size)
{
	if (pstr == NULL) return false;
	if (size == 0) return false;


	if (size == size_t(-1))
	{
		if (*pstr == '+')
		{
			pstr++;
		}


		const char *pstr_start = pstr;
		for (;; pstr++)
		{
			char ch = *pstr;

			if (ch == 0)
			{
				break;
			}

			if
			(
				(ch < '0') ||
				(ch > '9')
			)
			{
				return false;
			}
		}
		if (pstr == pstr_start)
		{
			return false;
		}
	}
	else
	{
		if (*pstr == '+')
		{
			pstr++;
			size--;
			if (size == 0) return false;
		}


		const char *pstr_end = pstr + size;
		for (; pstr != pstr_end; pstr++)
		{
			char ch = *pstr;

			if
			(
				(ch < '0') ||
				(ch > '9')
			)
			{
				return false;
			}
		}
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp [+]?[0-9]+
 * \param[in] str string
 * \return flag correct check
 */
bool libcore::is_udec(const std::string &str)
{
	return libcore::is_udec(str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp [-+]?[0-9]+
 * \param[in] pstr string
 * \param[in] size size string
 * \return flag correct check
 */
bool libcore::is_sdec(const char *pstr, size_t size)
{
	if (pstr == NULL) return false;
	if (size == 0) return false;


	if (size == size_t(-1))
	{
		if ((*pstr == '-') || (*pstr == '+'))
		{
			pstr++;
		}


		const char *pstr_start = pstr;
		for (;; pstr++)
		{
			char ch = *pstr;

			if (ch == 0)
			{
				break;
			}

			if
			(
				(ch < '0') ||
				(ch > '9')
			)
			{
				return false;
			}
		}
		if (pstr == pstr_start)
		{
			return false;
		}
	}
	else
	{
		if ((*pstr == '-') || (*pstr == '+'))
		{
			pstr++;
			size--;
			if (size == 0) return false;
		}


		const char *pstr_end = pstr + size;
		for (; pstr != pstr_end; pstr++)
		{
			char ch = *pstr;

			if
			(
				(ch < '0') ||
				(ch > '9')
			)
			{
				return false;
			}
		}
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp [-+]?[0-9]+
 * \param[in] str string
 * \return flag correct check
 */
bool libcore::is_sdec(const std::string &str)
{
	return libcore::is_sdec(str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check 0 < number < pstr_max
 * \param[in] pstr_max string with max number
 * \param[in] pstr string with test number
 * \param[in] size size string
 * \return flag correct check
 */
bool libcore::is_uint_string_overflow(const char *pstr_max, const char *pstr, size_t size)
{
	if
	(
		(pstr_max == NULL) ||
		(pstr     == NULL)
	)
	{
		return false;
	}


	if (*pstr_max == '-')
	{
		return false;
	}
	if (*pstr == '-')
	{
		return false;
	}


	if (*pstr_max == '+')
	{
		pstr_max++;
	}
	if (*pstr == '+')
	{
		pstr++;
		size--;
	}


	size_t str_max_size = strlen(pstr_max);


// check size input string
	if (size > str_max_size)
	{
		return false;
	}
	if (size < str_max_size)
	{
		return true;
	}


// size == str_max_size
	for (size_t i=0; i < str_max_size; i++)
	{
		if (pstr_max[i] > pstr[i])
		{
			break;
		}

		if (pstr_max[i] < pstr[i])
		{
			return false;
		}
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check 0 < number < pstr_max
 * \param[in] pstr_max string with max number
 * \param[in] str string with test number
 * \return flag correct check
 */
bool libcore::is_uint_string_overflow(const char *pstr_max, const std::string &str)
{
	return libcore::is_uint_string_overflow(pstr_max, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check pstr_min < number < pstr_max
 * \param[in] pstr_min string with min number
 * \param[in] pstr_max string with max number
 * \param[in] pstr string with test number
 * \param[in] size size string
 * \return flag correct check
 */
bool libcore::is_sint_string_overflow(const char *pstr_min, const char *pstr_max, const char *pstr, size_t size)
{
	if
	(
		(pstr_min == NULL) ||
		(pstr_max == NULL) ||
		(pstr     == NULL)
	)
	{
		return false;
	}


	if (*pstr_min == '+')
	{
		return false;
	}
	if (*pstr_max == '-')
	{
		return false;
	}


	bool flag_positive = true;
	if (*pstr == '-')
	{
		flag_positive = false;
	}


	if (*pstr_min == '-')
	{
		pstr_min++;
	}
	if (*pstr_max == '+')
	{
		pstr_max++;
	}
	if ((*pstr == '-') || (*pstr == '+'))
	{
		pstr++;
		size--;
	}


	size_t str_min_size = strlen(pstr_min);
	size_t str_max_size = strlen(pstr_max);


	if (str_min_size != str_max_size)
	{
		return false;
	}


// check size input string
	if (size > str_max_size)
	{
		return false;
	}
	if (size < str_max_size)
	{
		return true;
	}


// size == str_max_size
	if (flag_positive == false)
	{
		for (size_t i=0; i < str_min_size; i++)
		{
			if (pstr_min[i] > pstr[i])
			{
				break;
			}

			if (pstr_min[i] < pstr[i])
			{
				return false;
			}
		}
	}
	else
	{
		for (size_t i=0; i < str_max_size; i++)
		{
			if (pstr_max[i] > pstr[i])
			{
				break;
			}

			if (pstr_max[i] < pstr[i])
			{
				return false;
			}
		}
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check pstr_min < number < pstr_max
 * \param[in] pstr_min string with min number
 * \param[in] pstr_max string with max number
 * \param[in] str string with test number
 * \return flag correct check
 */
bool libcore::is_sint_string_overflow(const char *pstr_min, const char *pstr_max, const std::string &str)
{
	return libcore::is_sint_string_overflow(pstr_min, pstr_max, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, uint64_t default_value, const char *pstr, size_t size)
{
	if ((pstr == NULL) || (size == 0))
	{
		result = default_value;
		return false;
	}


	if (*pstr != '0')
	{
		result = default_value;
		return false;
	}
	pstr++;
	size--;

	if (*pstr != 'x')
	{
		result = default_value;
		return false;
	}
	pstr++;
	size--;


	if (size == 0)
	{
		result = default_value;
		return false;
	}


	char ch1, ch2;
	uint8_t r1, r2, out;


	size_t byte_count = size / 2;
	if (byte_count > sizeof(uint64_t))
	{
		result = default_value;
		return false;
	}

	bool flag_parity = true;
	if ((byte_count * 2) != size)
	{
		flag_parity = false;
		byte_count++;
	}


	result = 0;
	for (;;)
	{
		if (flag_parity == false)
		{
			ch1 = '0';
			flag_parity = true;
		}
		else
		{
			ch1 = *pstr;
			pstr++;
		}
		ch2 = *pstr;
		pstr++;


		if (libcore::hex2bin((uint8_t)ch1, r1) == false)
		{
			result = default_value;
			return false;
		}
		if (libcore::hex2bin((uint8_t)ch2, r2) == false)
		{
			result = default_value;
			return false;
		}
		out = (uint8_t)((r1 << 4) + r2);


		result <<= 8;
		result |= out;
		byte_count--;


		if (byte_count == 0) break;
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, uint64_t default_value, const char *pstr)
{
	return libcore::hex2uint(result, default_value, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] str source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, uint64_t default_value, const std::string &str)
{
	return libcore::hex2uint(result, default_value, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, const char *pstr, size_t size)
{
	return libcore::hex2uint(result, 0, pstr, size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] pstr source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, const char *pstr)
{
	return libcore::hex2uint(result, 0, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] str source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, const std::string &str)
{
	return libcore::hex2uint(result, 0, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, int64_t default_value, const char *pstr, size_t size)
{
	bool rc;
	uint64_t tmp;

	rc = libcore::hex2uint(tmp, (uint64_t)default_value, pstr, size);
	if (rc == false)
	{
		result = tmp;
		return rc;
	}

	result = libcore::sign_expand(tmp);
	return rc;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, int64_t default_value, const char *pstr)
{
	return libcore::hex2sint(result, default_value, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] str source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, int64_t default_value, const std::string &str)
{
	return libcore::hex2sint(result, default_value, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, const char *pstr, size_t size)
{
	return libcore::hex2sint(result, 0, pstr, size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] pstr source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, const char *pstr)
{
	return libcore::hex2sint(result, 0, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] str source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, const std::string &str)
{
	return libcore::hex2sint(result, 0, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * expand sign in value, example: 0xff -> -1, 0xffff -> -1, ...
 * \param[in] value unsign value
 * \return sign value
 */
int64_t libcore::sign_expand(const uint64_t value)
{
	if (value & (uint64_t(-1) << 32)) // 0xffffffff00000000
	{
		return (int64_t)value;
	}

	if (value & (uint64_t(-1) << 16)) // 0xffffffffffff0000
	{
		return (int32_t)value;
	}

	if (value & (uint64_t(-1) << 8))  // 0xffffffffffffff00
	{
		return (int16_t)value;
	}

	return (int8_t)value;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, uint64_t default_value, const char *pstr, size_t size)
{
// check correct data input string
	if (libcore::is_udec(pstr, size) == false)
	{
		value = default_value;
		return false;
	}


// check overflow
	if (libcore::is_uint_string_overflow("18446744073709551615", pstr, size) == false)
	{
		value = default_value;
		return false;
	}


// convert it
	value = strtoull(pstr, NULL, 10); // atoll
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, uint64_t default_value, const char *pstr)
{
	return libcore::dec2uint(value, default_value, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, uint64_t default_value, const std::string &str)
{
	return libcore::dec2uint(value, default_value, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, const char *pstr, size_t size)
{
	return libcore::dec2uint(value, 0, pstr, size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, const char *pstr)
{
	return libcore::dec2uint(value, 0, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, const std::string &str)
{
	return libcore::dec2uint(value, 0, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, int64_t default_value, const char *pstr, size_t size)
{
// check correct data input string
	if (libcore::is_sdec(pstr, size) == false)
	{
		value = default_value;
		return false;
	}


// check overflow
	if (libcore::is_sint_string_overflow("-9223372036854775806", "+9223372036854775807", pstr, size) == false)
	{
		value = default_value;
		return false;
	}

/*
	if (*pstr == '-')
	{
		if (libcore::is_numeric_string_overflow("-9223372036854775806", pstr, size) == false)
		{
			value = default_value;
			return false;
		}
	}
	else
	{
		if (libcore::is_numeric_string_overflow("+9223372036854775807", pstr, size) == false)
		{
			value = default_value;
			return false;
		}
	}
*/

// convert it
	value = strtoll(pstr, NULL, 10); // atoll
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, int64_t default_value, const char *pstr)
{
	return libcore::dec2sint(value, default_value, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, int64_t  default_value, const std::string &str)
{
	return libcore::dec2sint(value, default_value, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, const char *pstr, size_t size)
{
	return libcore::dec2sint(value, 0, pstr, size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, const char *pstr)
{
	return libcore::dec2sint(value, 0, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, const std::string &str)
{
	return libcore::dec2sint(value, 0, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert const char * to uint
bool libcore::str2uint(uint64_t &value, uint64_t default_value, const char *pstr, size_t size)
{
	if (size == 0)
	{
		value = default_value;
		return false;
	}


	if (libcore::hex2uint(value, default_value, pstr, size) != false)
	{
		return true;
	}


	if (libcore::dec2sint((int64_t &)value, (int64_t &)default_value, pstr, size) != false)
	{
		return true;
	}


	return libcore::dec2uint(value, default_value, pstr, size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert const char * to uint
bool libcore::str2uint(uint64_t &value, uint64_t default_value, const char *pstr)
{
	return libcore::str2uint(value, default_value, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert const char * to uint
bool libcore::str2uint(uint64_t &value, uint64_t default_value, const std::string &str)
{
	return libcore::str2uint(value, default_value, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert const char * to uint
bool libcore::str2uint(uint64_t &value, const char *pstr, size_t size)
{
	return libcore::str2uint(value, 0, pstr, size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert const char * to uint
bool libcore::str2uint(uint64_t &value, const char *pstr)
{
	return libcore::str2uint(value, 0, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert const char * to uint
bool libcore::str2uint(uint64_t &value, const std::string &str)
{
	return libcore::str2uint(value, 0, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::str2bool(bool &result, bool default_value, const char *str)
{
	if (strcasecmp(str, "1")    == 0)
	{
		result = true;
		return true;
	}
	if (strcasecmp(str, "t")    == 0)
	{
		result = true;
		return true;
	}
	if (strcasecmp(str, "on")   == 0)
	{
		result = true;
		return true;
	}
	if (strcasecmp(str, "true") == 0)
	{
		result = true;
		return true;
	}


	if (strcasecmp(str, "0")    == 0)
	{
		result = false;
		return true;
	}
	if (strcasecmp(str, "f")    == 0)
	{
		result = false;
		return true;
	}
	if (strcasecmp(str, "off")   == 0)
	{
		result = false;
		return true;
	}
	if (strcasecmp(str, "false") == 0)
	{
		result = false;
		return true;
	}


	result = default_value;
	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::str2bool(bool &result, bool default_value, const std::string &str)
{
	return libcore::str2bool(result, default_value, str.c_str());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::str2bool(bool &result, const char *str)
{
	return libcore::str2bool(result, false, str);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::str2bool(bool &result, const std::string &str)
{
	return libcore::str2bool(result, false, str.c_str());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert byte to hex string
const char *libcore::bin2hex(const uint8_t byte, bool flag_up)
{
	static const char *const bin2hex_table[] =
	{
//		 00    01    02    03    04    05    06    07    08    09    0a    0b    0c    0d    0e    0f
		"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "0a", "0b", "0c", "0d", "0e", "0f", // 00
		"10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "1a", "1b", "1c", "1d", "1e", "1f", // 10
		"20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "2a", "2b", "2c", "2d", "2e", "2f", // 20
		"30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "3a", "3b", "3c", "3d", "3e", "3f", // 30
		"40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "4a", "4b", "4c", "4d", "4e", "4f", // 40
		"50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "5a", "5b", "5c", "5d", "5e", "5f", // 50
		"60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "6a", "6b", "6c", "6d", "6e", "6f", // 60
		"70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "7a", "7b", "7c", "7d", "7e", "7f", // 70
		"80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "8a", "8b", "8c", "8d", "8e", "8f", // 80
		"90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "9a", "9b", "9c", "9d", "9e", "9f", // 90
		"a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "a9", "aa", "ab", "ac", "ad", "ae", "af", // a0
		"b0", "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "b9", "ba", "bb", "bc", "bd", "be", "bf", // b0
		"c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c9", "ca", "cb", "cc", "cd", "ce", "cf", // c0
		"d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7", "d8", "d9", "da", "db", "dc", "dd", "de", "df", // d0
		"e0", "e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8", "e9", "ea", "eb", "ec", "ed", "ee", "ef", // e0
		"f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8", "f9", "fa", "fb", "fc", "fd", "fe", "ff"  // f0
	};

	static const char *const bin2hex_up_table[] =
	{
//		 00    01    02    03    04    05    06    07    08    09    0A    0B    0C    0D    0E    0F
		"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "0A", "0B", "0C", "0D", "0E", "0F", // 00
		"10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "1A", "1B", "1C", "1D", "1E", "1F", // 10
		"20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "2A", "2B", "2C", "2D", "2E", "2F", // 20
		"30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "3A", "3B", "3C", "3D", "3E", "3F", // 30
		"40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "4A", "4B", "4C", "4D", "4E", "4F", // 40
		"50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "5A", "5B", "5C", "5D", "5E", "5F", // 50
		"60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "6A", "6B", "6C", "6D", "6E", "6F", // 60
		"70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "7A", "7B", "7C", "7D", "7E", "7F", // 70
		"80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "8A", "8B", "8C", "8D", "8E", "8F", // 80
		"90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "9A", "9B", "9C", "9D", "9E", "9F", // 90
		"A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "AA", "AB", "AC", "AD", "AE", "AF", // A0
		"B0", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "BA", "BB", "BC", "BD", "BE", "BF", // B0
		"C0", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CA", "CB", "CC", "CD", "CE", "CF", // C0
		"D0", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DA", "DB", "DC", "DD", "DE", "DF", // D0
		"E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "EA", "EB", "EC", "ED", "EE", "EF", // E0
		"F0", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "FA", "FB", "FC", "FD", "FE", "FF"  // F0
	};


	return (flag_up == false) ? bin2hex_table[byte] : bin2hex_up_table[byte];
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert sibmol to number, example: '0' -> 0, 'F' -> 15
bool libcore::hex2bin(uint8_t source, uint8_t &target)
{
	target = ::hex2bin_table[source];

	return (target == 0xff) ? false : true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// block read from handle
size_t libcore::blk_read(int handle, off64_t offset, void *pdata, size_t size)
{
	if (offset != off64_t(-1))
	{
		int rc = ::lseek64(handle, offset, SEEK_SET);
		if (rc == -1) return -1;
	}


	uint8_t *p = (uint8_t *)pdata;
	size_t cur_size = size;

	for (;;)
	{
		size_t rc = ::read(handle, p, cur_size);
		if (rc == 0) return -1;
		if (rc == size_t(-1)) return -1;

		p += rc;
		cur_size -= rc;

		if (cur_size == 0) break;
	}


	return size;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// block write to handle
size_t libcore::blk_write(int handle, off64_t offset, const void *pdata, size_t size, bool flag_sync)
{
	if (offset != off64_t(-1))
	{
		int rc = ::lseek64(handle, offset, SEEK_SET);
		if (rc == -1) return -1;
	}


	uint8_t *p = (uint8_t *)pdata;
	size_t cur_size = size;

	for (;;)
	{
		size_t rc = ::write(handle, p, cur_size);
		if (rc == size_t(-1)) return -1;

		p += rc;
		cur_size -= rc;

		if (cur_size == 0) break;
	}


// fsync file
	if (flag_sync != false)
	{
		int rc = ::fdatasync(handle);
		if (rc == -1)
		{
			return -1;
		}
	}


	return size;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// block recv from handle
size_t libcore::blk_recv(int handle, void *pdata, size_t size)
{
	uint8_t *p_cur = (uint8_t *)pdata;
	size_t count = size;


	for (;;)
	{
		ssize_t size_cur = ::recv(handle, p_cur, count, MSG_NOSIGNAL);
		if (size_cur == -1) return -1;

		count -= size_cur;
		p_cur += size_cur;

		if (count == 0) break;
	}


	return size;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// block send to handle
size_t libcore::blk_send(int handle, const void *pdata, size_t size)
{
	uint8_t *p_cur = (uint8_t *)pdata;
	size_t count = size;


	for (;;)
	{
		ssize_t size_cur = ::send(handle, p_cur, count, MSG_NOSIGNAL);
		if (size_cur == -1) return -1;

		count -= size_cur;
		p_cur += size_cur;

		if (count == 0) break;
	}


	return size;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// file open read only
int libcore::file_open_ro(const char *pfilename)
{
	return ::open(pfilename, O_RDONLY);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// file open read/write
int libcore::file_open_rw(const char *pfilename, bool flag_truncate, bool flag_excl)
{
// set open flags
	int open_flags = O_WRONLY | O_CREAT | O_LARGEFILE;
	if (flag_truncate != false)
	{
		open_flags |= O_TRUNC;
	}
	if (flag_excl != false)
	{
		open_flags |= O_EXCL;
	}


// open file
	umask(0);
	return ::open(pfilename, open_flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// file close
int libcore::file_close(int handle, bool flag_sync)
{
	int rc;


// fsync file
	if (flag_sync != false)
	{
		rc = ::fdatasync(handle);
		if (rc == -1)
		{
			rc = errno;
			::close(handle);
			errno = rc;
			return -1;
		}
	}


// close file
	rc = ::close(handle);
	if (rc == -1)
	{
		return -1;
	}


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// read data from exist file
int libcore::file_get(const char *pfilename, off_t offset, void *pdata, size_t data_size)
{
	int rc;


// open file
	rc = libcore::file_open_ro(pfilename);
	if (rc == -1)
	{
		return -1;
	}
	int fd = rc;


// get file size
	struct stat my_stat;
	rc = ::fstat(fd, &my_stat);
	if (rc == -1)
	{
		rc = errno;
		::close(fd);
		errno = rc;
		return -1;
	}
	size_t size = my_stat.st_size;


// check offset
	if ((offset + data_size) > size)
	{
		errno = EINVAL;
		return -1;
	}


// read from file
	rc = libcore::blk_read(fd, offset, pdata, data_size);
	if (rc == -1)
	{
		rc = errno;
		::close(fd);
		errno = rc;
		return -1;
	}


// close file
	rc = libcore::file_close(fd, false);
	if (rc == -1)
	{
		return -1;
	}


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// read data from exist file
int libcore::file_get(const char *pfilename, void **pdata, size_t *data_size)
{
	int rc;

	struct stat buf;
	rc = ::stat(pfilename, &buf);
	if (rc != 0)
	{
		return -1;
	}
	*data_size = buf.st_size;

	*pdata = ::malloc(*data_size);
	if (*pdata == NULL)
	{
		return -1;
	}

	rc = libcore::file_get(pfilename, 0, *pdata, *data_size);
	if (rc == -1)
	{
		::free(*pdata);
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// read data from exist file
int libcore::file_get(const char *pfilename, std::string &data)
{
	int rc;
	void *pdata;
	size_t data_size;

	rc = libcore::file_get(pfilename, &pdata, &data_size);
	if (rc == -1)
	{
		return -1;
	}

	data = std::string((const char *)pdata, data_size);
	::free(pdata);

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// write data to exist file
int libcore::file_set(const char *pfilename, off_t offset, const void *pdata, size_t data_size, bool flag_sync, bool flag_truncate, bool flag_excl)
{
	int rc;


// open file
	rc = libcore::file_open_rw(pfilename, flag_truncate, flag_excl);
	if (rc == -1)
	{
		return -1;
	}
	int fd = rc;


// write to file
	rc = libcore::blk_write(fd, offset, pdata, data_size, false);
	if (rc == -1)
	{
		rc = errno;
		::close(fd);
		errno = rc;
		return -1;
	}


// close file
	rc = libcore::file_close(fd, flag_sync);
	if (rc == -1)
	{
		return -1;
	}


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// write data to exist file
int libcore::file_set(const char *pfilename, off_t offset, const std::string &data, bool flag_sync, bool flag_truncate, bool flag_excl)
{
	return libcore::file_set(pfilename, offset, data.c_str(), data.size(), flag_sync, flag_truncate, flag_excl);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// write data to exist file
int libcore::file_set(const char *pfilename, const std::string &data, bool flag_sync, bool flag_truncate, bool flag_excl)
{
	return libcore::file_set(pfilename, 0, data.c_str(), data.size(), flag_sync, flag_truncate, flag_excl);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// return (concat str1 and str2) or NULL
char *libcore::concat_str(const char *pstr1, const char *pstr2)
{
	if ((pstr1 == NULL) || (pstr2 == NULL)) return NULL;

	size_t str1_size = strlen(pstr1);
	size_t str2_size = strlen(pstr2);

	char *pstr3 = (char *)malloc(str1_size + str2_size + 1);
	if (pstr3 == NULL)
	{
		return NULL;
	}

	memcpy(pstr3, pstr1, str1_size);
	memcpy(pstr3 + str1_size, pstr2, str2_size);
	pstr3[str1_size + str2_size] = 0;

	return pstr3;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// get env var and convert to bool
bool libcore::env2bool(bool &result, bool value_default, const char *pname)
{
	char *p = getenv(pname);
	if (p == NULL)
	{
		result = value_default;
		return false;
	}

	if (libcore::str2bool(result, value_default, p) == false)
	{
		return false;
	}

	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// signal name
const char *libcore::get_signal_name(const int sig)
{
	struct
	{
		int sig;
		const char *sig_name;
	}
	signal_list[] =
	{
#ifdef SIGHUP
		{ SIGHUP,    "SIGHUP"    },
#endif
#ifdef SIGINT
		{ SIGINT,    "SIGINT"    },
#endif
#ifdef SIGQUIT
		{ SIGQUIT,   "SIGQUIT"   },
#endif
#ifdef SIGILL
		{ SIGILL,    "SIGILL"    },
#endif
#ifdef SIGABRT
		{ SIGABRT,   "SIGABRT"   },
#endif
#ifdef SIGFPE
		{ SIGFPE,    "SIGFPE"    },
#endif
#ifdef SIGKILL
		{ SIGKILL,   "SIGKILL"   },
#endif
#ifdef SIGSEGV
		{ SIGSEGV,   "SIGSEGV"   },
#endif
#ifdef SIGPIPE
		{ SIGPIPE,   "SIGPIPE"   },
#endif
#ifdef SIGALRM
		{ SIGALRM,   "SIGALRM"   },
#endif
#ifdef SIGTERM
		{ SIGTERM,   "SIGTERM"   },
#endif
#ifdef SIGUSR1
		{ SIGUSR1,   "SIGUSR1"   },
#endif
#ifdef SIGUSR2
		{ SIGUSR2,   "SIGUSR2"   },
#endif
#ifdef SIGCHLD
		{ SIGCHLD,   "SIGCHLD"   },
#endif
#ifdef SIGCONT
		{ SIGCONT,   "SIGCONT"   },
#endif
#ifdef SIGSTOP
		{ SIGSTOP,   "SIGSTOP"   },
#endif
#ifdef SIGTSTP
		{ SIGTSTP,   "SIGTSTP"   },
#endif
#ifdef SIGTTIN
		{ SIGTTIN,   "SIGTTIN"   },
#endif
#ifdef SIGTTOU
		{ SIGTTOU,   "SIGTTOU"   },
#endif
#ifdef SIGBUS
		{ SIGBUS,    "SIGBUS"    },
#endif
#ifdef SIGPOLL
		{ SIGPOLL,   "SIGPOLL"   },
#endif
#ifdef SIGPROF
		{ SIGPROF,   "SIGPROF"   },
#endif
#ifdef SIGSYS
		{ SIGSYS,    "SIGSYS"    },
#endif
#ifdef SIGTRAP
		{ SIGTRAP,   "SIGTRAP"   },
#endif
#ifdef SIGURG
		{ SIGURG,    "SIGURG"    },
#endif
#ifdef SIGVTALRM
		{ SIGVTALRM, "SIGVTALRM" },
#endif
#ifdef SIGXCPU
		{ SIGXCPU,   "SIGXCPU"   },
#endif
#ifdef SIGXFSZ
		{ SIGXFSZ,   "SIGXFSZ"   },
#endif
#ifdef SIGIOT
		{ SIGIOT,    "SIGIOT"    },
#endif
#ifdef SIGSTKFLT
		{ SIGSTKFLT, "SIGSTKFLT" },
#endif
#ifdef SIGIO
		{ SIGIO,     "SIGIO"     },
#endif
#ifdef SIGCLD
		{ SIGCLD,    "SIGCLD"    },
#endif
#ifdef SIGPWR
		{ SIGPWR,    "SIGPWR"    },
#endif
#ifdef SIGWINCH
		{ SIGWINCH,  "SIGWINCH"  },
#endif
#ifdef SIGUNUSED
		{ SIGUNUSED, "SIGUNUSED" },
#endif
		{ 0,         NULL }
	};

	for (size_t i=0; i < sizeof(signal_list)/sizeof(signal_list[0]); i++)
	{
		if ((signal_list[i].sig == sig) && (signal_list[i].sig_name != NULL))
		{
			return signal_list[i].sig_name;
		}
	}

	return "unknown";
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * flip bytes in buffer
 * \param[in,out] pbuffer buffer bytes
 * \param[in] size size buffer
 */
void libcore::flip(void *pbuffer, size_t size)
{
	if (size < 2) return;

	uint8_t *p1 = (uint8_t *)pbuffer;
	uint8_t *p2 = (uint8_t *)pbuffer + size - 1;

	for (size_t i=0; i < (size / 2); i++)
	{
		uint8_t x = *p1;
		*p1 = *p2;
		*p2 = x;
		p1++;
		p2--;
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// remove file extension
bool libcore::remove_file_ext(std::string& filename)
{
	size_t pos = filename.rfind('.');

	if (pos != size_t(-1))
	{
		filename.resize(pos);
		return true;
	}


	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check ipv4 string like '127.0.0.1'
bool libcore::is_ipaddress(const char *str)
{
	std::string tmp = str;
	size_t point1 = tmp.find('.', 0);
	if (point1 == size_t(-1)) return false;
	size_t point2 = tmp.find('.', point1 + 1);
	if (point2 == size_t(-1)) return false;
	size_t point3 = tmp.find('.', point2 + 1);
	if (point3 == size_t(-1)) return false;


	std::string num1 = tmp.substr(0, point1);
	std::string num2 = tmp.substr(point1 + 1, point2 - point1 - 1);
	std::string num3 = tmp.substr(point2 + 1, point3 - point2 - 1);
	std::string num4 = tmp.substr(point3 + 1, tmp.size());


	uint64_t val1;
	uint64_t val2;
	uint64_t val3;
	uint64_t val4;

	if (dec2uint(val1, 0, num1.c_str(), num1.size()) == false) return false;
	if (dec2uint(val2, 0, num2.c_str(), num2.size()) == false) return false;
	if (dec2uint(val3, 0, num3.c_str(), num3.size()) == false) return false;
	if (dec2uint(val4, 0, num4.c_str(), num4.size()) == false) return false;

	std::string tmp2 = num1 + '.' + num2 + '.' + num3 + '.' + num4;

	if (tmp != tmp2) return false;

	if ((val1 > 255) || (val2 > 255) || (val3 > 255) || (val4 > 255)) return false;


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// set signal
bool libcore::set_signal(int signo, void (*sig_handler)(int))
{
	struct sigaction act, oldact;
	act.sa_handler = sig_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if (signo != SIGALRM)
	{
		act.sa_flags |= SA_RESTART;
	}

	if (sigaction(signo, &act, &oldact) == -1) return false;

	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// string to lower
void libcore::strtolower(const std::string &source, std::string &target)
{
	std::transform(source.begin(), source.end(), target.begin(), tolower);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check pointer and strlen
size_t libcore::strlen(const char *pstr)
{
	if (pstr == NULL) return 0;

	return ::strlen(pstr);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// find block
size_t libcore::find(const void *p, size_t size, const void *ppattern, size_t pattern_size)
{
	if ((p == NULL) || (ppattern == NULL)) return -1;

	if (pattern_size > size) return -1;

	const int8_t *p2 = (int8_t *)p;
	size_t find_size = size - pattern_size;
	for (size_t i = 0; i < find_size; i++)
	{
		if (::memcmp(p2, ppattern, pattern_size) == 0)
		{
			return i;
		}
		p2++;
	}

	return size_t(-1);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::bin2print(std::string &result, const void *psource, size_t source_size, bool ignore_nonprint)
{
	result.reserve(4096);
	uint8_t *p = (uint8_t *)psource;

	for (size_t i=0; i < source_size; i++)
	{
		uint8_t ch = *p;
		p++;


		if
		(
			(ch >= 0x20) &&
			(ch <  0x7F)
		)
		{
			result += (char)ch;
			continue;
		}

		if (ch == 0x0D)
		{
			result += "\\r";
			continue;
		}

		if (ch == 0x0A)
		{
			result += "\\n";
			continue;
		}

		if (ch == 0x09)
		{
			result += "\\t";
			continue;
		}

		if (ignore_nonprint == true)
		{
			result += ".";
			continue;
		}

		result += "\\x";

		char buf[3];
		sprintf(buf, "%02X", ch & 0xFF);

		result += std::string(buf, 2);
	}

	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::bin2print(std::string &result, const std::string &source, bool ignore_nonprint)
{
	return libcore::bin2print(result, source.c_str(), source.size(), ignore_nonprint);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
