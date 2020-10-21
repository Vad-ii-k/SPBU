#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE sizeof(int) * 8

void convertToBinary(int number, bool* bin);

int convertToDecimal(bool* bin);

void sumOfBinaryArrays(bool* binA, bool* binB, bool* binResult);

void printBin(bool* bin);

bool testSumBinary();

int main()
{
    if (!testSumBinary())
    {
        printf("The tests fail!");
        return EXIT_FAILURE;
    }

    const int a = 17;
    const int b = -127;
    int result = -9999;
    bool binArrayA[SIZE];
    bool binArrayB[SIZE];
    bool binArrayResult[SIZE];

    convertToBinary(a, binArrayA);
    convertToBinary(b, binArrayB);
    sumOfBinaryArrays(binArrayA, binArrayB, binArrayResult);
    result = convertToDecimal(binArrayResult);
    
    printf("%10d ", a);
    printBin(binArrayA);
    printf("\n");
    printf("%10d ", b);
    printBin(binArrayB);
    printf("\n           ");
    printBin(binArrayResult);
    printf(" = %d\n", result);
    return EXIT_SUCCESS;
}

void convertToBinary(int number, bool* bin)
{
    for (int i = 0; i < SIZE; i++)
    {
        bin[i] = (number & 1) == 1;
        number >>= 1;
    }
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

void sumOfBinaryArrays(bool* binA, bool* binB, bool* binResult)
{
    bool memorized = false;

    for (int i = 0; i < SIZE; i++)
    {
        int sum = binA[i] + binB[i] + memorized;
        binResult[i] = sum == 1 || sum == 3;
        memorized = sum == 3 || sum == 2;
    }
}

void printBin(bool* bin)
{
    for (int i = SIZE - 1; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }
}

bool testSumBinary()
{
    for (int a = -500; a < 500; a++)
    {
        for (int b = 400; b < 1000; b++)
        {
            const int correctAnswer = a + b;
            bool binA[SIZE];
            bool binB[SIZE];
            bool binResult[SIZE];
            convertToBinary(a, binA);
            convertToBinary(b, binB);
            sumOfBinaryArrays(binA, binB, binResult);
            int receivedSum = convertToDecimal(binResult);

            if (correctAnswer != receivedSum)
            {
                return false;
            }
        }
    }
    return true;
}