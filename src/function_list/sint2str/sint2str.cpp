//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/**
 * convert sint to string
 * \param[out] result string result
 * \param[in] source int source
 * \param[in] fill_count fill count
 * \param[in] fill_char char for fill
 * \param[in] flag_plus enable '+' before string
 * \return flag correct convertion
 */
bool libcore::sint2str(std::string &result, int64_t source, uint8_t fill_count, char fill_char, bool flag_plus)
{
	if (source >= 0)
	{
		return libcore::uint2str(result, source, fill_count, fill_char, flag_plus);
	}


	source = -source;


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


	*p = '-';
	p--;


	result = ++p;


	return true;
}
/*
bool libcore::sint2str(std::string &result, int64_t source, uint8_t zero_count)
{
	char buf[128], format[128];

	if (zero_count == 0)
	{
#if (INTPTR_MAX == INT32_MAX)
		sprintf(buf, "%lld", source);
#endif
#if (INTPTR_MAX == INT64_MAX)
		sprintf(buf, "%ld", source);
#endif
	}
	else
	{
#if (INTPTR_MAX == INT32_MAX)
		sprintf(format, "%%0%ulld", zero_count);
		sprintf(buf, format, source);
#endif
#if (INTPTR_MAX == INT64_MAX)
		sprintf(format, "%%0%uld", zero_count);
		sprintf(buf, format, source);
#endif
	}

	result = buf;

	return true;
}
*/
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
