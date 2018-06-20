/**
 * check 0 < number < pstr_max
 * \param[in] pstr_max string with max number
 * \param[in] pstr string with test number
 * \param[in] size size string
 * \return flag correct check
 */
	bool is_uint_string_overflow(const char *pstr_max, const char *pstr, size_t size);


/**
 * check 0 < number < pstr_max
 * \param[in] pstr_max string with max number
 * \param[in] str string with test number
 * \return flag correct check
 */
	bool is_uint_string_overflow(const char *pstr_max, const std::string &str);
