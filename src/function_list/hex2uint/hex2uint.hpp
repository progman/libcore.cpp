/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, uint64_t default_value, const char *pstr, size_t size);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] pstr source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, uint64_t default_value, const char *pstr);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] default_value default value
 * \param[in] str source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, uint64_t default_value, const std::string &str);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] pstr source string
 * \param[in] size size source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, const char *pstr, size_t size);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] pstr source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, const char *pstr);


/**
 * convert hex string to uint
 * \param[in] result return value
 * \param[in] str source string
 * \return flag correct convert
 */
	bool hex2uint(uint64_t &result, const std::string &str);
