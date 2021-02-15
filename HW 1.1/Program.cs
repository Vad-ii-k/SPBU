using System;

namespace HW_1._1
{
    class Program
    {
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

        static void Main(string[] args)
        {
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
    }
}
