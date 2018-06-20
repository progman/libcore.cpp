//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check whether a string is equivalent to regexp [-+]?[0-9]+
 * \param[in] pstr string
 * \param[in] size size string
 * \return flag correct check
 */
bool libcore::is_sdec(const char *pstr, size_t size)
{
	if (pstr == NULL) return false;
	if (size == 0) return false;


	if (size == size_t(-1))
	{
		if ((*pstr == '-') || (*pstr == '+'))
		{
			pstr++;
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
		if ((*pstr == '-') || (*pstr == '+'))
		{
			pstr++;
			size--;
			if (size == 0) return false;
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
 * check whether a string is equivalent to regexp [-+]?[0-9]+
 * \param[in] str string
 * \return flag correct check
 */
bool libcore::is_sdec(const std::string &str)
{
	return libcore::is_sdec(str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
