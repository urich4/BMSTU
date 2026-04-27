using System;

namespace HW2;

class Sofa
{
    protected string color;
    protected double length;
    protected double width;

    public Sofa(string color, double length, double width)
    {
        this.color = color;
        this.length = length;
        this.width = width;
    }

    public void PrintInfo()
    {
        Console.WriteLine($"Диван: цвет = {color}, длина = {length}, ширина = {width}");
    }

    public double GetLength()
    {
        return length;
    }

    public double GetWidth()
    {
        return width;
    }

    public double CalculateArea()
    {
        return length * width;
    }
}

class SofaBed: Sofa
{
    bool razl;
    private double length_r;
    private double width_r;

    public SofaBed(string col, double len, double wid, bool r, double len2, double wid2): base(col, len, wid)
    {
        this.length_r = len2;
        this.width_r = wid2;
        this.razl = r;
    }

    public new void PrintInfo()
    {
        Console.WriteLine($"Диван: цвет = {color}, длина = {length}, ширина = {width}, состояние = {razl}, длина разлож = {length_r}, ширина разлож = {width_r}.");
    }

    public void Slojit()
    {
        this.razl = false;
    }

    public void Razlojit()
    {
        this.razl = true;
    }

     public new double GetLength()
    {
        if (!razl)
            return length;
        else 
            return length_r;
    }

    public new double GetWidth()
    {
        if (!razl)
            return width;
        else 
            return width_r;
    }

    public double OtnoshPlos()
    {
        return (length_r * width_r) / (length * width);
    }

}

class Program
{
    static void Main(string[] args)
    {
        Sofa mySofa = new Sofa("Серый", 2.2, 1.4);
        
        mySofa.PrintInfo();

        Console.WriteLine($"Запрошенная длина: {mySofa.GetLength()} м");
        Console.WriteLine($"Запрошенная ширина: {mySofa.GetWidth()} м");
        Console.WriteLine($"Занимаемая площадь: {mySofa.CalculateArea()} кв.м");

        SofaBed mySofa2 = new SofaBed("Бежевый", 2.0, 1.0, false, 2.0, 1.6);
        mySofa2.PrintInfo();

        Console.WriteLine($"Текущая длина: {mySofa2.GetLength()}, ширина: {mySofa2.GetWidth()}");
        
        mySofa2.Razlojit(); 
        Console.WriteLine("Диван разложили.");
        Console.WriteLine($"Текущая длина: {mySofa2.GetLength()}, ширина: {mySofa2.GetWidth()}");

        Console.WriteLine($"Разложенный диван больше сложенного в {mySofa2.OtnoshPlos()} раз");
    }
}