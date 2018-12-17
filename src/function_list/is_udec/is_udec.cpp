//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp [+]?[0-9]+
 * \param[in] pstr string
 * \param[in] size size string or -1
 * \param[in] flag_enable_positive_sign enable or disable positive sign
 * \return flag correct check
 */
bool libcore::is_udec(const char *pstr, size_t size, bool flag_enable_positive_sign)
{
	if (pstr == NULL) return false;
	if (size == 0) return false;


	if (size == size_t(-1))
	{
		if (flag_enable_positive_sign == true)
		{
			if (*pstr == '+')
			{
				pstr++;
			}
		}


		const char *pstr_start = pstr;
		for (;; pstr++)
		{
			char ch = *pstr;

			if (ch == 0)
			{
				break;
			}

			if
			(
				(ch < '0') ||
				(ch > '9')
			)
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
		if (flag_enable_positive_sign == true)
		{
			if (*pstr == '+')
			{
				pstr++;
				size--;
				if (size == 0) return false;
			}
		}


		const char *pstr_end = pstr + size;
		for (; pstr != pstr_end; pstr++)
		{
			char ch = *pstr;

			if
			(
				(ch < '0') ||
				(ch > '9')
			)
			{
				return false;
			}
		}
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp [+]?[0-9]+
 * \param[in] str string
 * \return flag correct check
 */
bool libcore::is_udec(const std::string &str)
{
	return libcore::is_udec(str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
