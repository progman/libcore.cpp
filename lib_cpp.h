//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.0.6
// Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#ifndef LIB_CPP_H_INCLUDE
#define LIB_CPP_H_INCLUDE
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <string>
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
namespace lib_cpp
{
// check const char * in set 0x[0-9a-fA-F]+
	bool is_hex(const char *pstr);

// check const std::string in set 0x[0-9a-fA-F]+
	bool is_hex(const std::string &str);

// check const char * in set [0-9]+
	bool is_udec(const char *pstr);

// check const std::string in set [0-9]+
	bool is_udec(const std::string &str);

// check const char * in set [-+]*[0-9]+
	bool is_sdec(const char *pstr);

// check const std::string in set [-+]*[0-9]+
	bool is_sdec(const std::string &str);

// check number in str less number in str_max
	bool is_numeric_string_overflow(const char *pstr_max, const char *pstr, const size_t size);

// check number in str less number in str_max
	bool is_numeric_string_overflow(const char *pstr_max, const std::string &str);

// convert hex string to uint64_t
	bool hex2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size);

// convert hex string to uint64_t
	bool hex2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr);

// convert dec string to uint64_t
	bool dec2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size);

// convert dec string to uint64_t
	bool dec2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr);

// convert dec string to int64_t
	bool dec2int64_t (int64_t  &value, int64_t  default_value, const char *pstr, size_t size);

// convert dec string to int64_t
	bool dec2int64_t (int64_t  &value, int64_t  default_value, const char *pstr);

// convert const char * to uint64_t
	bool str2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size);

// convert const char * to uint64_t
	bool str2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr);

// convert int to string
	std::string sint2str(int value);

// pedantic read from descriptor
	size_t pedantic_read(int fd, void *pdata, size_t size);

// pedantic write to descriptor
	size_t pedantic_write(int fd, const void *pdata, size_t size);

// read data from exist file
	int file_get(const char *pfilename, off_t offset, void *pdata, size_t data_size);

// write data to exist file
	int file_set(const char *pfilename, off_t offset, const void *pdata, size_t data_size);

// convert byte to hex string
	const char *bin2hex(const uint8_t byte, bool flag_up = false);

// convert sibmol to number, example: '0' -> 0, 'F' -> 15
	bool hex2bin(uint8_t source, uint8_t &target);

// convert string to bool
	bool str2bool(const char *str);

// convert string to bool
	bool str2bool(const std::string &str);

// return (concat str1 and str2) or NULL
	char *concat_str(const char *pstr1, const char *pstr2);

// get env var and convert to bool
	bool env2bool(const char *pname, bool value_default = false);

// signal name
	const char *get_signal_name(const int sig);

// flip bytes
	void flip(void *pbuffer, size_t size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#endif
