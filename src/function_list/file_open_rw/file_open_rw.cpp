//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// file open read/write
int libcore::file_open_rw(const char *pfilename, bool flag_sync, bool flag_truncate, bool flag_excl)
{
// set open flags
	int open_flags = O_WRONLY | O_CREAT | O_LARGEFILE;
	if (flag_sync != false)
	{
		open_flags |= O_SYNC;
	}
	if (flag_truncate != false)
	{
		open_flags |= O_TRUNC;
	}
	if (flag_excl != false)
	{
		open_flags |= O_EXCL;
	}


// open file
	umask(0);
	return ::open(pfilename, open_flags, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
