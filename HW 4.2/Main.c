#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include <assert.h>
#include "Sort.h"

int fileSize(FILE* file)
{
	int arraySize = 0;
	while (!feof(file))
	{
		const int readBytes = fscanf(file, "%*d");
		if (readBytes < 0)
		{
			break;
		}
		arraySize++;
	}
	fseek(file, 0L, SEEK_SET);
	return arraySize;
}

void readingFile(FILE* file, int* arrayNums, const int arraySize)
{
	int i = 0;
	while (!feof(file))
	{
		int num = 0;
		const int readBytes = fscanf(file, "%d", &num);
		if (readBytes < 0)
		{
			break;
		}
		if (i < arraySize)
		{
			arrayNums[i] = num;
		}
		i++;
	}
}

int mostFrequentlyEncounteredElement(int* arrayNums, const int arraySize)
{
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
	return maxValue;
}

int numberOfRepetitions(const int maxValue, int* arrayNums, const int arraySize)
{
	int maxCount = 0;
	for (int i = 0; i < arraySize; i++)
	{
		while (maxValue == arrayNums[i] and i < arraySize)
		{
			maxCount++;
			i++;
			if (maxValue != arrayNums[i])
			{
				return maxCount;
			}
		}
	}
	return 0;
}

void test()
{
	int arrayNums[6] = { 1, 2, 2, 3, 3, 3 };
	quickSort(arrayNums, 6);
	int maxValue = mostFrequentlyEncounteredElement(arrayNums, 6);
	int maxCount = numberOfRepetitions(maxValue, arrayNums, 6);
	assert(maxCount == 3 and maxValue == 3);
}

int main()
{
	test();

	FILE* file = fopen("Any text.txt", "r");
	if (file == NULL)
	{
		printf("File not found!");
		return EXIT_FAILURE;
	}

	const int arraySize = fileSize(file);
	if (arraySize <= 0)
	{
		printf("File is empty!");
		return 1;
	}

	int* arrayNums = malloc(arraySize * sizeof(int));
	if (NULL == arrayNums)
	{
		printf("OS didn't gave memory. Exit...\n");
		return 1;
	}

	readingFile(file, arrayNums, arraySize);
	fclose(file);
	quickSort(arrayNums, arraySize);

	int maxValue = mostFrequentlyEncounteredElement(arrayNums, arraySize);
	int maxCount = numberOfRepetitions(maxValue, arrayNums, arraySize);
	free(arrayNums);
	printf("Value of the most frequently encountered element: %d\n", maxValue);
	printf("The number of repetitions: %d\n", maxCount);
	return EXIT_SUCCESS;
}