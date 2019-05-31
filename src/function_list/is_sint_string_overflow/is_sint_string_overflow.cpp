//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check pstr_min < number < pstr_max
 * \param[in] pstr_min string with min number
 * \param[in] pstr_max string with max number
 * \param[in] pstr string with test number
 * \param[in] size size string
 * \return flag correct check
 */
bool libcore::is_sint_string_overflow(const char *pstr_min, const char *pstr_max, const char *pstr, size_t size)
{
	if
	(
		(pstr_min == NULL) ||
		(pstr_max == NULL) ||
		(pstr     == NULL)
	)
	{
		return false;
	}


	if (*pstr_min == '+')
	{
		return false;
	}
	if (*pstr_max == '-')
	{
		return false;
	}


	bool flag_positive = true;
	if (*pstr == '-')
	{
		flag_positive = false;
	}


	if (*pstr_min == '-')
	{
		pstr_min++;
	}
	if (*pstr_max == '+')
	{
		pstr_max++;
	}
	if ((*pstr == '-') || (*pstr == '+'))
	{
		pstr++;
		size--;
	}


	size_t str_min_size = strlen(pstr_min);
	size_t str_max_size = strlen(pstr_max);


	if (str_min_size != str_max_size)
	{
		return false;
	}


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
	if (flag_positive == false)
	{
		for (size_t i=0; i < str_min_size; i++)
		{
			if (pstr_min[i] > pstr[i])
			{
				break;
			}

			if (pstr_min[i] < pstr[i])
			{
				return false;
			}
		}
	}
	else
	{
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
	}


	return true;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * check pstr_min < number < pstr_max
 * \param[in] pstr_min string with min number
 * \param[in] pstr_max string with max number
 * \param[in] str string with test number
 * \return flag correct check
 */
bool libcore::is_sint_string_overflow(const char *pstr_min, const char *pstr_max, const std::string &str)
{
	return libcore::is_sint_string_overflow(pstr_min, pstr_max, str.c_str(), str.size());
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
