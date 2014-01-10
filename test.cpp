//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// 0.0.4
// Alexey Potehin <gnuplanet@gmail.com>, http://www.gnuplanet.ru/doc/cv
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <stdio.h>
#include <string.h>
#include "lib_cpp.hpp"
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
int str2bool()
{
	if (lib_cpp::str2bool("true") == false)
	{
		printf("ERROR[str2bool()]: step001\n");
		return -1;
	}

	if (lib_cpp::str2bool("True") == false)
	{
		printf("ERROR[str2bool()]: step002\n");
		return -1;
	}

	if (lib_cpp::str2bool("TRUE") == false)
	{
		printf("ERROR[str2bool()]: step003\n");
		return -1;
	}

	if (lib_cpp::str2bool("false") == true)
	{
		printf("ERROR[str2bool()]: step004\n");
		return -1;
	}

	if (lib_cpp::str2bool("False") == true)
	{
		printf("ERROR[str2bool()]: step005\n");
		return -1;
	}

	if (lib_cpp::str2bool("FALSE") == true)
	{
		printf("ERROR[str2bool()]: step006\n");
		return -1;
	}

	if (lib_cpp::str2bool("t") == false)
	{
		printf("ERROR[str2bool()]: step007\n");
		return -1;
	}

	if (lib_cpp::str2bool("on") == false)
	{
		printf("ERROR[str2bool()]: step008\n");
		return -1;
	}

	if (lib_cpp::str2bool("1") == false)
	{
		printf("ERROR[str2bool()]: step009\n");
		return -1;
	}

	if (lib_cpp::str2bool(std::string("true")) == false)
	{
		printf("ERROR[str2bool()]: step010\n");
		return -1;
	}

	if (lib_cpp::str2bool(std::string("True")) == false)
	{
		printf("ERROR[str2bool()]: step011\n");
		return -1;
	}

	if (lib_cpp::str2bool(std::string("TRUE")) == false)
	{
		printf("ERROR[str2bool()]: step012\n");
		return -1;
	}

	if (lib_cpp::str2bool(std::string("false")) == true)
	{
		printf("ERROR[str2bool()]: step013\n");
		return -1;
	}

	if (lib_cpp::str2bool(std::string("False")) == true)
	{
		printf("ERROR[str2bool()]: step014\n");
		return -1;
	}

	if (lib_cpp::str2bool(std::string("FALSE")) == true)
	{
		printf("ERROR[str2bool()]: step015\n");
		return -1;
	}

	if (lib_cpp::str2bool(std::string("t")) == false)
	{
		printf("ERROR[str2bool()]: step016\n");
		return -1;
	}

	if (lib_cpp::str2bool(std::string("on")) == false)
	{
		printf("ERROR[str2bool()]: step017\n");
		return -1;
	}

	if (lib_cpp::str2bool(std::string("1")) == false)
	{
		printf("ERROR[str2bool()]: step018\n");
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
		printf("ERROR[get_signal_name()]: step001\n");
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

	lib_cpp::flip(t1, sizeof(t1));
	if (t1[0] != 3)
	{
		printf("ERROR[flip()]: step001\n");
		return -1;
	}

	lib_cpp::flip(t2, sizeof(t2));
	if
	(
		(t2[0] != 2) ||
		(t2[1] != 3)
	)
	{
		printf("ERROR[flip()]: step002\n");
		return -1;
	}

	lib_cpp::flip(t3, sizeof(t3));
	if
	(
		(t3[0] != 1) ||
		(t3[1] != 2) ||
		(t3[2] != 3)
	)
	{
		printf("ERROR[flip()]: step003\n");
		return -1;
	}

	lib_cpp::flip(t4, sizeof(t4));
	if
	(
		(t4[0] != 0) ||
		(t4[1] != 1) ||
		(t4[2] != 2) ||
		(t4[3] != 3)
	)
	{
		printf("ERROR[flip()]: step004\n");
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
	if ((lib_cpp::remove_file_ext(out) == true) || (out != in))
	{
		printf("ERROR[flip()]: step001\n");
		return -1;
	}

	in = "wow";
	out = in;
	if ((lib_cpp::remove_file_ext(out) == true) || (out != in))
	{
		printf("ERROR[flip()]: step002\n");
		return -1;
	}

	in = "wow.zip";
	out = in;
	if ((lib_cpp::remove_file_ext(out) == false) || (out != "wow"))
	{
		printf("ERROR[flip()]: step003\n");
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


	rc = str2bool();
	if (rc == -1) return 1;

	rc = get_signal_name();
	if (rc == -1) return 1;

	rc = flip();
	if (rc == -1) return 1;

	rc = remove_file_ext();
	if (rc == -1) return 1;


	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
