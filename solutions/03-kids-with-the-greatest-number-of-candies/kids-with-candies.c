#include <stdbool.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize)
{
	*returnSize = candiesSize;
	bool *res = malloc(candiesSize * sizeof(bool));
	int max_candies = candies[0];
	int i = 0;

	while (i < candiesSize)
	{
		if (candies[i] > max_candies)
			max_candies = candies[i];
		i++;
	}

	for (int i = 0; i < candiesSize; i++)
	{
		if (candies[i] + extraCandies >= max_candies)
			res[i] = true;
		else
			res[i] = false;
	}

	return res;
}