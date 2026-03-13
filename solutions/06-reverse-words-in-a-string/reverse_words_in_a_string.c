#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_alpha_numeric(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return true;
	else
		return false;
}

char *reverseWords(char *s)
{

	if (strlen(s) == 0)
	{
		return strdup("");
	}

	int i = 0;

	char *temp_res = calloc(1, strlen(s) + 1);

	if (s[i] >= 0 && s[i] <= 13 || (s[i] == 32))
		i++;

	int j = 0;
	while (s[i])
	{
		if (is_alpha_numeric(s[i]) || (s[i] == 32 && s[i + 1] != 32))
		{
			temp_res[j] = s[i];
			j++;
		}
		i++;
	}

	temp_res[j] = '\0';
	int real_res_size = 0;

	while (temp_res[real_res_size])
	{
		if ((i == 0 || i + 1 == strlen(temp_res)) && temp_res[i] == ' ')
			continue;
		real_res_size++;
	}

	char *fixed_str = calloc(1, real_res_size + 1);
	char *result = calloc(1, real_res_size + 1);
	int res_idx = 0;

	for (int i = 0; temp_res[i]; i++)
	{
		if ((i == 0 || i + 1 == strlen(temp_res)) && temp_res[i] == ' ')
			continue;
		fixed_str[res_idx] = temp_res[i];
		res_idx++;
	}

	fixed_str[res_idx] = '\0';

	free(temp_res);

	int cursor = 0;
	int save_idx = 0;
	const int limit_cursor = real_res_size;
	while (true)
	{
		if (real_res_size == 0)
		{
			if (cursor != 0)
				result[cursor++] = ' ';

			while (is_alpha_numeric(fixed_str[real_res_size]))
			{
				result[cursor] = fixed_str[real_res_size];
				real_res_size++;
				if (cursor < limit_cursor)
					cursor++;
			}
			break;
		}
		if (real_res_size < 0)
		{
			real_res_size = 0;
		}
		if (fixed_str[real_res_size] != ' ')
		{
			real_res_size--;
		}
		else
		{
			if (cursor != 0)
			{
				result[cursor] = ' ';
				cursor++;
			}

			real_res_size++;
			save_idx = real_res_size;

			while (is_alpha_numeric(fixed_str[save_idx]))
			{
				result[cursor] = fixed_str[save_idx];
				cursor++;
				save_idx++;
			}

			real_res_size -= 2;
			continue;
		}
	}

	free(fixed_str);

	return result;
}

#include <stdio.h>

int main(void)
{
	char *str = "    a good  next   example     ";

	char *result = reverseWords(str);

	if (result)
	{
		printf("%s\n", result);
		free(result);
	}

	return 0;
}