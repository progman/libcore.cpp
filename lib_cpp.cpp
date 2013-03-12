//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.0.1
// Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <errno.h>
#include "lib_cpp.h"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check const char* in set [0-9]
// TODO: add hex
bool lib_cpp::is_uint(const char* str)
{
	size_t i = 0;

	for(;; i++, str++)
	{
		char ch = *str;

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
// convert const char* to unsigned int
bool lib_cpp::str2uint(const char* str, unsigned int& value, unsigned int default_value)
{
	value = default_value;

	if (is_uint(str) == false)
	{
		return false;
	}

	value = atoll(str);

	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// pedantic read from descriptor
size_t lib_cpp::pedantic_read(int fd, void *data, size_t size)
{
	char *p = (char*)data;
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
size_t lib_cpp::pedantic_write(int fd, const void *data, size_t size)
{
	char *p = (char*)data;
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
int lib_cpp::file_get(const char *filename, off_t offset, void *pdata, size_t data_size)
{
	int rc;


// open file
	rc = open(filename, O_RDONLY);
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
int lib_cpp::file_set(const char *filename, off_t offset, const void *pdata, size_t data_size)
{
	int rc;


// open file
	rc = open(filename, O_WRONLY);
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
// convert raw byte to char
const char* lib_cpp::raw2hex(const uint8_t byte, bool flag_low)
{
	static const char* low[] =
	{
		"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "0a", "0b", "0c", "0d", "0e", "0f",
		"10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "1a", "1b", "1c", "1d", "1e", "1f",
		"20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "2a", "2b", "2c", "2d", "2e", "2f",
		"30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "3a", "3b", "3c", "3d", "3e", "3f",
		"40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "4a", "4b", "4c", "4d", "4e", "4f",
		"50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "5a", "5b", "5c", "5d", "5e", "5f",
		"60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "6a", "6b", "6c", "6d", "6e", "6f",
		"70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "7a", "7b", "7c", "7d", "7e", "7f",
		"80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "8a", "8b", "8c", "8d", "8e", "8f",
		"90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "9a", "9b", "9c", "9d", "9e", "9f",
		"a0", "a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8", "a9", "aa", "ab", "ac", "ad", "ae", "af",
		"b0", "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8", "b9", "ba", "bb", "bc", "bd", "be", "bf",
		"c0", "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8", "c9", "ca", "cb", "cc", "cd", "ce", "cf",
		"d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7", "d8", "d9", "da", "db", "dc", "dd", "de", "df",
		"e0", "e1", "e2", "e3", "e4", "e5", "e6", "e7", "e8", "e9", "ea", "eb", "ec", "ed", "ee", "ef",
		"f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7", "f8", "f9", "fa", "fb", "fc", "fd", "fe", "ff",
	};


	static const char* hi[] =
	{
		"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "0A", "0B", "0C", "0D", "0E", "0F",
		"10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "1A", "1B", "1C", "1D", "1E", "1F",
		"20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "2A", "2B", "2C", "2D", "2E", "2F",
		"30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "3A", "3B", "3C", "3D", "3E", "3F",
		"40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "4A", "4B", "4C", "4D", "4E", "4F",
		"50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "5A", "5B", "5C", "5D", "5E", "5F",
		"60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "6A", "6B", "6C", "6D", "6E", "6F",
		"70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "7A", "7B", "7C", "7D", "7E", "7F",
		"80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "8A", "8B", "8C", "8D", "8E", "8F",
		"90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "9A", "9B", "9C", "9D", "9E", "9F",
		"A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "AA", "AB", "AC", "AD", "AE", "AF",
		"B0", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "BA", "BB", "BC", "BD", "BE", "BF",
		"C0", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CA", "CB", "CC", "CD", "CE", "CF",
		"D0", "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DA", "DB", "DC", "DD", "DE", "DF",
		"E0", "E1", "E2", "E3", "E4", "E5", "E6", "E7", "E8", "E9", "EA", "EB", "EC", "ED", "EE", "EF",
		"F0", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "FA", "FB", "FC", "FD", "FE", "FF",
	};


	if (flag_low == true)
	{
		return low[byte];
	}
	return hi[byte];
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
