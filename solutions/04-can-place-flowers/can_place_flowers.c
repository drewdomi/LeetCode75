#include <stdbool.h>

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
	if (flowerbedSize <= 0)
		return false;

	for (int i = 0; (flowerbedSize > i) && n > 0; i++)
	{
		if (flowerbed[i] == 0 && flowerbedSize - 1 >= i)
		{
			if (i == 0 && (flowerbedSize == 1 || flowerbed[i + 1] == 0))
			{
				n--;
				flowerbed[i] = 1;
				continue;
			}
			if (flowerbedSize - 1 > i && i > 0)
			{
				if (flowerbed[i - 1] == 1 && flowerbed[i + 1] == 0)
					continue;

				if (flowerbed[i - 1] == 1 && flowerbed[i + 1] == 1)
					continue;

				if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 1 && flowerbedSize < i)
					return false;

				if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
				{
					n--;
					flowerbed[i] = 1;
					continue;
				}
			}
			else // Last element
			{
				if (i > 0 && flowerbed[i - 1] == 0)
				{
					n--;
					flowerbed[i] = 1;
					continue;
				}
			}
		}
		else
			continue;
	}

	if (n > 0)
		return false;

	return true;
}

#include <stdio.h>
#define SIZE 1

int main(void)
{
	int flowers_to_add = 1;

	int arr[SIZE] = {0};

	const bool res = canPlaceFlowers(arr, SIZE, flowers_to_add);

	if (res)
		printf("OK, flowers can be placed");
	else
		printf("Can NOT place flowers");

	puts("");
	puts("----------------");
	puts("");

	for (int i = 0; SIZE > i; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}