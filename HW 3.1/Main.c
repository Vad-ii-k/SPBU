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
    printf("Generated array: ");
    printArray(array, SIZE);
    qsortModified(array, SIZE);
    printf("Sorted array:    ");
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
    srand(31);
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

void testCorrestSort()
{
    int testArray1[15] = { 36, 91,  0, 40, 80, 95, 35,  -3, 78, 10, 16, 22, 49, 51, 42 };
    qsortModified(testArray1, 15);
    int testSortArray1[15] = { -3,  0, 10, 16, 22, 35, 36, 40, 42, 49, 51, 78, 80, 91, 95 };
    for (int i = 0; i < 15; i++)
    {
        assert(testArray1[i] == testSortArray1[i]);
    }

    int testArray2[1] = { 100 };
    qsortModified(testArray2, 1);
    int testSortArray2[1] = { 100 };
    for (int i = 0; i < 1; i++)
    {
        assert(testArray2[i] == testSortArray2[i]);
    }

    int testArray3[11] = { 40, 80, 95, 35,  -3, 78, 10, 16, 22, 49, 51 };
    qsortModified(testArray3, -10);
    int testSortArray3[11] = { 40, 80, 95, 35,  -3, 78, 10, 16, 22, 49, 51 };
    for (int i = 0; i < 11; i++)
    {
        assert(testArray3[i] == testSortArray3[i]);
    }

    int testArray4[15] = { 25, 25, 25, 25, -25, 25, 25, 25, 25, 25, 25, 25, 15, 25, 25 };
    qsortModified(testArray4, 15);
    int testSortArray4[15] = { -25, 15, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25 };
    for (int i = 0; i < 15; i++)
    {
        assert(testArray4[i] == testSortArray4[i]);
    }
}