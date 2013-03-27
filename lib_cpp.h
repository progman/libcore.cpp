//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.0.2
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
	bool is_hex(const char *str);

// check const std::string in set 0x[0-9a-fA-F]+
	bool is_hex(const std::string &str);

// check const char * in set [0-9]+
	bool is_udec(const char *str);

// check const std::string in set [0-9]+
	bool is_udec(const std::string &str);

// check const char * in set [-+]*[0-9]+
	bool is_sdec(const char *str);

// check const std::string in set [-+]*[0-9]+
	bool is_sdec(const std::string &str);

// convert hex string to uint64_t
	bool hex2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size);

// convert hex string to uint64_t
	bool hex2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr);

// convert dec string to uint64_t
	bool dec2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size);

// convert dec string to uint64_t
	bool dec2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr);

// convert const char * to uint64_t
	bool str2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size);

// convert const char * to uint64_t
	bool str2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr);

// convert int to string
	std::string sint2str(int value);

// pedantic read from descriptor
	size_t pedantic_read(int fd, void *data, size_t size);

// pedantic write to descriptor
	size_t pedantic_write(int fd, const void *data, size_t size);

// read data from exist file
	int file_get(const char *filename, off_t offset, void *pdata, size_t data_size);

// write data to exist file
	int file_set(const char *filename, off_t offset, const void *pdata, size_t data_size);

// convert byte to hex string
	const char *bin2hex(const uint8_t byte, bool flag_up = false);

// convert sibmol to number, example: '0' -> 0, 'F' -> 15
	bool hex2bin(uint8_t source, uint8_t &target);

// convert string to bool
	bool str2bool(const std::string &str);

// return (concat str1 and str2) or NULL
	char *concat_str(const char *str1, const char *str2);

// get env var and convert to bool
	bool env2bool(const char *name, bool value_default = false);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#endif
