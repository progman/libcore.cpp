//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// block read from handle
size_t libcore::blk_read(int handle, off64_t offset, void *pdata, size_t size)
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
		if (cur_size == 0) break;

		ssize_t rc = ::read(handle, p, cur_size);

		if (rc == 0)
		{
			return -1;
		}
		if (rc == -1)
		{
			if (errno == EAGAIN)
			{
				continue;
			}
			return -1;
		}

		p += rc;
		cur_size -= rc;
	}


	return size;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
