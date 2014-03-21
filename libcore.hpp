//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.2.5
// Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#ifndef LIBCORE_HPP_INCLUDE
#define LIBCORE_HPP_INCLUDE
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <string>
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
namespace libcore
{
/**
 * convert uint to string
 * \param[out] result string result
 * \param[in] source uint source
 * \param[in] zero_count zero count
 * \return flag correct convertion
 */
	bool uint2str(std::string &result, uint64_t source, uint8_t zero_count = 0);


/**
 * convert sint to string
 * \param[out] result string result
 * \param[in] source int source
 * \param[in] zero_count zero count
 * \return flag correct convertion
 */
	bool sint2str(std::string &result, int64_t source, uint8_t zero_count = 0);


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

// convert dec string to sint
	bool dec2sint(int64_t  &result, int64_t  default_value, const char *pstr, size_t size);
	bool dec2sint(int64_t  &result, int64_t  default_value, const char *pstr);
	bool dec2sint(int64_t  &result, int64_t  default_value, const std::string &str);
	bool dec2sint(int64_t  &result, const char *pstr, size_t size);
	bool dec2sint(int64_t  &result, const char *pstr);
	bool dec2sint(int64_t  &result, const std::string &str);

// convert string to uint
	bool str2uint(uint64_t &result, uint64_t default_value, const char *pstr, size_t size);
	bool str2uint(uint64_t &result, uint64_t default_value, const char *pstr);
	bool str2uint(uint64_t &result, uint64_t default_value, const std::string &str);
	bool str2uint(uint64_t &result, const char *pstr, size_t size);
	bool str2uint(uint64_t &result, const char *pstr);
	bool str2uint(uint64_t &result, const std::string &str);

// convert string to bool
	bool str2bool(bool &result, bool default_value, const char *str);
	bool str2bool(bool &result, bool default_value, const std::string &str);
	bool str2bool(bool &result, const char *str);
	bool str2bool(bool &result, const std::string &str);

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

// find block
	size_t find(const void *p, size_t size, const void *ppattern, size_t pattern_size);

	bool bin2print(std::string &result, const void *psource, size_t source_size, bool ignore_nonprint = false);
	bool bin2print(std::string &result, const std::string &source,               bool ignore_nonprint = false);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#endif
