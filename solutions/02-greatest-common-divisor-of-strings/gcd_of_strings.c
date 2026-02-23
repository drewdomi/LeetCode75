#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int gdc(int divisor, int dividend)
{
	int remainder = divisor % dividend;

	if (!remainder)
		return dividend;

	return gdc(dividend, remainder);
}
char *gcdOfStrings(char *str1, char *str2)
{
	const int str1_len = strlen(str1);
	const int str2_len = strlen(str2);
	if (str1_len == 0 || str2_len == 0 || str2_len > 1000)
		return strdup("");

	const int total_size = str1_len + str2_len + 1;

	char *full_str1 = malloc(total_size);
	full_str1[0] = '\0';

	char *full_str2 = malloc(total_size);
	full_str2[0] = '\0';

	if (!full_str1 || !full_str2)
		return NULL;

	strcat(full_str1, str1);
	strcat(full_str1, str2);
	strcat(full_str2, str2);
	strcat(full_str2, str1);

	if (strcmp(full_str1, full_str2))
	{
		free(full_str1);
		free(full_str2);
		return strdup("");
	}

	free(full_str1);
	free(full_str2);

	const int gcd_size = gdc(str1_len, str2_len);

	char *result = malloc(gcd_size + 1);
	result[0] = '\0';

	int i = 0, j = 0;

	while ((str1[i] || str2[i]) && j < gcd_size)
	{
		if (str1[i] == str2[i])
			result[j++] = str1[i++];
	}

	result[j] = '\0';
	return result;
}

int main(void)
{
	char *str1 = "ABABAB";
	char *str2 = "ABAB";

	char *res = gcdOfStrings(str1, str2);

	if (res)
	{
		printf("%s\n", res);
		free(res);
	}

	return 0;
}