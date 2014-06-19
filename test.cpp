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
 * \param[in] zero_count zero count
 * \param[in] flag_plus enable '+' before string
 * \return flag correct convertion
 */
//	bool uint2str(std::string &result, uint64_t source, uint8_t zero_count = 0, bool flag_plus = false);
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

	rc = libcore::uint2str(value, +1, 0, true);
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

	rc = libcore::uint2str(value, 1917, 6, true);
	if ((rc == false) || (value != "+001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::uint2str(value, 1917, 200, true);
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
	rc = libcore::uint2str(value, x, 0, true);
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
 * \param[in] zero_count zero count
 * \param[in] flag_plus enable '+' before string
 * \return flag correct convertion
 */
//	bool sint2str(std::string &result, int64_t source, uint8_t zero_count = 0, bool flag_plus = false);
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

	rc = libcore::sint2str(value, +1, 0, true);
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

	rc = libcore::sint2str(value, 1917, 6, true);
	if ((rc == false) || (value != "+001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::sint2str(value, 1917, 200, true);
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
	rc = libcore::sint2str(value, x, 0, true);
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
 * check whether a string is equivalent to regexp [+]?[0-9]+
 * \param[in] pstr string
 * \return flag correct check
 */
//	bool is_udec(const char *pstr);
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
 * \return flag correct check
 */
//	bool is_sdec(const char *pstr);
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
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}
//printf("%lu\n", result);

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
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


/*
// check const string in set 0x[0-9a-fA-F]+
	bool is_hex(const char *pstr);
	bool is_hex(const std::string &str);
*/


	rc = is_udec();
	if (rc == -1) return 1;

	rc = is_sdec();
	if (rc == -1) return 1;

/*
// check number in string less number in str_max
	bool is_numeric_string_overflow(const char *pstr_max, const char *pstr, size_t size);
	bool is_numeric_string_overflow(const char *pstr_max, const std::string &str);

// convert hex string to uint
	bool hex2uint(uint64_t &result, uint64_t default_value, const char *pstr, size_t size);
	bool hex2uint(uint64_t &result, uint64_t default_value, const char *pstr);
	bool hex2uint(uint64_t &result, uint64_t default_value, const std::string &str);
	bool hex2uint(uint64_t &result, const char *pstr, size_t size);
	bool hex2uint(uint64_t &result, const char *pstr);
	bool hex2uint(uint64_t &result, const std::string &str);

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

/*
	bool bin2print(std::string &result, const void *psource, size_t source_size, bool ignore_nonprint = false);
	bool bin2print(std::string &result, const std::string &source,               bool ignore_nonprint = false);
*/


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
