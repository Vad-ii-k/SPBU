#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 30

void qsortModified(int* array, const int size);

void insertSort(int* array, const int size);

void swap(int* x, int* y);

void randArray(int* array, const int size);

void printArray(int* array, const int size);

void testCorrestSort();

int main()
{
    testCorrestSort();
    int array[SIZE];
    randArray(array, SIZE);
    qsortModified(array, SIZE);
    printArray(array, SIZE);
    return EXIT_SUCCESS;
}

void insertSort(int* array, const int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
        {
            swap(&array[j - 1], &array[j]);
        }
    }
}

void qsortModified(int* array, const int size)
{
    int i = 0;
    int j = size - 1;
    const int middle = array[size / 2];

    if (size < 10)
    {
        insertSort(array, size);
    }

    do
    {
        while (array[i] < middle)
        {
            i++;
        }
        while (array[j] > middle)
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
        qsortModified(array, j + 1);
    }

    if (i < size)
    {
        qsortModified(array + i, size - i);
    }
}

void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void randArray(int* array, const int size)
{
    printf("Generated array: ");
    srand(31);
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

void testCorrestSort()
{
    int testArray[15] = { 36, 91,  0, 40, 80, 95, 35,  -3, 78, 10, 16, 22, 49, 51, 42 };
    qsortModified(testArray, 15);
    int testSortArray[15] = { -3,  0, 10, 16, 22, 35, 36, 40, 42, 49, 51, 78, 80, 91, 95 };
    for (int i = 0; i < 15; i++)
    {
        assert(testArray[i] == testSortArray[i]);
    }
}