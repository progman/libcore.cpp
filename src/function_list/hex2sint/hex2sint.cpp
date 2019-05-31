//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, int64_t default_value, const char *pstr, size_t size)
{
	bool rc;
	uint64_t tmp;

	rc = libcore::hex2uint(tmp, (uint64_t)default_value, pstr, size);
	if (rc == false)
	{
		result = tmp;
		return rc;
	}

	result = libcore::sign_expand(tmp);
	return rc;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, int64_t default_value, const char *pstr)
{
	return libcore::hex2sint(result, default_value, pstr, libcore::strlen(pstr));
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] str source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, int64_t default_value, const std::string &str)
{
	return libcore::hex2sint(result, default_value, str.c_str(), str.size());
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, const char *pstr, size_t size)
{
	return libcore::hex2sint(result, 0, pstr, size);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] pstr source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, const char *pstr)
{
	return libcore::hex2sint(result, 0, pstr, libcore::strlen(pstr));
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] str source string
 * \return flag correct convert
 */
bool libcore::hex2sint(int64_t &result, const std::string &str)
{
	return libcore::hex2sint(result, 0, str.c_str(), str.size());
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
