//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, int64_t default_value, const char *pstr, size_t size)
{
// check correct data input string
	if (libcore::is_sdec(pstr, size) == false)
	{
		value = default_value;
		return false;
	}


// check overflow
	if (libcore::is_sint_string_overflow("-9223372036854775806", "+9223372036854775807", pstr, size) == false)
	{
		value = default_value;
		return false;
	}

/*
	if (*pstr == '-')
	{
		if (libcore::is_numeric_string_overflow("-9223372036854775806", pstr, size) == false)
		{
			value = default_value;
			return false;
		}
	}
	else
	{
		if (libcore::is_numeric_string_overflow("+9223372036854775807", pstr, size) == false)
		{
			value = default_value;
			return false;
		}
	}
*/

// convert it
	value = strtoll(pstr, NULL, 10); // atoll
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, int64_t default_value, const char *pstr)
{
	return libcore::dec2sint(value, default_value, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, int64_t  default_value, const std::string &str)
{
	return libcore::dec2sint(value, default_value, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, const char *pstr, size_t size)
{
	return libcore::dec2sint(value, 0, pstr, size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, const char *pstr)
{
	return libcore::dec2sint(value, 0, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to sint
bool libcore::dec2sint(int64_t &value, const std::string &str)
{
	return libcore::dec2sint(value, 0, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
