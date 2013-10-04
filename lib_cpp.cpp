//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.0.5
// Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <string>
#include <string.h>
#include <errno.h>
#include <algorithm>
#include "lib_cpp.h"
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
// check const char * in set 0x[0-9a-fA-F]+
bool lib_cpp::is_hex(const char *pstr)
{
	if (pstr == NULL) return false;

	if (*pstr != '0') return false;
	pstr++;

	if (*pstr != 'x') return false;
	pstr++;


	size_t i = 0;

	for (;; i++, pstr++)
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

	if (i == 0)
	{
		return false;
	}

	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check const std::string in set 0x[0-9a-fA-F]+
bool lib_cpp::is_hex(const std::string &str)
{
	return lib_cpp::is_hex(str.c_str());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check const char * in set [0-9]+
bool lib_cpp::is_udec(const char *pstr)
{
	if (pstr == NULL) return false;

	size_t i = 0;

	for (;; i++, pstr++)
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

	if (i == 0)
	{
		return false;
	}

	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check const std::string in set [0-9]+
bool lib_cpp::is_udec(const std::string &str)
{
	return lib_cpp::is_udec(str.c_str());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check const char * in set [-+]*[0-9]+
bool lib_cpp::is_sdec(const char *pstr)
{
	if (pstr == NULL) return false;

	if
	(
		(*pstr != '-') &&
		(*pstr != '+')
	)
	{
		return false;
	}

	pstr++;


	return lib_cpp::is_udec(pstr);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check const std::string in set [-+]*[0-9]+
bool lib_cpp::is_sdec(const std::string &str)
{
	return lib_cpp::is_sdec(str.c_str());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check number in str less number in str_max
bool lib_cpp::is_numeric_string_overflow(const char *pstr_max, const char *pstr, const size_t size)
{
	if
	(
		(pstr_max == NULL) ||
		(pstr     == NULL)
	)
	{
		return false;
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

		if ((i + 1) == str_max_size)
		{
			break;
		}
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check number in str less number in str_max
bool lib_cpp::is_numeric_string_overflow(const char *pstr_max, const std::string &str)
{
	return lib_cpp::is_numeric_string_overflow(pstr_max, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert hex string to uint64_t
bool lib_cpp::hex2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size)
{
	if (pstr == NULL)
	{
		value = default_value;
		return false;
	}


	if (*pstr != '0')
	{
		value = default_value;
		return false;
	}
	pstr++;
	size--;

	if (*pstr != 'x')
	{
		value = default_value;
		return false;
	}
	pstr++;
	size--;


	char ch1, ch2;
	uint8_t r1, r2, out;


	size_t byte_count = size / 2;
	if (byte_count > sizeof(uint64_t))
	{
		value = default_value;
		return false;
	}

	bool flag_parity = true;
	if ((byte_count * 2) != size)
	{
		flag_parity = false;
	}


	value = 0;
	for (;;)
	{
		if (flag_parity == false)
		{
			ch1 = 0;
			flag_parity = true;
		}
		else
		{
			ch1 = *pstr;
			pstr++;
		}
		ch2 = *pstr;
		pstr++;


		if (lib_cpp::hex2bin((uint8_t)ch1, r1) == false)
		{
			value = default_value;
			return false;
		}
		if (lib_cpp::hex2bin((uint8_t)ch2, r2) == false)
		{
			value = default_value;
			return false;
		}
		out = (uint8_t)((r1 << 4) + r2);


		value <<= 8;
		value  |= out;
		byte_count--;


		if (byte_count == 0) break;
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert hex string to uint64_t
bool lib_cpp::hex2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr)
{
	if (pstr == NULL)
	{
		value = default_value;
		return false;
	}

	return lib_cpp::hex2uint64_t(value, default_value, pstr, strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint64_t
bool lib_cpp::dec2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size)
{
// check correct data input string
	if (lib_cpp::is_udec(pstr) == false)
	{
		value = default_value;
		return false;
	}


// check overflow
	if (lib_cpp::is_numeric_string_overflow("18446744073709551615", pstr, size) == false)
	{
		value = default_value;
		return false;
	}


// convert it
	value = strtoull(pstr, NULL, 10); // atoll
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint64_t
bool lib_cpp::dec2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr)
{
	if (pstr == NULL)
	{
		value = default_value;
		return false;
	}

	return lib_cpp::dec2uint64_t(value, default_value, pstr, strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to int64_t
bool lib_cpp::dec2int64_t(int64_t &value, int64_t default_value, const char *pstr, size_t size)
{
// check correct data input string
	if (lib_cpp::is_sdec(pstr) == false)
	{
		value = default_value;
		return false;
	}


// check overflow
	if (*pstr == '-')
	{
		if (lib_cpp::is_numeric_string_overflow("-9223372036854775806", pstr, size) == false)
		{
			value = default_value;
			return false;
		}
	}
	else
	{
		if (lib_cpp::is_numeric_string_overflow("+9223372036854775807", pstr, size) == false)
		{
			value = default_value;
			return false;
		}
	}


// convert it
	value = strtoll(pstr, NULL, 10); // atoll
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to int64_t
bool lib_cpp::dec2int64_t(int64_t &value, int64_t default_value, const char *pstr)
{
	if (pstr == NULL)
	{
		value = default_value;
		return false;
	}

	return lib_cpp::dec2int64_t(value, default_value, pstr, strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert const char * to uint64_t
bool lib_cpp::str2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size)
{
	if (pstr == NULL)
	{
		value = default_value;
		return false;
	}


	if (lib_cpp::hex2uint64_t(value, default_value, pstr, size) == true)
	{
		return true;
	}


	if (lib_cpp::dec2int64_t((int64_t &)value, (int64_t &)default_value, pstr, size) == true)
	{
		return true;
	}


	return lib_cpp::dec2uint64_t(value, default_value, pstr, size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert const char * to uint64_t
bool lib_cpp::str2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr)
{
	value = default_value;
	if (pstr == NULL) return false;

	return lib_cpp::str2uint64_t(value, default_value, pstr, strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert int to string
std::string lib_cpp::sint2str(int value)
{
	char buf[128];
	sprintf(buf, "%d", value);

	return std::string(buf);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// pedantic read from descriptor
size_t lib_cpp::pedantic_read(int fd, void *pdata, size_t size)
{
	char *p = (char *)pdata;
	size_t cur_size = size;

	for (;;)
	{
		size_t rc = ::read(fd, p, cur_size);
		if (rc == 0) return -1;
		if (rc == size_t(-1)) return -1;

		p += rc;
		cur_size -= rc;

		if (cur_size == 0) break;
	}

	return size;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// pedantic write to descriptor
size_t lib_cpp::pedantic_write(int fd, const void *pdata, size_t size)
{
	char *p = (char *)pdata;
	size_t cur_size = size;

	for (;;)
	{
		size_t rc = ::write(fd, p, cur_size);
		if (rc == size_t(-1)) return -1;

		p += rc;
		cur_size -= rc;

		if (cur_size == 0) break;
	}

	return size;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// read data from exist file
int lib_cpp::file_get(const char *pfilename, off_t offset, void *pdata, size_t data_size)
{
	int rc;


// open file
	rc = open(pfilename, O_RDONLY);
	if (rc == -1)
	{
		printf("ERROR[open()]: %s\n", strerror(errno));
		return -1;
	}
	int fd = rc;


// get file size
	struct stat my_stat;
	rc = fstat(fd, &my_stat);
	if (rc == -1)
	{
		close(fd);
		printf("ERROR[fstat()]: %s\n", strerror(errno));
		return -1;
	}
	size_t size = my_stat.st_size;


// check offset
	if ((offset + data_size) > size)
	{
		printf("ERROR[file_get()]: offset too big\n");
		return -1;
	}


// seek in file
	rc = lseek(fd, offset, SEEK_SET);
	if (rc == -1)
	{
		close(fd);
		printf("ERROR[lseek()]: %s\n", strerror(errno));
		return -1;
	}


// read from file
	rc = pedantic_read(fd, pdata, data_size);
	if (rc == -1)
	{
		close(fd);
		printf("ERROR[read()]: %s\n", strerror(errno));
		return -1;
	}


// close file
	rc = close(fd);
	if (rc == -1)
	{
		printf("ERROR[close()]: %s\n", strerror(errno));
		return -1;
	}


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// write data to exist file
int lib_cpp::file_set(const char *pfilename, off_t offset, const void *pdata, size_t data_size)
{
	int rc;


// open file
	rc = open(pfilename, O_WRONLY);
	if (rc == -1)
	{
		printf("ERROR[open()]: %s\n", strerror(errno));
		return -1;
	}
	int fd = rc;


// get file size
	struct stat my_stat;
	rc = fstat(fd, &my_stat);
	if (rc == -1)
	{
		close(fd);
		printf("ERROR[fstat()]: %s\n", strerror(errno));
		return -1;
	}
	size_t size = my_stat.st_size;


// check offset
	if ((offset + data_size) > size)
	{
		printf("ERROR[file_get()]: offset too big\n");
		return -1;
	}


// seek in file
	rc = lseek(fd, offset, SEEK_SET);
	if (rc == -1)
	{
		close(fd);
		printf("ERROR[lseek()]: %s\n", strerror(errno));
		return -1;
	}


// write to file
	rc = pedantic_write(fd, pdata, data_size);
	if (rc == -1)
	{
		close(fd);
		printf("ERROR[write()]: %s\n", strerror(errno));
		return -1;
	}


// fsync file
	rc = fdatasync(fd);
	if (rc == -1)
	{
		close(fd);
		printf("ERROR[fdatasync()]: %s\n", strerror(errno));
		return -1;
	}


// close file
	rc = close(fd);
	if (rc == -1)
	{
		printf("ERROR[close()]: %s\n", strerror(errno));
		return -1;
	}


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert byte to hex string
const char *lib_cpp::bin2hex(const uint8_t byte, bool flag_up)
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
bool lib_cpp::hex2bin(uint8_t source, uint8_t &target)
{
	target = ::hex2bin_table[source];

	return (target == 0xff) ? false : true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert string to bool
bool lib_cpp::str2bool(const std::string &str)
{
	std::string tmp = str;
	std::transform(str.begin(), str.end(), tmp.begin(), tolower);

	if
	(
		(tmp == "true") ||
		(tmp == "t")    ||
		(tmp == "on")   ||
		(tmp == "1")
	)
	{
		return true;
	}

	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// return (concat str1 and str2) or NULL
char *lib_cpp::concat_str(const char *pstr1, const char *pstr2)
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
bool lib_cpp::env2bool(const char *pname, bool value_default)
{
	char *p = getenv(pname);
	if (p == NULL)
	{
		return value_default;
	}

	return lib_cpp::str2bool(p);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// signal name
const char *lib_cpp::get_signal_name(const int sig)
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
// flip bytes
void lib_cpp::flip(void *pbuffer, size_t size)
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
