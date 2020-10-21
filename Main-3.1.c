#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

void qsortModified(int* mas, int size);

void insertSort(int* mas, int size);

void swap(int* x, int* y);

int main()
{
    srand(31);
    int array[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    qsortModified(array, SIZE);
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}

void insertSort(int* mas, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0 && mas[j - 1] > mas[j]; j--)
        {
            swap(&mas[j - 1], &mas[j]);
        }
    }
}

void qsortModified(int* mas, int size)
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
        if (j + 1 < 10)
        {
            insertSort(mas, j + 1);
        }
        else
        {
            qsortModified(mas, j + 1);
        }
    }
    if (i < size)
    {
        if (size - i < 10)
        {
            insertSort(&mas[i], size - i);
        }
        else
        {
            qsortModified(&mas[i], size - i);
        }
    }
}

void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}