//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void libcore::bin2print2(std::string &result, const void *psource, size_t source_size)
{
	uint8_t* p;


	result.append("[");
	p = (uint8_t *)psource;
	for (size_t i=0; i < source_size; i++)
	{
		uint8_t ch = *p;
		p++;


		if (i != 0)
		{
			result.append(" ");
		}


		char tmp[3];
		sprintf(tmp, "%02x", ch);
		result.append(tmp);
	}
	result.append("]");


	result.append(" ");


	result.append("[");
	p = (uint8_t *)psource;
	for (size_t i=0; i < source_size; i++)
	{
		uint8_t ch = *p;
		p++;

		if (is_ascii_hide_char(ch) == false)
		{
			result.append(1, char(ch));
		}
		else
		{
			result.append(".");
		}
	}
	result.append("]");
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
void libcore::bin2print2(std::string &result, const std::string &source)
{
	libcore::bin2print2(result, source.c_str(), source.size());
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
