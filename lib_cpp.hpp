//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.1.6
// Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#ifndef LIB_CPP_H_INCLUDE
#define LIB_CPP_H_INCLUDE
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <string>
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
namespace lib_cpp
{
// convert uint64_t to string
	void uint2str(uint64_t source, std::string &target);

// convert int64_t  to string
	void sint2str(int64_t  source, std::string &target);

// check const string in set 0x[0-9a-fA-F]+
	bool is_hex(const char *pstr);
	bool is_hex(const std::string &str);

// check const string in set [0-9]+
	bool is_udec(const char *pstr);
	bool is_udec(const std::string &str);

// check const string in set [-+]*[0-9]+
	bool is_sdec(const char *pstr);
	bool is_sdec(const std::string &str);

// check number in string less number in str_max
	bool is_numeric_string_overflow(const char *pstr_max, const char *pstr, const size_t size);
	bool is_numeric_string_overflow(const char *pstr_max, const std::string &str);

// convert hex string to uint64_t
	bool hex2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size);
	bool hex2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr);
	bool hex2uint64_t(uint64_t &value, uint64_t default_value, const std::string &str);
	bool hex2uint64_t(uint64_t &value, const char *pstr, size_t size);
	bool hex2uint64_t(uint64_t &value, const char *pstr);
	bool hex2uint64_t(uint64_t &value, const std::string &str);

// convert dec string to uint64_t
	bool dec2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size);
	bool dec2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr);
	bool dec2uint64_t(uint64_t &value, uint64_t default_value, const std::string &str);
	bool dec2uint64_t(uint64_t &value, const char *pstr, size_t size);
	bool dec2uint64_t(uint64_t &value, const char *pstr);
	bool dec2uint64_t(uint64_t &value, const std::string &str);

// convert dec string to int64_t
	bool dec2int64_t (int64_t  &value, int64_t  default_value, const char *pstr, size_t size);
	bool dec2int64_t (int64_t  &value, int64_t  default_value, const char *pstr);
	bool dec2int64_t (int64_t  &value, int64_t  default_value, const std::string &str);
	bool dec2int64_t (int64_t  &value, const char *pstr, size_t size);
	bool dec2int64_t (int64_t  &value, const char *pstr);
	bool dec2int64_t (int64_t  &value, const std::string &str);

// convert string to uint64_t
	bool str2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr, size_t size);
	bool str2uint64_t(uint64_t &value, uint64_t default_value, const char *pstr);
	bool str2uint64_t(uint64_t &value, uint64_t default_value, const std::string &str);
	bool str2uint64_t(uint64_t &value, const char *pstr, size_t size);
	bool str2uint64_t(uint64_t &value, const char *pstr);
	bool str2uint64_t(uint64_t &value, const std::string &str);

// convert string to bool
	bool str2bool(const char *str);
	bool str2bool(const std::string &str);

// convert byte to hex string
	const char *bin2hex(const uint8_t byte, bool flag_up = false);

// convert sibmol to number, example: '0' -> 0, 'F' -> 15
	bool hex2bin(uint8_t source, uint8_t &target);

// block read from handle
	size_t blk_read(int handle, off64_t offset, void *pdata, size_t size);

// block write to handle
	size_t blk_write(int handle, off64_t offset, const void *pdata, size_t size);

// block recv from handle
	size_t blk_recv(int handle, void *pdata, size_t size);

// block send to handle
	size_t blk_send(int handle, const void *pdata, size_t size);

// read data from exist file
	int file_get(const char *pfilename, off_t offset, void *pdata, size_t data_size);
	int file_get(const char *pfilename, void **pdata, size_t *data_size);
	int file_get(const char *pfilename, std::string &data);

// write data to exist file
	int file_set(const char *pfilename, off_t offset, const void *pdata, size_t data_size);
	int file_set(const char *pfilename, off_t offset, const std::string &data);
	int file_set(const char *pfilename, const std::string &data);

// return (concat str1 and str2) or NULL
	char *concat_str(const char *pstr1, const char *pstr2);

// get env var and convert to bool
	bool env2bool(const char *pname, bool value_default = false);

// signal name
	const char *get_signal_name(const int sig);

// flip bytes
	void flip(void *pbuffer, size_t size);

// remove file extension
	bool remove_file_ext(std::string& filename);

// check ipv4 string like '127.0.0.1'
	bool is_ipaddress(const char *str);

// set signal
	bool set_signal(int signo, void (*sig_handler)(int));

// string to lower
	void strtolower(const std::string &source, std::string &target);

// check pointer and strlen
	size_t strlen(const char *pstr);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#endif
