//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// block send to handle
size_t libcore::blk_send(int handle, const void *pdata, size_t size)
{
	uint8_t *p_cur = (uint8_t *)pdata;
	size_t count = size;


	for (;;)
	{
		ssize_t size_cur = ::send(handle, p_cur, count, MSG_NOSIGNAL);
		if (size_cur == -1) return -1;

		count -= size_cur;
		p_cur += size_cur;

		if (count == 0) break;
	}


	return size;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
