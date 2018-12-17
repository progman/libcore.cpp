/**
 * check whether a string is equivalent to regexp [+]?[0-9]+
 * \param[in] pstr string
 * \param[in] size size string or -1
 * \param[in] flag_enable_positive_sign enable or disable positive sign
 * \return flag correct check
 */
	bool is_udec(const char *pstr, size_t size = size_t(-1), bool flag_enable_positive_sign = true);


/**
 * check whether a string is equivalent to regexp [+]?[0-9]+
 * \param[in] str string
 * \return flag correct check
 */
	bool is_udec(const std::string &str);
