//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.0.5
// Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <stdio.h>
#include <string.h>
#include "libcore.hpp"
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
//	bool uint2str(std::string &result, uint64_t source, uint8_t fill_count = 0, char fill_char = '0', bool flag_plus = false);
int uint2str()
{
	bool rc;
	std::string value;

	rc = libcore::uint2str(value, -1);
	if ((rc == false) || (value != "18446744073709551615"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::uint2str(value, +1);
	if ((rc == false) || (value != "1"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::uint2str(value, +1, 0, '0', true);
	if ((rc == false) || (value != "+1"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::uint2str(value, 1917, 6);
	if ((rc == false) || (value != "001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::uint2str(value, 1917, 6, '0', true);
	if ((rc == false) || (value != "+001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::uint2str(value, 1917, 200, '0', true);
	if ((rc == false) || (value != "+000000000000000000000000001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	uint64_t x;

	x = 0;
	x = ~x;
	rc = libcore::uint2str(value, x);
	if ((rc == false) || (value != "18446744073709551615"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	x = 0;
	x = ~x;
	rc = libcore::uint2str(value, x, 0, '0', true);
	if ((rc == false) || (value != "+18446744073709551615"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	return 0;
}
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
//	bool sint2str(std::string &result, int64_t source, uint8_t fill_count = 0, char fill_char = '0', bool flag_plus = false);
int sint2str()
{
	bool rc;
	std::string value;

	rc = libcore::sint2str(value, -1);
	if ((rc == false) || (value != "-1"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::sint2str(value, +1);
	if ((rc == false) || (value != "1"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::sint2str(value, +1, 0, '0', true);
	if ((rc == false) || (value != "+1"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::sint2str(value, 1917, 6);
	if ((rc == false) || (value != "001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::sint2str(value, 1917, 6, '0', true);
	if ((rc == false) || (value != "+001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::sint2str(value, 1917, 200, '0', true);
	if ((rc == false) || (value != "+000000000000000000000000001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}


	uint64_t x;

	x = 0;
	x = ~x;
	rc = libcore::sint2str(value, x);
	if ((rc == false) || (value != "-1"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	x = 0;
	x = ~x;
	rc = libcore::sint2str(value, x, 0, '0', true);
	if ((rc == false) || (value != "-1"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp 0x[0-9a-fA-F]+
 * \param[in] pstr string
 * \param[in] size size string
 * \param[in] flag_prefix must prefix '0x'
 * \return flag correct check
 */
//	bool is_hex(const char *pstr, size_t size = size_t(-1), bool flag_prefix = true);
//	bool is_hex(const std::string &str, bool flag_prefix = true);
int is_hex()
{
	bool rc;

	rc = libcore::is_hex(NULL);
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	rc = libcore::is_hex("");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	rc = libcore::is_hex("wow");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	rc = libcore::is_hex("0xwow");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	rc = libcore::is_hex("0x");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	rc = libcore::is_hex("0xff");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	rc = libcore::is_hex("0xfff");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		return -1;
	}

	rc = libcore::is_hex("0xfff", size_t(-1), true);
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		return -1;
	}

	rc = libcore::is_hex("0xfff", size_t(-1), false);
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		return -1;
	}

	rc = libcore::is_hex("fff", size_t(-1), true);
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		return -1;
	}

	rc = libcore::is_hex("fff", size_t(-1), false);
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "009");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp [+]?[0-9]+
 * \param[in] pstr string
 * \param[in] size size string
 * \return flag correct check
 */
//	bool is_udec(const char *pstr, size_t size = size_t(-1));
//	bool is_udec(const std::string &str);
int is_udec()
{
	bool rc;

	rc = libcore::is_udec(NULL);
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	rc = libcore::is_udec("");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	rc = libcore::is_udec("wow");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	rc = libcore::is_udec("-1");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	rc = libcore::is_udec("+1");
	if (rc == false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	rc = libcore::is_udec("1");
	if (rc == false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp [-+]?[0-9]+
 * \param[in] pstr string
 * \param[in] size size string
 * \return flag correct check
 */
//	bool is_sdec(const char *pstr, size_t size = size_t(-1));
//	bool is_sdec(const std::string &str);
int is_sdec()
{
	bool rc;

	rc = libcore::is_sdec(NULL);
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	rc = libcore::is_sdec("");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	rc = libcore::is_sdec("wow");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	rc = libcore::is_sdec("-1");
	if (rc == false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	rc = libcore::is_sdec("+1");
	if (rc == false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	rc = libcore::is_sdec("1");
	if (rc == false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check 0 < number < pstr_max
 * \param[in] pstr_max string with max number
 * \param[in] pstr string with test number
 * \param[in] size size string
 * \return flag correct check
 */
//	bool is_uint_string_overflow(const char *pstr_max, const char *pstr, size_t size);
//	bool is_uint_string_overflow(const char *pstr_max, const std::string &str);
int is_uint_string_overflow()
{
	bool rc;

	rc = libcore::is_uint_string_overflow(NULL, NULL, 10);
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	rc = libcore::is_uint_string_overflow("0", "0");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	rc = libcore::is_uint_string_overflow("0", "-0");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	rc = libcore::is_uint_string_overflow("-0", "0");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	rc = libcore::is_uint_string_overflow("0", "10");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	rc = libcore::is_uint_string_overflow("18446744073709551615", "18446744073709551615");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	rc = libcore::is_uint_string_overflow("18446744073709551615", "+18446744073709551615");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		return -1;
	}

	rc = libcore::is_uint_string_overflow("+18446744073709551615", "18446744073709551615");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		return -1;
	}

	rc = libcore::is_uint_string_overflow("+18446744073709551615", "+18446744073709551615");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "009");
		return -1;
	}

	rc = libcore::is_uint_string_overflow("18446744073709551615", "18446744073709551616");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "010");
		return -1;
	}

	return 0;
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
//	bool is_sint_string_overflow(const char *pstr_min, const char *pstr_max, const char *pstr, size_t size);
//	bool is_sint_string_overflow(const char *pstr_min, const char *pstr_max, const std::string &str);
int is_sint_string_overflow()
{
	bool rc;

	rc = libcore::is_sint_string_overflow(NULL, NULL, NULL, 10);
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	rc = libcore::is_sint_string_overflow("-0", "+0", "0");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	rc = libcore::is_sint_string_overflow("-0", "+0", "10");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	rc = libcore::is_sint_string_overflow("-9223372036854775806", "+9223372036854775807", "0");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	rc = libcore::is_sint_string_overflow("-9223372036854775806", "+9223372036854775807", "-9223372036854775807");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	rc = libcore::is_sint_string_overflow("-9223372036854775806", "+9223372036854775807", "-9223372036854775806");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	rc = libcore::is_sint_string_overflow("-9223372036854775806", "+9223372036854775807", "+9223372036854775807");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		return -1;
	}

	rc = libcore::is_sint_string_overflow("-9223372036854775806", "+9223372036854775807", "9223372036854775807");
	if (rc != true)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		return -1;
	}

	rc = libcore::is_sint_string_overflow("-9223372036854775806", "+9223372036854775807", "9223372036854775808");
	if (rc != false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "009");
		return -1;
	}

	return 0;
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
//	bool hex2uint(uint64_t &result, uint64_t default_value, const char *pstr, size_t size);
//	bool hex2uint(uint64_t &result, uint64_t default_value, const char *pstr);
//	bool hex2uint(uint64_t &result, uint64_t default_value, const std::string &str);
//	bool hex2uint(uint64_t &result, const char *pstr, size_t size);
//	bool hex2uint(uint64_t &result, const char *pstr);
//	bool hex2uint(uint64_t &result, const std::string &str);
int hex2uint()
{
	bool rc;
	uint64_t result;

	rc = libcore::hex2uint(result, 777, NULL, 10);
	if ((rc != false) || (result != 777))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		printf("ERROR[%s()]: result:\"%u\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2uint(result, 777, "");
	if ((rc != false) || (result != 777))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		printf("ERROR[%s()]: result:\"%u\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2uint(result, 777, "0");
	if ((rc != false) || (result != 777))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		printf("ERROR[%s()]: result:\"%u\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2uint(result, 777, "0x");
	if ((rc != false) || (result != 777))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		printf("ERROR[%s()]: result:\"%u\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2uint(result, 777, "0xf");
	if ((rc != true) || (result != 0xf))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		printf("ERROR[%s()]: result:\"%u\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2uint(result, 777, "0xff");
	if ((rc != true) || (result != 0xff))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		printf("ERROR[%s()]: result:\"%u\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2uint(result, 777, "0xfff");
	if ((rc != true) || (result != 0xfff))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		printf("ERROR[%s()]: result:\"%u\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2uint(result, 777, "0xffff");
	if ((rc != true) || (result != 0xffff))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		printf("ERROR[%s()]: result:\"%u\"\n", __FUNCTION__, int(result));
		return -1;
	}

	return 0;
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
//	bool hex2sint(int64_t &result, int64_t default_value, const char *pstr, size_t size);
//	bool hex2sint(int64_t &result, int64_t default_value, const char *pstr);
//	bool hex2sint(int64_t &result, int64_t default_value, const std::string &str);
//	bool hex2sint(int64_t &result, const char *pstr, size_t size);
//	bool hex2sint(int64_t &result, const char *pstr);
//	bool hex2sint(int64_t &result, const std::string &str);
int hex2sint()
{
	bool rc;
	int64_t result;

	rc = libcore::hex2sint(result, 777, NULL, 10);
	if ((rc != false) || (result != 777))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2sint(result, 777, "");
	if ((rc != false) || (result != 777))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2sint(result, 777, "0");
	if ((rc != false) || (result != 777))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2sint(result, 777, "0x");
	if ((rc != false) || (result != 777))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2sint(result, 777, "0xf");
	if ((rc != true) || (result != 15))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2sint(result, 777, "0xff");
	if ((rc != true) || (result != -1))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2sint(result, 777, "0xfff");
	if ((rc != true) || (result != 4095))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(result));
		return -1;
	}

	rc = libcore::hex2sint(result, 777, "0xffff");
	if ((rc != true) || (result != -1))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(result));
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * expand sign in value, example: 0xff -> -1, 0xffff -> -1, ...
 * \param[in] value unsign value
 * \return sign value
 */
//	int64_t sign_expand(const uint64_t value);
int sign_expand()
{
	int64_t rc;

	rc = libcore::sign_expand(0x7f);
	if (rc != INT8_MAX) // 127
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(rc));
		return -1;
	}

	rc = libcore::sign_expand(0x80);
	if (rc != INT8_MIN) // -128
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(rc));
		return -1;
	}

	rc = libcore::sign_expand(0x7fff);
	if (rc != INT16_MAX) // 32767
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(rc));
		return -1;
	}

	rc = libcore::sign_expand(0x8000);
	if (rc != INT16_MIN) // -32768
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(rc));
		return -1;
	}

	rc = libcore::sign_expand(0x7fffffff);
	if (rc != INT32_MAX) // 2147483647
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(rc));
		return -1;
	}

	rc = libcore::sign_expand(0x80000000);
	if (rc != INT32_MIN) // -2147483648
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(rc));
		return -1;
	}

	rc = libcore::sign_expand((uint64_t(1) << 63) - 1); // 0x7fffffffffffffff
	if (rc != INT64_MAX) // -9223372036854775807
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(rc));
		return -1;
	}

	rc = libcore::sign_expand(uint64_t(1) << 63); // 0x8000000000000000
	if (rc != INT64_MIN) // 9223372036854775808
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		printf("ERROR[%s()]: result:\"%d\"\n", __FUNCTION__, int(rc));
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int dec2sint()
{
	bool rc;

	int64_t result;
	std::string value = "+1";
	rc = libcore::dec2sint(result, value);
	if (rc == false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int str2uint()
{
	bool rc;

	uint64_t result;
	std::string value = "-1";
	rc = libcore::str2uint(result, value);
	if (rc == false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}
	if (result != uint64_t(-1))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	const char *p1 = "777 ";
	const char *p2 = p1 + 3;
	std::string x(p1, p2 - p1);

	rc = libcore::str2uint(result, x);
	if ((rc == false) || (result != 777))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	rc = libcore::str2uint(result, p1, p2 - p1);
	if ((rc == false) || (result != 777))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int str2bool()
{
	bool value;
	bool rc;


	rc = libcore::str2bool(value, false, "1");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	rc = libcore::str2bool(value, false, "t");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	rc = libcore::str2bool(value, false, "T");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	rc = libcore::str2bool(value, false, "on");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	rc = libcore::str2bool(value, false, "On");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	rc = libcore::str2bool(value, false, "ON");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	rc = libcore::str2bool(value, false, "true");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		return -1;
	}

	rc = libcore::str2bool(value, false, "True");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		return -1;
	}

	rc = libcore::str2bool(value, false, "TRUE");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "009");
		return -1;
	}


	rc = libcore::str2bool(value, false, "0");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "010");
		return -1;
	}

	rc = libcore::str2bool(value, false, "f");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "011");
		return -1;
	}

	rc = libcore::str2bool(value, false, "F");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "012");
		return -1;
	}

	rc = libcore::str2bool(value, false, "off");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "013");
		return -1;
	}

	rc = libcore::str2bool(value, false, "Off");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "014");
		return -1;
	}

	rc = libcore::str2bool(value, false, "OFF");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "015");
		return -1;
	}

	rc = libcore::str2bool(value, false, "false");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "016");
		return -1;
	}

	rc = libcore::str2bool(value, false, "False");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "017");
		return -1;
	}

	rc = libcore::str2bool(value, false, "FALSE");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "018");
		return -1;
	}


	rc = libcore::str2bool(value, false, "");
	if ((rc == true) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "019");
		return -1;
	}

	rc = libcore::str2bool(value, true, "");
	if ((rc == true) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "020");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int get_signal_name()
{
#ifdef SIGINT
	if (strcmp(get_signal_name(SIGINT), "SIGINT") != 0)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}
#endif
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * flip bytes in buffer
 * \param[in,out] pbuffer buffer bytes
 * \param[in] size size buffer
 */
//	void flip(void *pbuffer, size_t size);
int flip()
{
	char t1[]={ 3 };
	char t2[]={ 3, 2 };
	char t3[]={ 3, 2, 1 };
	char t4[]={ 3, 2, 1, 0 };

	libcore::flip(t1, sizeof(t1));
	if (t1[0] != 3)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	libcore::flip(t2, sizeof(t2));
	if
	(
		(t2[0] != 2) ||
		(t2[1] != 3)
	)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	libcore::flip(t3, sizeof(t3));
	if
	(
		(t3[0] != 1) ||
		(t3[1] != 2) ||
		(t3[2] != 3)
	)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	libcore::flip(t4, sizeof(t4));
	if
	(
		(t4[0] != 0) ||
		(t4[1] != 1) ||
		(t4[2] != 2) ||
		(t4[3] != 3)
	)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int remove_file_ext()
{
	std::string in, out;

	in = "";
	out = in;
	if ((libcore::remove_file_ext(out) == true) || (out != in))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	in = "wow";
	out = in;
	if ((libcore::remove_file_ext(out) == true) || (out != in))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	in = "wow.zip";
	out = in;
	if ((libcore::remove_file_ext(out) == false) || (out != "wow"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int find()
{
	const char *pdata = "hello world!";

	const char *ppattern = "world";

	size_t index = libcore::find(pdata, strlen(pdata), ppattern, strlen(ppattern));
	if (index == size_t(-1))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	if (pdata[index] != 'w')
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	index++;
	if (pdata[index] != 'o')
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	index++;
	if (pdata[index] != 'r')
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	index++;
	if (pdata[index] != 'l')
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	index++;
	if (pdata[index] != 'd')
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//	bool bin2print(std::string &result, const void *psource, size_t source_size, bool ignore_nonprint = false);
//	bool bin2print(std::string &result, const std::string &source,               bool ignore_nonprint = false);
int bin2print()
{
	std::string source;
	std::string target;


	source = "hello world\n";

	char addon[2];
	addon[0] = 1;
	addon[1] = 0;

	source.append(addon);


	target.clear();
	if (libcore::bin2print(target, source, false) == false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	if (target != "hello world\\n\\x01")
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}


	target.clear();
	if (libcore::bin2print(target, source, true) == false)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	if (target != "hello world\\n.")
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int main(int argc, char *argv[])
{
	int rc;


	if (argc != 1)
	{
		if
		(
			(strcmp(argv[1], "-h")     == 0) ||
			(strcmp(argv[1], "-help")  == 0) ||
			(strcmp(argv[1], "--help") == 0)
		)
		{
			printf("example: %s\n", argv[0]);
			return 0;
		}
	}


	rc = uint2str();
	if (rc == -1) return 1;

	rc = sint2str();
	if (rc == -1) return 1;

	rc = is_hex();
	if (rc == -1) return 1;

	rc = is_udec();
	if (rc == -1) return 1;

	rc = is_sdec();
	if (rc == -1) return 1;

	rc = is_uint_string_overflow();
	if (rc == -1) return 1;

	rc = is_sint_string_overflow();
	if (rc == -1) return 1;

	rc = hex2uint();
	if (rc == -1) return 1;

	rc = hex2sint();
	if (rc == -1) return 1;

	rc = sign_expand();
	if (rc == -1) return 1;


/*
// convert dec string to uint
	bool dec2uint(uint64_t &result, uint64_t default_value, const char *pstr, size_t size);
	bool dec2uint(uint64_t &result, uint64_t default_value, const char *pstr);
	bool dec2uint(uint64_t &result, uint64_t default_value, const std::string &str);
	bool dec2uint(uint64_t &result, const char *pstr, size_t size);
	bool dec2uint(uint64_t &result, const char *pstr);
	bool dec2uint(uint64_t &result, const std::string &str);
*/

	rc = dec2sint();
	if (rc == -1) return 1;

	rc = str2uint();
	if (rc == -1) return 1;

	rc = str2bool();
	if (rc == -1) return 1;

/*
// convert byte to hex string
	const char *bin2hex(const uint8_t byte, bool flag_up = false);

// convert sibmol to number, example: '0' -> 0, 'F' -> 15
	bool hex2bin(uint8_t source, uint8_t &target);

// block read from handle
	size_t blk_read(int handle, off64_t offset, void *pdata, size_t size);

// block write to handle
	size_t blk_write(int handle, off64_t offset, const void *pdata, size_t size, bool flag_sync = false);

// block recv from handle
	size_t blk_recv(int handle, void *pdata, size_t size);

// block send to handle
	size_t blk_send(int handle, const void *pdata, size_t size);

// file open read only
	int file_open_ro(const char *pfilename);

// file open read/write
	int file_open_rw(const char *pfilename, bool flag_truncate = false, bool flag_excl = false);

// file close
	int file_close(int handle, bool flag_sync = false);

// read data from exist file
	int file_get(const char *pfilename, off_t offset, void *pdata, size_t data_size);
	int file_get(const char *pfilename, void **pdata, size_t *data_size);
	int file_get(const char *pfilename, std::string &data);

// write data to exist file
	int file_set(const char *pfilename, off_t offset, const void *pdata, size_t data_size, bool flag_sync = false, bool flag_truncate = false, bool flag_excl = false);
	int file_set(const char *pfilename, off_t offset, const std::string &data, bool flag_sync = false, bool flag_truncate = false, bool flag_excl = false);
	int file_set(const char *pfilename, const std::string &data, bool flag_sync = false, bool flag_truncate = false, bool flag_excl = false);

// return (concat str1 and str2) or NULL
	char *concat_str(const char *pstr1, const char *pstr2);

// get env var and convert to bool
	bool env2bool(bool &result, bool value_default, const char *pname);
*/

	rc = get_signal_name();
	if (rc == -1) return 1;

	rc = flip();
	if (rc == -1) return 1;

	rc = remove_file_ext();
	if (rc == -1) return 1;

/*
// check ipv4 string like '127.0.0.1'
	bool is_ipaddress(const char *str);

// set signal
	bool set_signal(int signo, void (*sig_handler)(int));

// string to lower
	void strtolower(const std::string &source, std::string &target);

// check pointer and strlen
	size_t strlen(const char *pstr);
*/

	rc = find();
	if (rc == -1) return 1;

	rc = bin2print();
	if (rc == -1) return 1;


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
