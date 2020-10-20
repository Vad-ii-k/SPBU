#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* x, int* y);

void qsortX(int* mas, int size);

int binarySearch(int a, int mass[], int n);

int main()
{
	int* inputArray;
	int arraySize, countOfNumbers;
	scanf("%d%d", &arraySize, &countOfNumbers);
	inputArray = (int*)malloc(arraySize);

	srand(32);
	for (int i = 0; i < arraySize; i++)
	{
		inputArray[i] = rand() % 100;
		printf("%d ", inputArray[i]);
	}

	qsortX(inputArray, arraySize);
	printf("\n");

	for (int i = 0; i < countOfNumbers; i++)
	{
		int x = rand() % 100;
		if (binarySearch(x, inputArray, arraySize))
			printf("%3d is in array.\n", x);
		else
			printf("%3d is not in array.\n", x);
	}
	return 0;
}

int binarySearch(int y, int* mas, int n)
{
	int left, right, middle;
	left = 0;
	right = n - 1;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (y < mas[middle])
		{
			right = middle - 1;
		}
		else if (y > mas[middle])
		{
			left = middle + 1;
		}
		else
		{
			return middle;
		}
	}
	return 0;
}

void qsortX(int* mas, int size)
{
	int i = 0;
	int j = size - 1;
	int mid = mas[size / 2];

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
			swap(&mas[i], &mas[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
	{
		qsortX(mas, j + 1);
	}
	if (i < size)
	{
		qsortX(&mas[i], size - i);
	}
}

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}