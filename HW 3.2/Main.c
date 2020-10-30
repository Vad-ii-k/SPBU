#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

void qsortFunction(int* mas, int size);

bool binarySearch(int a, int *mas, int n);

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
	int* inputArray;
	inputArray = (int*)malloc(sizeOfArray*(sizeof(int)));
	if (NULL == inputArray)
	{
		printf("OS didn't gave memory. Exit...\n");
		exit(1);
	}

	randArray(inputArray, sizeOfArray);
	qsortFunction(inputArray, sizeOfArray);
	printArray(inputArray, sizeOfArray);

	search(inputArray, sizeOfArray, countOfNumbers);

	free(inputArray);
	return 0;
}

void randArray(int* array, const int size)
{
	printf("Generated array: ");
	srand(32);
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
		printf("%2d ", array[i]);
	}
	printf("\n");
}

void printArray(int* array, const int size)
{
	printf("Sorted array:    ");
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
		int middle;
		middle = (left + right) / 2;
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

void qsortFunction(int* mas, const int size)
{
	int i = 0;
	int j = size - 1;
	const int mid = mas[size / 2];

	do
	{
		while (mas[i] < mid)
		{
			i++;
		}
		while (mas[j] > mid)
		{
			j--;
		}

		if (i <= j)
		{
			swap(mas + i, mas + j);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
	{
		qsortFunction(mas, j + 1);
	}
	if (i < size)
	{
		qsortFunction(mas + i, size - i);
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