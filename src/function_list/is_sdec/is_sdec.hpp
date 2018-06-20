/**
 * check whether a string is equivalent to regexp [-+]?[0-9]+
 * \param[in] pstr string
 * \param[in] size size string
 * \return flag correct check
 */
	bool is_sdec(const char *pstr, size_t size = size_t(-1));


/**
 * check whether a string is equivalent to regexp [-+]?[0-9]+
 * \param[in] str string
 * \return flag correct check
 */
	bool is_sdec(const std::string &str);
