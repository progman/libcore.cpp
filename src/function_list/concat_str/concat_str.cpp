//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// return (concat str1 and str2) or NULL
char *libcore::concat_str(const char *pstr1, const char *pstr2)
{
	if ((pstr1 == NULL) || (pstr2 == NULL)) return NULL;

	size_t str1_size = strlen(pstr1);
	size_t str2_size = strlen(pstr2);

	char *pstr3 = (char *)malloc(str1_size + str2_size + 1);
	if (pstr3 == NULL)
	{
		return NULL;
	}

	memcpy(pstr3, pstr1, str1_size);
	memcpy(pstr3 + str1_size, pstr2, str2_size);
	pstr3[str1_size + str2_size] = 0;

	return pstr3;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
