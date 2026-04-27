using System;
namespace Lab3Project
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                double a = ReadCoefficient("Введите коэффициент a: ");
                double b = ReadCoefficient("Введите коэффициент b: ");
                double c = ReadCoefficient("Введите коэффициент c: ");
                if (a == 0)
                {
                    Console.WriteLine("\nКоэффициент a равен 0. Уравнение является линейным (bx + c = 0).");
                    if (b != 0)
                    {
                        double linearX = -c / b;
                        Console.WriteLine($"Корень уравнения: x = {linearX}");
                    }
                    else
                    {
                        if (c == 0)
                            Console.WriteLine("Уравнение имеет бесконечное множество решений (0 = 0).");
                        else
                            Console.WriteLine("Уравнение не имеет решений.");
                    }
                    return;
                }
                double discriminant = Math.Pow(b, 2) - 4 * a * c;
                Console.WriteLine($"\nДискриминант D = {discriminant}");
                if (discriminant > 0)
                {
                    double x1 = (-b + Math.Sqrt(discriminant)) / (2 * a);
                    double x2 = (-b - Math.Sqrt(discriminant)) / (2 * a);
                    Console.WriteLine($"Уравнение имеет два различных корня:\nx1 = {x1}\nx2 = {x2}");
                }
                else if (discriminant == 0)
                {
                    double x = -b / (2 * a);
                    Console.WriteLine($"Уравнение имеет один корень (два совпадающих):\nx = {x}");
                }
                else
                {
                    Console.WriteLine("Действительных корней нет, так как дискриминант меньше нуля.");
                }
            }
            catch (FormatException)
            {
                Console.WriteLine("Ошибка: Введены некорректные данные.");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }
        static double ReadCoefficient(string prompt)
        {
            Console.Write(prompt);
            string? input = Console.ReadLine();
            return double.Parse(input);
        }
    }
}
