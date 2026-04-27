using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
Cabin[] list = {
    new Cabin(101, "Люкс", 2),
    new Cabin(102, "Эконом", 4),
    new Cabin(103, "Первый класс", 2),
    new Cabin(104, "Эконом", 2)
    };
PassPal deck = new PassPal(list);
deck.Show();
Console.WriteLine($"Общее количество мест на палубе: {deck.GetTotalCapacity()}\n");
string targetClass = Console.ReadLine();
int targetCapacity = int.Parse(Console.ReadLine());
int foundCabinNumber = deck.FindNumber(targetClass, targetCapacity);

Console.WriteLine(foundCabinNumber != -1 ? $"Найдена каюта с номером: {foundCabinNumber}" : "Каюта не найдена");
}}

class Cabin
{
    private int number;
    private string serviceClass;
    private int capacity;

    public Cabin (int num, string ser, int cap)
    {
        number = num;
        serviceClass = ser;
        capacity = cap;
    }

    public void Show()
    {
        Console.WriteLine($"Каюта {number}, {serviceClass}, {capacity}");
    }
    public int GetCapacity()
    {
        return capacity;
    }
    public string GetServiceClass()
    {
        return serviceClass;
    }
    public int GetNumber()
    {
        return number;
    }
}

class PassPal
{
    Cabin[] listCabin;
    public PassPal(Cabin[] cabin)
    {
        listCabin = cabin;
    }
    public void Show()
    {
        for (int i = 0; i < listCabin.Length; i++)
        {
            listCabin[i].Show();
        }
    }
    public int GetTotalCapacity()
    {
        int sum = 0;
        for (int i = 0; i < listCabin.Length ; i++)
        {
            sum += listCabin[i].GetCapacity();
        }
        return sum;
    }
    public int FindNumber(string serClass, int capacity)
    {
        for (int i = 0; i < listCabin.Length; i++)
        {
            if (listCabin[i].GetServiceClass() == serClass && listCabin[i].GetCapacity() == capacity)
            {
                return listCabin[i].GetNumber();
            }
        }
        return -1;
    }
}
