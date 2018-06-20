// write data to exist file
	int file_set(const char *pfilename, off64_t offset, const void *pdata, size_t data_size, bool flag_sync, bool flag_truncate, bool flag_excl);
	int file_set(const char *pfilename, off64_t offset, const std::string &data,             bool flag_sync, bool flag_truncate, bool flag_excl);
