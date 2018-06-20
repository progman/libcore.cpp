/**
 * convert uint to string
 * \param[out] result string result
 * \param[in] source uint source
 * \param[in] fill_count fill count
 * \param[in] fill_char char for fill
 * \param[in] flag_plus enable '+' before string
 * \return flag correct convertion
 */
	bool uint2str(std::string &result, uint64_t source, uint8_t fill_count = 0, char fill_char = '0', bool flag_plus = false);
