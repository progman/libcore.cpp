//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, uint64_t default_value, const char *pstr, size_t size)
{
	if ((pstr == NULL) || (size == 0))
	{
		result = default_value;
		return false;
	}


	if (size > 1)
	{
		if ((pstr[0] == '0') && (pstr[1] == 'x'))
		{
			pstr += 2;
			size -= 2;
		}
	}


	if (size == 0)
	{
		result = default_value;
		return false;
	}


	char ch1, ch2;
	uint8_t r1, r2, out;


	size_t byte_count = size / 2;
	if (byte_count > sizeof(uint64_t))
	{
		result = default_value;
		return false;
	}

	bool flag_parity = true;
	if ((byte_count * 2) != size)
	{
		flag_parity = false;
		byte_count++;
	}


	result = 0;
	for (;;)
	{
		if (flag_parity == false)
		{
			ch1 = '0';
			flag_parity = true;
		}
		else
		{
			ch1 = *pstr;
			pstr++;
		}
		ch2 = *pstr;
		pstr++;


		if (libcore::hex2bin((uint8_t)ch1, r1) == false)
		{
			result = default_value;
			return false;
		}
		if (libcore::hex2bin((uint8_t)ch2, r2) == false)
		{
			result = default_value;
			return false;
		}
		out = (uint8_t)((r1 << 4) + r2);


		result <<= 8;
		result |= out;
		byte_count--;


		if (byte_count == 0) break;
	}


	return true;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, uint64_t default_value, const char *pstr)
{
	return libcore::hex2uint(result, default_value, pstr, libcore::strlen(pstr));
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] str source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, uint64_t default_value, const std::string &str)
{
	return libcore::hex2uint(result, default_value, str.c_str(), str.size());
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, const char *pstr, size_t size)
{
	return libcore::hex2uint(result, 0, pstr, size);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] pstr source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, const char *pstr)
{
	return libcore::hex2uint(result, 0, pstr, libcore::strlen(pstr));
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] str source string
 * \return flag correct convert
 */
bool libcore::hex2uint(uint64_t &result, const std::string &str)
{
	return libcore::hex2uint(result, 0, str.c_str(), str.size());
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
