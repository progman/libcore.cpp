//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert uint to string
 * \param[out] result string result
 * \param[in] source uint source
 * \param[in] fill_count fill count
 * \param[in] fill_char char for fill
 * \param[in] flag_plus enable '+' before string
 * \return flag correct convertion
 */
bool libcore::uint2str(std::string &result, uint64_t source, uint8_t fill_count, char fill_char, bool flag_plus)
{
//0         1         2         3
//0123456789012345678901234567890123456789
//+000000000000000000000000001917
//18446744073709551615
//-9223372036854775806
//+9223372036854775807
	char s[32];
	char *p = s + (sizeof(s) - 1);


	*p = '\0';
	p--;


	for (;;)
	{
		*p = (source % 10) + '0';
		p--;
		source /= 10;
		if (source == 0) break;
	}


	if (fill_count != 0)
	{
		if (fill_count > (sizeof(s) - 2))
		{
			fill_count = (sizeof(s) - 2);
		}
		int max = fill_count - (sizeof(s) - (p - s)) + 2;
		for (int j=0; j < max; j++)
		{
			*p = fill_char;
			p--;
		}
	}


	if (flag_plus != false)
	{
		*p = '+';
		p--;
	}


	result = ++p;


	return true;
}
/*
bool libcore::uint2str(std::string &result, uint64_t source, uint8_t zero_count)
{
	char buf[128], format[128];

	if (zero_count == 0)
	{
#if (INTPTR_MAX == INT32_MAX)
		sprintf(buf, "%llu", source);
#endif
#if (INTPTR_MAX == INT64_MAX)
		sprintf(buf, "%lu", source);
#endif
	}
	else
	{
#if (INTPTR_MAX == INT32_MAX)
		sprintf(format, "%%0%ullu", zero_count);
		sprintf(buf, format, source);
#endif
#if (INTPTR_MAX == INT64_MAX)
		sprintf(format, "%%0%ulu", zero_count);
		sprintf(buf, format, source);
#endif
	}

	result = buf;

	return true;
}
*/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
