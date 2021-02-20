using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;

namespace HW_1._2
{
    class Program
    {
        private static void Main(string[] args)
        {
            Test();
            Console.WriteLine("Enter a string:");
            string input = Console.ReadLine();
            string output = BWT(input);
            Console.WriteLine("\n   BWT string: " + output);
            string recovery = InverseBWT(output);
            Console.WriteLine("\nSource string: " + recovery);
            for (int i = 0; i < input.Length; i++)
            {
                if (input[i] != recovery[i])
                {
                    Console.WriteLine("\nThe string was not recovered(((");
                }
                if (i == input.Length - 1)
                {
                    Console.WriteLine("\nThe string was recovered)))");
                }
            }
        }

        static void Test()
        {
            Debug.Assert(String.Equals(BWT("this is a test."), "ssa.t tt hiies $"));
            Debug.Assert(String.Equals(BWT("abcabcabc"), "ccc$aaabbb"));
            Debug.Assert(String.Equals(InverseBWT(BWT("this is a test.")), "this is a test."));
            Debug.Assert(String.Equals(InverseBWT(BWT("abcabcabc")), "abcabcabc"));
        }

        private static string BWT(string text)
        {
            text += "$";
            var array2D = new char[text.Length, text.Length];
            for (int i = 0; i < text.Length; i++)
            {
                array2D[0, i] = text[i];
            }

            for (int i = 1; i < text.Length; i++)
            {
                for (int j = 0; j < text.Length; j++)
                {
                    int index = j - 1;
                    if (index < 0)
                    {
                        index += text.Length;
                    }
                    array2D[i, j] = array2D[i - 1, index];
                }
            }

            SortedMatrix(array2D);

            var result = new char[text.Length];
            for (int i = 0; i < text.Length; i++)
            {
                result[i] = array2D[i, text.Length - 1];
            }

            return new string(result);
        }

        private static void SortedMatrix(char[,] array2D)
        {
            var permutations = new string[array2D.GetLength(0)];
            for (int i = 0; i < array2D.GetLength(0); i++)
            {
                var temp = new char[array2D.GetLength(0)];
                for (int j = 0; j < array2D.GetLength(0); j++)
                {
                    temp[j] = array2D[i, j];
                }
                permutations[i] = new string(temp);
            }
            IEnumerable<string> query = from word in permutations
                                        orderby word[..]
                                        select word;

            int count = 0;
            foreach (string str in query)
            {
                for (int j = 0; j < array2D.GetLength(0); j++)
                {
                    array2D[count, j] = str[j];
                }
                count++;
            }
        }

        private static string InverseBWT(string text)
        {
            var array2D = new char[text.Length, text.Length];
            for (int i = 0; i < text.Length; i++)
            {
                for (int j = 0; j < text.Length; j++)
                {
                    array2D[j, text.Length - i - 1] = text[j];
                }
                SortedMatrix(array2D);
            }

            var result = new char[text.Length - 1];
            for (int i = 0; i < text.Length; i++)
            {
                if (array2D[i, text.Length - 1] == '$')
                {
                    for (int j = 0; j < text.Length - 1; j++)
                    {
                        result[j] = array2D[i, j];
                    }
                    break;
                }
            }

            return new string(result);
        }
    }
}