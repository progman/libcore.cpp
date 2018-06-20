//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// block write to handle
size_t libcore::blk_write(int handle, off64_t offset, const void *pdata, size_t size, bool flag_sync)
{
	if (offset != off64_t(-1))
	{
		int rc = ::lseek64(handle, offset, SEEK_SET);
		if (rc == -1) return -1;
	}


	uint8_t *p = (uint8_t *)pdata;
	size_t cur_size = size;

	for (;;)
	{
		size_t rc = ::write(handle, p, cur_size);
		if (rc == size_t(-1)) return -1;

		p += rc;
		cur_size -= rc;

		if (cur_size == 0) break;
	}


// fsync file
	if (flag_sync != false)
	{
		int rc = ::fdatasync(handle);
		if (rc == -1)
		{
			return -1;
		}
	}


	return size;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
