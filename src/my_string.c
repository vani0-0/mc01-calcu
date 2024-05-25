#include "../include/my_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern char *strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *dest = malloc(len);
	if (dest == NULL)
		return NULL;
	strcpy(dest, str);
	return dest;
}

extern char *itoa(const int num)
{
	int len = snprintf(NULL, 0, "%d", num);
	char *str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return NULL;
	snprintf(str, len + 1, "%d", num);
	return str;
}
