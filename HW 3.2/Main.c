#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void qsortFunction(int* array, const int size);

bool binarySearch(int a, int *array, const int size);

void randArray(int* array, const int size);

void printArray(int* array, const int size);

void search(int* array, const int size, const int countOfNumbers);

void swap(int* x, int* y);

void testCorrectSort(void);

void testCorrectSearch(int* array, const int size);

int main()
{
	testCorrectSort();
	printf("Enter size of array and count of numbers to search for:\n");
	int sizeOfArray = 0; 
	int countOfNumbers = 0;
	scanf_s("%d%d", &sizeOfArray, &countOfNumbers);
	int* inputArray = malloc(sizeOfArray * sizeof(int));
	if (NULL == inputArray)
	{
		printf("OS didn't gave memory. Exit...\n");
		return 1;
	}

	randArray(inputArray, sizeOfArray);
	printf("Generated array: ");
	printArray(inputArray, sizeOfArray);
	qsortFunction(inputArray, sizeOfArray);
	printf("Sorted array:    ");
	printArray(inputArray, sizeOfArray);

	search(inputArray, sizeOfArray, countOfNumbers);

	free(inputArray);
	return 0;
}

void randArray(int* array, const int size)
{
	srand(32);
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
	}
}

void printArray(int* array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%2d ", array[i]);
	}
	printf("\n");
}

bool binarySearch(int y, int* array, const int size)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (y < array[middle])
		{
			right = middle - 1;
		}
		else if (y > array[middle])
		{
			left = middle + 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

void qsortFunction(int* array, const int size)
{
	int i = 0;
	int j = size - 1;
	const int mid = array[size / 2];

	do
	{
		while (array[i] < mid)
		{
			i++;
		}
		while (array[j] > mid)
		{
			j--;
		}

		if (i <= j)
		{
			swap(array + i, array + j);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
	{
		qsortFunction(array, j + 1);
	}
	if (i < size)
	{
		qsortFunction(array + i, size - i);
	}
}

void search(int* array, const int size, const int countOfNumbers)
{
	for (int i = 0; i < countOfNumbers; i++)
	{
		int x = rand() % 100;
		if (binarySearch(x, array, size))
		{
			printf("%3d is in array.\n", x);
		}
		else
		{
			printf("%3d is not in array.\n", x);
		}
	}
}

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void testCorrectSort(void)
{
	int testArray[15] = { 36, 91,  0, 40, 80, 95, 35,  -3, 78, 10, 16, 22, 49, 51, 42 };
	qsortFunction(testArray, 15);
	int testSortArray[15] = { -3,  0, 10, 16, 22, 35, 36, 40, 42, 49, 51, 78, 80, 91, 95 };
	for (int i = 0; i < 15; i++)
	{
		assert(testArray[i] == testSortArray[i]);
	}
	testCorrectSearch(testArray, 15);
}

void testCorrectSearch(int *array, const int size)
{
	assert(binarySearch(10, array, size));
	assert(binarySearch(-3, array, size));
	assert(!binarySearch(1, array, size));
}