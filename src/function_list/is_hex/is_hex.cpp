//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp 0x[0-9a-fA-F]+
 * \param[in] pstr string
 * \param[in] size size string
 * \param[in] flag_prefix must prefix '0x'
 * \return flag correct check
 */
bool libcore::is_hex(const char *pstr, size_t size, bool flag_prefix)
{
	if (pstr == NULL) return false;
	if (size == 0) return false;


	if (size == size_t(-1))
	{
		if (*pstr == 0) return false;
		if ((pstr[1] == 'x') && (pstr[0] == '0'))
		{
			pstr += 2;
		}
		else
		{
			if (flag_prefix == true)
			{
				return false;
			}
		}


		const char *pstr_start = pstr;
		for (;; pstr++)
		{
			uint8_t ch = *pstr;

			if (ch == 0)
			{
				break;
			}

			if (::hex2bin_table[ch] == 0xff)
			{
				return false;
			}
		}
		if (pstr == pstr_start)
		{
			return false;
		}
	}
	else
	{
		if ((size > 1) && (pstr[1] == 'x') && (pstr[0] == '0'))
		{
			pstr += 2;
			size -= 2;
			if (size == 0) return false;
		}
		else
		{
			if (flag_prefix == true)
			{
				return false;
			}
		}


		for (; size != 0; pstr++, size--)
		{
			uint8_t ch = *pstr;

			if (::hex2bin_table[ch] == 0xff)
			{
				return false;
			}
		}
	}


	return true;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp 0x[0-9a-fA-F]+
 * \param[in] str string
 * \param[in] flag_prefix must prefix '0x'
 * \return flag correct check
 */
bool libcore::is_hex(const std::string &str, bool flag_prefix)
{
	return libcore::is_hex(str.c_str(), str.size(), flag_prefix);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
