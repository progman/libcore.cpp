//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.0.5
// Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <stdio.h>
#include <string.h>
#include "libcore.hpp"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int uint2str()
{
	bool rc;
	std::string value;

	rc = libcore::uint2str(value, +10);
	if ((rc == false) || (value != "10"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	rc = libcore::uint2str(value, +10, 0, true);
	if ((rc == false) || (value != "+10"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	rc = libcore::uint2str(value, 1917, 6);
	if ((rc == false) || (value != "001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	rc = libcore::uint2str(value, 1917, 6, true);
	if ((rc == false) || (value != "+001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	uint64_t x;

	x = 0;
	x = ~x;
	rc = libcore::uint2str(value, x);
	if ((rc == false) || (value != "18446744073709551615"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	x = 0;
	x = ~x;
	rc = libcore::uint2str(value, x, 0, true);
	if ((rc == false) || (value != "+18446744073709551615"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int sint2str()
{
	bool rc;
	std::string value;

	rc = libcore::sint2str(value, -10);
	if ((rc == false) || (value != "-10"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	rc = libcore::sint2str(value, +10);
	if ((rc == false) || (value != "10"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	rc = libcore::sint2str(value, +10, 0, true);
	if ((rc == false) || (value != "+10"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	rc = libcore::sint2str(value, 1917, 6);
	if ((rc == false) || (value != "001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	rc = libcore::sint2str(value, 1917, 6, true);
	if ((rc == false) || (value != "+001917"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	uint64_t x;

	x = 0;
	x = ~x;
	rc = libcore::sint2str(value, x);
	if ((rc == false) || (value != "-1"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	x = 0;
	x = ~x;
	rc = libcore::sint2str(value, x, 0, true);
	if ((rc == false) || (value != "-1"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		printf("ERROR[%s()]: value:\"%s\"\n", __FUNCTION__, value.c_str());
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int str2bool()
{
	bool value;
	bool rc;


	rc = libcore::str2bool(value, false, "1");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	rc = libcore::str2bool(value, false, "t");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	rc = libcore::str2bool(value, false, "T");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	rc = libcore::str2bool(value, false, "on");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	rc = libcore::str2bool(value, false, "On");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	rc = libcore::str2bool(value, false, "ON");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	rc = libcore::str2bool(value, false, "true");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "007");
		return -1;
	}

	rc = libcore::str2bool(value, false, "True");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "008");
		return -1;
	}

	rc = libcore::str2bool(value, false, "TRUE");
	if ((rc == false) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "009");
		return -1;
	}


	rc = libcore::str2bool(value, false, "0");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "010");
		return -1;
	}

	rc = libcore::str2bool(value, false, "f");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "011");
		return -1;
	}

	rc = libcore::str2bool(value, false, "F");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "012");
		return -1;
	}

	rc = libcore::str2bool(value, false, "off");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "013");
		return -1;
	}

	rc = libcore::str2bool(value, false, "Off");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "014");
		return -1;
	}

	rc = libcore::str2bool(value, false, "OFF");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "015");
		return -1;
	}

	rc = libcore::str2bool(value, false, "false");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "016");
		return -1;
	}

	rc = libcore::str2bool(value, false, "False");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "017");
		return -1;
	}

	rc = libcore::str2bool(value, false, "FALSE");
	if ((rc == false) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "018");
		return -1;
	}


	rc = libcore::str2bool(value, false, "");
	if ((rc == true) || (value == true))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "019");
		return -1;
	}

	rc = libcore::str2bool(value, true, "");
	if ((rc == true) || (value == false))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "020");
		return -1;
	}


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int get_signal_name()
{
#ifdef SIGINT
	if (strcmp(get_signal_name(SIGINT), "SIGINT") != 0)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}
#endif
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int flip()
{
	char t1[]={ 3 };
	char t2[]={ 3, 2 };
	char t3[]={ 3, 2, 1 };
	char t4[]={ 3, 2, 1, 0 };

	libcore::flip(t1, sizeof(t1));
	if (t1[0] != 3)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	libcore::flip(t2, sizeof(t2));
	if
	(
		(t2[0] != 2) ||
		(t2[1] != 3)
	)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	libcore::flip(t3, sizeof(t3));
	if
	(
		(t3[0] != 1) ||
		(t3[1] != 2) ||
		(t3[2] != 3)
	)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	libcore::flip(t4, sizeof(t4));
	if
	(
		(t4[0] != 0) ||
		(t4[1] != 1) ||
		(t4[2] != 2) ||
		(t4[3] != 3)
	)
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int remove_file_ext()
{
	std::string in, out;

	in = "";
	out = in;
	if ((libcore::remove_file_ext(out) == true) || (out != in))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	in = "wow";
	out = in;
	if ((libcore::remove_file_ext(out) == true) || (out != in))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	in = "wow.zip";
	out = in;
	if ((libcore::remove_file_ext(out) == false) || (out != "wow"))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int find()
{
	const char *pdata = "hello world!";

	const char *ppattern = "world";

	size_t index = libcore::find(pdata, strlen(pdata), ppattern, strlen(ppattern));
	if (index == size_t(-1))
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "001");
		return -1;
	}

	if (pdata[index] != 'w')
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "002");
		return -1;
	}

	index++;
	if (pdata[index] != 'o')
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "003");
		return -1;
	}

	index++;
	if (pdata[index] != 'r')
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "004");
		return -1;
	}

	index++;
	if (pdata[index] != 'l')
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "005");
		return -1;
	}

	index++;
	if (pdata[index] != 'd')
	{
		printf("ERROR[%s()]: step%s\n", __FUNCTION__, "006");
		return -1;
	}

	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int main(int argc, char *argv[])
{
	int rc;


	if (argc != 1)
	{
		if
		(
			(strcmp(argv[1], "-h")     == 0) ||
			(strcmp(argv[1], "-help")  == 0) ||
			(strcmp(argv[1], "--help") == 0)
		)
		{
			printf("example: %s\n", argv[0]);
			return 0;
		}
	}


	rc = uint2str();
	if (rc == -1) return 1;

	rc = sint2str();
	if (rc == -1) return 1;

	rc = str2bool();
	if (rc == -1) return 1;

	rc = get_signal_name();
	if (rc == -1) return 1;

	rc = flip();
	if (rc == -1) return 1;

	rc = remove_file_ext();
	if (rc == -1) return 1;

	rc = find();
	if (rc == -1) return 1;


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
