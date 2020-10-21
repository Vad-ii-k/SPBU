#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "Header.h"

int main()
{
	FILE* file = fopen("Any text.txt", "r");
	if (file == NULL)
	{
		printf("File not found!");
		return EXIT_FAILURE;
	}

	int arraySize = 0;
	while (!feof(file))
	{
		int num;
		const int readBytes = fscanf(file, "%d", &num);
		if (readBytes < 0)
		{
			break;
		}
		arraySize++;
	}
	fseek(file, 0L, SEEK_SET);

	int* arrayNums = malloc(sizeof(int) * arraySize);
	if (arrayNums == NULL)
	{
		printf("Error");
		return EXIT_FAILURE;
	}

	int i = 0;
	while (!feof(file))
	{
		int num;
		const int readBytes = fscanf(file, "%d", &num);
		if (readBytes < 0)
		{
			break;
		}
		arrayNums[i] = num;
		i++;
	}
	fclose(file);

	quickSort(arrayNums, arraySize);

	int maxCount = 0;
	int maxValue = arrayNums[0];
	int curCount = 0;
	for (int i = 1; i < arraySize; i++)
	{
		if (arrayNums[i] == arrayNums[i - 1])
		{
			curCount++;
			if (maxCount < curCount)
			{
				maxValue = arrayNums[i];
				maxCount = curCount;
			}
		}
		else 
		{
			curCount = 0;
		}
	}
	free(arrayNums);

	printf("Value of the most frequently encountered element: %d\nThe number of repetitions: %d\n", maxValue, maxCount + 1);
	return EXIT_SUCCESS;
}