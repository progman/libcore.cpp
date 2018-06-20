//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// write data to exist file
int libcore::file_set(const char *pfilename, off64_t offset, const void *pdata, size_t data_size, bool flag_sync, bool flag_truncate, bool flag_excl)
{
	int rc;


// open file
	rc = libcore::file_open_rw(pfilename, false, flag_truncate, flag_excl);
	if (rc == -1)
	{
		return -1;
	}
	int fd = rc;


// write to file
	rc = libcore::blk_write(fd, offset, pdata, data_size, false);
	if (rc == -1)
	{
		rc = errno;
		::close(fd);
		errno = rc;
		return -1;
	}


// close file
	rc = libcore::file_close(fd, flag_sync);
	if (rc == -1)
	{
		return -1;
	}


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// write data to exist file
int libcore::file_set(const char *pfilename, off64_t offset, const std::string &data, bool flag_sync, bool flag_truncate, bool flag_excl)
{
	return libcore::file_set(pfilename, offset, data.c_str(), data.size(), flag_sync, flag_truncate, flag_excl);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
