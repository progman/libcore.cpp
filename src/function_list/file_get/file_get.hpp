// read data from exist file
	int file_get(const char *pfilename, off64_t offset, void *pdata, size_t data_size);
	int file_get(const char *pfilename, off64_t offset, void **pdata, size_t *data_size);
	int file_get(const char *pfilename, off64_t offset, std::string &data);
