//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check 0 < number < pstr_max
 * \param[in] pstr_max string with max number
 * \param[in] pstr string with test number
 * \param[in] size size string
 * \return flag correct check
 */
bool libcore::is_uint_string_overflow(const char *pstr_max, const char *pstr, size_t size)
{
	if
	(
		(pstr_max == NULL) ||
		(pstr     == NULL)
	)
	{
		return false;
	}


	if (*pstr_max == '-')
	{
		return false;
	}
	if (*pstr == '-')
	{
		return false;
	}


	if (*pstr_max == '+')
	{
		pstr_max++;
	}
	if (*pstr == '+')
	{
		pstr++;
		size--;
	}


	size_t str_max_size = strlen(pstr_max);


// check size input string
	if (size > str_max_size)
	{
		return false;
	}
	if (size < str_max_size)
	{
		return true;
	}


// size == str_max_size
	for (size_t i=0; i < str_max_size; i++)
	{
		if (pstr_max[i] > pstr[i])
		{
			break;
		}

		if (pstr_max[i] < pstr[i])
		{
			return false;
		}
	}


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check 0 < number < pstr_max
 * \param[in] pstr_max string with max number
 * \param[in] str string with test number
 * \return flag correct check
 */
bool libcore::is_uint_string_overflow(const char *pstr_max, const std::string &str)
{
	return libcore::is_uint_string_overflow(pstr_max, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
