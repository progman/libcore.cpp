//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check ipv4 string like '127.0.0.1'
bool libcore::is_ipaddress(const char *str)
{
	std::string tmp = str;
	size_t point1 = tmp.find('.', 0);
	if (point1 == size_t(-1)) return false;
	size_t point2 = tmp.find('.', point1 + 1);
	if (point2 == size_t(-1)) return false;
	size_t point3 = tmp.find('.', point2 + 1);
	if (point3 == size_t(-1)) return false;


	std::string num1 = tmp.substr(0, point1);
	std::string num2 = tmp.substr(point1 + 1, point2 - point1 - 1);
	std::string num3 = tmp.substr(point2 + 1, point3 - point2 - 1);
	std::string num4 = tmp.substr(point3 + 1, tmp.size());


	uint64_t val1;
	uint64_t val2;
	uint64_t val3;
	uint64_t val4;

	if (dec2uint(val1, 0, num1.c_str(), num1.size()) == false) return false;
	if (dec2uint(val2, 0, num2.c_str(), num2.size()) == false) return false;
	if (dec2uint(val3, 0, num3.c_str(), num3.size()) == false) return false;
	if (dec2uint(val4, 0, num4.c_str(), num4.size()) == false) return false;

	std::string tmp2 = num1 + '.' + num2 + '.' + num3 + '.' + num4;

	if (tmp != tmp2) return false;

	if ((val1 > 255) || (val2 > 255) || (val3 > 255) || (val4 > 255)) return false;


	return true;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
