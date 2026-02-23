#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *mergeAlternately(char *word1, char *word2)
{
	int len1 = strlen(word1);
	int len2 = strlen(word2);

	char *str = malloc(len1 + len2 + 1);
	if (str == NULL)
		return NULL;

	int i = 0, j = 0, k = 0;

	while (i < len1 || j < len2)
	{
		if (i < len1)
			str[k++] = word1[i++];

		if (j < len2)
			str[k++] = word2[j++];
	}

	str[k] = '\0';
	return str;
}

int main(void)
{
	char *word1 = "Hello";
	char word2[] = {'W', 'o', 'r', 'l', 'd', '\0'};

	char *result = mergeAlternately(word1, word2);
	if (result != NULL)
	{
		printf("%s\n", result);
		free(result);
	}

	return 0;
}