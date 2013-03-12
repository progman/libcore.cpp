//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.0.1
// Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#ifndef BASE64_H_INCLUDE
#define BASE64_H_INCLUDE
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
namespace lib_cpp
{
// check const char* in set [0-9]
	bool is_uint(const char* str);

// convert const char* to unsigned int
	bool str2uint(const char* str, unsigned int& value, unsigned int default_value);

// pedantic read from descriptor
	size_t pedantic_read(int fd, void *data, size_t size);

// pedantic write to descriptor
	size_t pedantic_write(int fd, const void *data, size_t size);

// read data from exist file
	int file_get(const char *filename, off_t offset, void *pdata, size_t data_size);

// write data to exist file
	int file_set(const char *filename, off_t offset, const void *pdata, size_t data_size);

// convert raw byte to char
	const char* raw2hex(const uint8_t byte, bool flag_low = true);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#endif
