//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// find block
size_t libcore::find(const void *p, size_t size, const void *ppattern, size_t pattern_size)
{
	if ((p == NULL) || (ppattern == NULL)) return -1;

	if (pattern_size > size) return -1;

	const int8_t *p2 = (int8_t *)p;
	size_t find_size = size - pattern_size;
	for (size_t i = 0; i < find_size; i++)
	{
		if (::memcmp(p2, ppattern, pattern_size) == 0)
		{
			return i;
		}
		p2++;
	}

	return size_t(-1);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//