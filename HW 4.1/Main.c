#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define SIZE (sizeof(int) * 8)

bool* convertToBinary(int number);

int convertToDecimal(bool* bin);

bool* sumOfBinaryArrays(bool* binA, bool* binB);

void printBin(bool* bin);

void testSumBinary();

int main()
{
    testSumBinary(100, 256);
    testSumBinary(-1000, 1000);
    testSumBinary(0, -128);

    const int a = 17;
    const int b = -127;
    
    bool* binArrayA = convertToBinary(a);
    bool* binArrayB = convertToBinary(b);
    bool* binArrayResult = sumOfBinaryArrays(binArrayA, binArrayB);

    int result = 0;
    result = convertToDecimal(binArrayResult);

    printf("%10d ", a);
    printBin(binArrayA);
    printf("\n");
    printf("%10d ", b);
    printBin(binArrayB);
    printf("\n\t   ");
    printBin(binArrayResult);
    printf(" = %d\n", result);

    free(binArrayA);
    free(binArrayB);
    free(binArrayResult);
    return EXIT_SUCCESS;
}

bool* convertToBinary(int number)
{
    bool *binArray = (bool*)malloc(SIZE);
    if (NULL == binArray)
    {
        printf("OS didn't gave memory. Exit...\n");
        exit(1);
    }

    for (int i = 0; i < SIZE; i++)
    {
        binArray[i] = (number & 1) == 1;
        number >>= 1;
    }
    return binArray;
}

int convertToDecimal(bool* bin)
{
    int number = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (bin[i])
        {
            number |= 1 << i;
        }
    }
    return number;
}

bool* sumOfBinaryArrays(bool* binA, bool* binB)
{
    bool *binResult = (bool*)malloc(SIZE);
    if (NULL == binResult)
    {
        printf("OS didn't gave memory. Exit...\n");
        exit(1);
    }

    bool memorized = 0;
    for (int i = 0; i < SIZE; i++)
    {
        int sum = binA[i] + binB[i] + memorized;
        binResult[i] = sum == 1 || sum == 3;
        memorized = sum == 3 || sum == 2;
    }
    return binResult;
}

void printBin(bool* bin)
{
    for (int i = SIZE - 1; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }
}

void testSumBinary(int a, int b)
{
    bool *binA = convertToBinary(a);
    bool *binB = convertToBinary(b);
    bool *binResult = sumOfBinaryArrays(binA, binB);

    int receivedSum = convertToDecimal(binResult);
    const int correctAnswer = a + b;
    assert(correctAnswer == receivedSum, );

    free(binA);
    free(binB);
    free(binResult);
}