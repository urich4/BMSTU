using System;

namespace MyProgram
{
    class Program
    {
        static void Main(string[] args)
        {
//             int[,] matrix = new int[5,5]{
//     { 0, 2, 0, 0, 1 },
//     { 2, 0, 3, 0, 0 },
//     { 0, 3, 0, 4, 0 },
//     { 0, 0, 4, 0, 5 },
//     { 1, 0, 0, 5, 0 }
// };
            Console.WriteLine("Введите размер матрицы: ");
            int n = Convert.ToInt32(Console.ReadLine());
            int[,] matrix = new int[n,n];
            
            Console.WriteLine("Введите матрицу:");
            for (int i = 0; i < n; ++i)
            {
                string[] input = Console.ReadLine().Split(' ');
                for (int j = 0; j < n; ++j)
                {
                    matrix[i, j] = Convert.ToInt32(input[j]);
                }
            }
            Map map = new Map(matrix);
            int[,] newMatr = map.BuildNewMatr();
            Console.WriteLine("Новая матрица: ");
            map.PrintMatr(newMatr);
        }
    }

    class Map
    {
        private int[,] roadMatrix;
        private int maxElement;

        public Map(int[,] matrix)
        {
            roadMatrix = matrix;
            maxElement = FindMaxElem();
        }
        private int FindMaxElem()
        {
            int max = 0;
            for(int i = 0; i < roadMatrix.GetLength(0); ++i)
            {
                for(int j = 0; j < roadMatrix.GetLength(1); ++j)
                {
                    if (roadMatrix[i,j] > max) max = roadMatrix[i,j];
                }
            }
            return max;
        }
        public int[,] BuildNewMatr()
        {
            int[,] result = new int[maxElement, maxElement];
            int p1 = -1, p2 = -1;
            for (int i = 0; i < roadMatrix.GetLength(0); ++i)
            {
                for (int j = 0; j < roadMatrix.GetLength(1); ++j)
                {
                    if (roadMatrix[i,j] != 0)
                    {   if(p2 == -1) p2 = roadMatrix[i,j];
                        else
                        p1 = roadMatrix[i,j];
                    }

                }
                if (p1 != -1 && p2 != -1) 
                {
                result[p1-1, p2-1] = i;
                result[p2-1, p1-1] = i;
                }
                p1 = -1; p2 = -1;
            }
            return result;
        }
        public void PrintMatr(int[,] matr)
        {
        
            for (int i = 0; i < matr.GetLength(1); ++i)
            {
                for (int j = 0; j < matr.GetLength(0); ++j)
                {
                    Console.Write(matr[i, j] + " ");
                }
                Console.WriteLine();
            }
        }
    }
}