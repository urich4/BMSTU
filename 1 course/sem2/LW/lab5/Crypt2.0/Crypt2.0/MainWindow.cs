using System;
using Gtk;
using System.Collections.Generic;

public partial class MainWindow : Gtk.Window
{
    private List<string> spisok;
    public MainWindow() : base(Gtk.WindowType.Toplevel)
    {
        Build();
        spisok = new List<string>();
    }

    protected void OnDeleteEvent(object sender, DeleteEventArgs a)
    {
        Application.Quit();
        a.RetVal = true;
    }

    protected void OnButton1Clicked(object sender, EventArgs e)
    {
        string text = entry1.Text;
        Kod kod = new Kod(entry3.Text);
        entry1.Text = kod.Encrypt(text);
        spisok.Add("Операция: Шифрование. Текст: " + text);
        SpisokUpdate();

    }

    protected void OnButton2Clicked(object sender, EventArgs e)
    {
        string text = entry2.Text;
        Kod kod = new Kod(entry3.Text);
        entry2.Text = kod.Decrypt(text);
        spisok.Add("Операция: Дeшифрование. Текст: " + text);
        SpisokUpdate();
    }
    private void SpisokUpdate()
    {
        textview1.Buffer.Text = "";
        foreach (string el in spisok)
        {
            Gtk.TextIter iter = textview1.Buffer.EndIter;
            textview1.Buffer.Insert(ref iter, el + '\n');
        }
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
