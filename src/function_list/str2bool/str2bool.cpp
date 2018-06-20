//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::str2bool(bool &result, bool default_value, const char *pstr)
{
	if (pstr == NULL)
	{
		result = default_value;
		return false;
	}


	if (strcasecmp(pstr, "1")    == 0)
	{
		result = true;
		return true;
	}
	if (strcasecmp(pstr, "t")    == 0)
	{
		result = true;
		return true;
	}
	if (strcasecmp(pstr, "on")   == 0)
	{
		result = true;
		return true;
	}
	if (strcasecmp(pstr, "true") == 0)
	{
		result = true;
		return true;
	}


	if (strcasecmp(pstr, "0")    == 0)
	{
		result = false;
		return true;
	}
	if (strcasecmp(pstr, "f")    == 0)
	{
		result = false;
		return true;
	}
	if (strcasecmp(pstr, "off")   == 0)
	{
		result = false;
		return true;
	}
	if (strcasecmp(pstr, "false") == 0)
	{
		result = false;
		return true;
	}


	result = default_value;
	return false;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::str2bool(bool &result, bool default_value, const std::string &str)
{
	return libcore::str2bool(result, default_value, str.c_str());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::str2bool(bool &result, const char *pstr)
{
	return libcore::str2bool(result, false, pstr);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool libcore::str2bool(bool &result, const std::string &str)
{
	return libcore::str2bool(result, false, str.c_str());
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
