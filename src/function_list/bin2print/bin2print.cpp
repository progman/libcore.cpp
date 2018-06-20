//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::bin2print(std::string &result, const void *psource, size_t source_size, bool ignore_nonprint)
{
	result.reserve(4096);
	uint8_t *p = (uint8_t *)psource;

	for (size_t i=0; i < source_size; i++)
	{
		uint8_t ch = *p;
		p++;


		if
		(
			(ch >= 0x20) &&
			(ch <  0x7F)
		)
		{
			result += (char)ch;
			continue;
		}

		if (ch == 0x0D)
		{
			result += "\\r";
			continue;
		}

		if (ch == 0x0A)
		{
			result += "\\n";
			continue;
		}

		if (ch == 0x09)
		{
			result += "\\t";
			continue;
		}

		if (ignore_nonprint == true)
		{
			result += ".";
			continue;
		}

		result += "\\x";

		char buf[3];
		sprintf(buf, "%02X", ch & 0xFF);

		result.append(buf);
	}

	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::bin2print(std::string &result, const std::string &source, bool ignore_nonprint)
{
	return libcore::bin2print(result, source.c_str(), source.size(), ignore_nonprint);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
