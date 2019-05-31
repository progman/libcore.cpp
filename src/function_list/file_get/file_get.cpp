//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// read data from exist file
int libcore::file_get(const char *pfilename, off64_t offset, void *pdata, size_t data_size)
{
	int rc;


// open file
	rc = libcore::file_open_ro(pfilename);
	if (rc == -1)
	{
		return -1;
	}
	int fd = rc;


// get file size
	size_t size = libcore::get_file_size(fd);
	if (size == size_t(-1))
	{
		rc = errno;
		::close(fd);
		errno = rc;
		return -1;
	}


// check offset
	if ((offset + data_size) > size)
	{
		errno = EINVAL;
		return -1;
	}


// read from file
	rc = libcore::blk_read(fd, offset, pdata, data_size);
	if (rc == -1)
	{
		rc = errno;
		::close(fd);
		errno = rc;
		return -1;
	}


// close file
	rc = libcore::file_close(fd, false);
	if (rc == -1)
	{
		return -1;
	}


	return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// read data from exist file
int libcore::file_get(const char *pfilename, off64_t offset, void **pdata, size_t *data_size)
{
	int rc;

	size_t size = get_file_size(pfilename);
	if (size == size_t(-1))
	{
		return -1;
	}

	*pdata = ::malloc(size - offset);
	if (*pdata == NULL)
	{
		return -1;
	}

	rc = libcore::file_get(pfilename, offset, *pdata, size - offset);
	if (rc == -1)
	{
		::free(*pdata);
		*pdata = NULL;
		return -1;
	}
	*data_size = size - offset;

	return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// read data from exist file
int libcore::file_get(const char *pfilename, off64_t offset, std::string &data)
{
	int rc;
	void *pdata;
	size_t data_size;

	rc = libcore::file_get(pfilename, offset, &pdata, &data_size);
	if (rc == -1)
	{
		return -1;
	}

	data = std::string((const char *)pdata, data_size);
	::free(pdata);

	return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
