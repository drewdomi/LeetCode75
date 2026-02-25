#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isVowel(char c)
{
	if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
		return true;
	else
		return false;
}

char *reverseVowels(char *s)
{
	int qnt_vowels = 0;
	int str_size = 0;

	while (s[str_size])
	{
		if (isVowel(s[str_size]))
		{
			qnt_vowels++;
		}
		str_size++;
	}

	if (qnt_vowels < 1)
	{
		return strdup(s);
	}

	char vowels[qnt_vowels];
	char *str_final = calloc(1, str_size + 1);

	int idx = 0;
	for (int i = 0; s[i]; i++)
	{
		if (isVowel(s[i]))
		{
			vowels[idx] = s[i];
			idx++;
		}
	}

	qnt_vowels--;

	for (int i = 0; s[i]; i++)
	{
		if (isVowel(s[i]))
		{
			str_final[i] = vowels[qnt_vowels];
			qnt_vowels--;
		}
		else
		{
			str_final[i] = s[i];
		}
	}

	return str_final;
}

#include <stdio.h>

int main(void)
{
	char *str = " ";
	char *res = reverseVowels(str);

	if (res)
	{
		printf("%s\n", res);
		free(res);
	}

	return 0;
}