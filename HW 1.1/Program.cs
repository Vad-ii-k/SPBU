using System;
using System.Diagnostics;

namespace HW_1._1
{
    class Program
    {
        static void Main(string[] args)
        {
            Test();
            Console.WriteLine($"Enter array elements:");
            string[] nums = Console.ReadLine().Split(' ');
            int[] array = new int[nums.Length];
            for (int i = 0; i < nums.Length; i++)
            {
                array[i] = int.Parse(nums[i]);
            }

            BubbleSort(array);
            Console.WriteLine("Sorted array:");
            foreach (int value in array)
            {
                Console.Write(value + " ");
            }
        }

        static void BubbleSort(int[] sortArray)
        {
            for (int i = 0; i < sortArray.Length - 1; i++)
                for (int j = 0; j < sortArray.Length - 1 - i; j++)
                    if (sortArray[j] > sortArray[j + 1])
                    {
                        int temp = sortArray[j];
                        sortArray[j] = sortArray[j + 1];
                        sortArray[j + 1] = temp;
                    }
        }

        static void Test()
        {
            int[] testArray = { 36, 91, 0, 40, 80, 95, 35, -3, 78, 10, 16, 22, 49, 51, 42 };
            BubbleSort(testArray);
            int[] testSortArray = { -3, 0, 10, 16, 22, 35, 36, 40, 42, 49, 51, 78, 80, 91, 95 };
            for (int i = 0; i < testArray.Length; i++)
            {
                Debug.Assert(testArray[i] == testSortArray[i]);
            }
        }
    }
}
