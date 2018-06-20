/**
 * check whether a string is equivalent to regexp 0x[0-9a-fA-F]+
 * \param[in] pstr string
 * \param[in] size size string
 * \param[in] flag_prefix must prefix '0x'
 * \return flag correct check
 */
	bool is_hex(const char *pstr, size_t size = size_t(-1), bool flag_prefix = true);


/**
 * check whether a string is equivalent to regexp 0x[0-9a-fA-F]+
 * \param[in] str string
 * \param[in] flag_prefix must prefix '0x'
 * \return flag correct check
 */
	bool is_hex(const std::string &str, bool flag_prefix = true);
