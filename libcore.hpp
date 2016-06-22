//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.4.6
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
 * \param[in] fill_count fill count
 * \param[in] fill_char char for fill
 * \param[in] flag_plus enable '+' before string
 * \return flag correct convertion
 */
	bool uint2str(std::string &result, uint64_t source, uint8_t fill_count = 0, char fill_char = '0', bool flag_plus = false);


/**
 * convert sint to string
 * \param[out] result string result
 * \param[in] source int source
 * \param[in] fill_count fill count
 * \param[in] fill_char char for fill
 * \param[in] flag_plus enable '+' before string
 * \return flag correct convertion
 */
	bool sint2str(std::string &result, int64_t source, uint8_t fill_count = 0, char fill_char = '0', bool flag_plus = false);


/**
 * check whether a string is equivalent to regexp 0x[0-9a-fA-F]+
 * \param[in] pstr string
 * \param[in] size size string
 * \param[in] flag_prefix must prefix '0x'
 * \return flag correct check
 */
	bool is_hex(const char *pstr, size_t size = size_t(-1), bool flag_prefix = true);


/**
 * check whether a string is equivalent to regexp 0x[0-9a-fA-F]+
 * \param[in] str string
 * \param[in] flag_prefix must prefix '0x'
 * \return flag correct check
 */
	bool is_hex(const std::string &str, bool flag_prefix = true);


/**
 * check whether a string is equivalent to regexp [+]?[0-9]+
 * \param[in] pstr string
 * \param[in] size size string
 * \return flag correct check
 */
	bool is_udec(const char *pstr, size_t size = size_t(-1));


/**
 * check whether a string is equivalent to regexp [+]?[0-9]+
 * \param[in] str string
 * \return flag correct check
 */
	bool is_udec(const std::string &str);


/**
 * check whether a string is equivalent to regexp [-+]?[0-9]+
 * \param[in] pstr string
 * \param[in] size size string
 * \return flag correct check
 */
	bool is_sdec(const char *pstr, size_t size = size_t(-1));


/**
 * check whether a string is equivalent to regexp [-+]?[0-9]+
 * \param[in] str string
 * \return flag correct check
 */
	bool is_sdec(const std::string &str);


/**
 * check 0 < number < pstr_max
 * \param[in] pstr_max string with max number
 * \param[in] pstr string with test number
 * \param[in] size size string
 * \return flag correct check
 */
	bool is_uint_string_overflow(const char *pstr_max, const char *pstr, size_t size);


/**
 * check 0 < number < pstr_max
 * \param[in] pstr_max string with max number
 * \param[in] str string with test number
 * \return flag correct check
 */
	bool is_uint_string_overflow(const char *pstr_max, const std::string &str);


/**
 * check pstr_min < number < pstr_max
 * \param[in] pstr_min string with min number
 * \param[in] pstr_max string with max number
 * \param[in] pstr string with test number
 * \param[in] size size string
 * \return flag correct check
 */
	bool is_sint_string_overflow(const char *pstr_min, const char *pstr_max, const char *pstr, size_t size);


/**
 * check pstr_min < number < pstr_max
 * \param[in] pstr_min string with min number
 * \param[in] pstr_max string with max number
 * \param[in] str string with test number
 * \return flag correct check
 */
	bool is_sint_string_overflow(const char *pstr_min, const char *pstr_max, const std::string &str);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, uint64_t default_value, const char *pstr, size_t size);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, uint64_t default_value, const char *pstr);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] str source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, uint64_t default_value, const std::string &str);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, const char *pstr, size_t size);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] pstr source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, const char *pstr);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] str source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, const std::string &str);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, int64_t default_value, const char *pstr, size_t size);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, int64_t default_value, const char *pstr);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] str source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, int64_t default_value, const std::string &str);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, const char *pstr, size_t size);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] pstr source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, const char *pstr);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] str source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, const std::string &str);


/**
 * expand sign in value, example: 0xff -> -1, 0xffff -> -1, ...
 * \param[in] value unsign value
 * \return sign value
 */
	int64_t sign_expand(const uint64_t value);












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
	bool str2bool(bool &result, bool default_value, const char *pstr);
	bool str2bool(bool &result, bool default_value, const std::string &str);
	bool str2bool(bool &result, const char *pstr);
	bool str2bool(bool &result, const std::string &str);

// convert bool to string
	const char *bool2str(bool value);

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

// get file size
	off64_t get_file_size(int handle);

// get file size
	off64_t get_file_size(const char *pfilename);

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


/**
 * flip bytes in buffer
 * \param[in,out] pbuffer buffer bytes
 * \param[in] size size buffer
 */
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


	void rnd_init();
	uint64_t rnd(uint64_t min, uint64_t max);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#endif
