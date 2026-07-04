using System;

namespace MyProgram
{
    class Program
    {
        static void Main()
        {
            Console.WriteLine("Введите код: ");
            string k = Console.ReadLine();
            Console.WriteLine("Введите текст: ");
            string text = Console.ReadLine();
            Kod kod = new Kod(k);
            Console.WriteLine(kod.Encrypt(text));
            Console.WriteLine(kod.Decrypt(kod.Encrypt(text)));
        }
    }

    class Kod
    {
        private string Skey;
        public Kod(string key)
        {
            Skey = key;
        }

        public string Encrypt(string text)
        {
            string result = "";
            int keyIndex = 0;
            for (int i = 0; i < text.Length; ++i)
            {
                if (char.IsLetter(text[i]))
                {
                    bool caps = char.IsUpper(text[i]);
                    char baseChar = caps ? 'А' : 'а';
                    result += (char)((((text[i] + Skey[keyIndex]) - '0' - baseChar) % 32) + baseChar);
                    keyIndex = (++keyIndex) % Skey.Length;
                }
                else
                {
                    result += text[i];
                }
            }
            return result;
        }

        public string Decrypt(string text)
        {
            string result = "";
            int keyIndex = 0;
            for (int i = 0; i < text.Length; ++i)
            {
                if (char.IsLetter(text[i]))
                {
                    bool caps = char.IsUpper(text[i]);
                    char baseChar = caps ? 'А' : 'а';
                    result += (char)((((text[i] - Skey[keyIndex]) + '0' + baseChar) % 32) + baseChar);
                    keyIndex = (++keyIndex) % Skey.Length;
                }
                else
                {
                    result += text[i];
                }
            }
            return result;
        }
    }
}