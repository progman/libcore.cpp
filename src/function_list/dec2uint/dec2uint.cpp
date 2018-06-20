//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, uint64_t default_value, const char *pstr, size_t size)
{
// check correct data input string
	if (libcore::is_udec(pstr, size) == false)
	{
		value = default_value;
		return false;
	}


// check overflow
	if (libcore::is_uint_string_overflow("18446744073709551615", pstr, size) == false)
	{
		value = default_value;
		return false;
	}


// convert it
	value = strtoull(pstr, NULL, 10); // atoll
	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, uint64_t default_value, const char *pstr)
{
	return libcore::dec2uint(value, default_value, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, uint64_t default_value, const std::string &str)
{
	return libcore::dec2uint(value, default_value, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, const char *pstr, size_t size)
{
	return libcore::dec2uint(value, 0, pstr, size);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, const char *pstr)
{
	return libcore::dec2uint(value, 0, pstr, libcore::strlen(pstr));
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// convert dec string to uint
bool libcore::dec2uint(uint64_t &value, const std::string &str)
{
	return libcore::dec2uint(value, 0, str.c_str(), str.size());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
