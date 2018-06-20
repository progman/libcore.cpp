/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, int64_t default_value, const char *pstr, size_t size);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, int64_t default_value, const char *pstr);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] str source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, int64_t default_value, const std::string &str);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, const char *pstr, size_t size);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] pstr source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, const char *pstr);


/**
 * convert hex string to sint
 * \param[in] result return value
 * \param[in] str source string
 * \return flag correct convert
 */
	bool hex2sint(int64_t &result, const std::string &str);
