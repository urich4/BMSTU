using System;
using System.Collections.Generic;
using System.IO;
using Gtk;

// 1. Структура данных
public struct DataStruct
{
    public int Number;
    public string Name;
    public int Size;
    public string Date;
    public int Godnost;
}

public partial class MainWindow : Gtk.Window
{
    private TreeView tableWidget;
    private ComboBox filterComboBox;

    private Dictionary<int, DataStruct> database = new Dictionary<int, DataStruct>();
    private ListStore listStore;
    private string filePath = "";
    private bool safe = true;

    private AddForm addForm;

    public MainWindow() : base(Gtk.WindowType.Toplevel)
    {
        this.Title = "Product Magazine";
        this.SetDefaultSize(800, 600);
        this.SetPosition(WindowPosition.Center);

        VBox mainVBox = new VBox(false, 2);

        HBox row1 = new HBox(true, 2);
        Button btnCreate = new Button("Создать файл");
        btnCreate.Clicked += OnCreateBtnClicked;
        Button btnLoad = new Button("Загрузить файл");
        btnLoad.Clicked += OnDownloadBtnClicked;
        Button btnSave = new Button("Сохранить изменения");
        btnSave.Clicked += OnSaveBtnClicked;

        row1.PackStart(btnCreate, true, true, 0);
        row1.PackStart(btnLoad, true, true, 0);
        row1.PackStart(btnSave, true, true, 0);
        mainVBox.PackStart(row1, false, false, 0);

        HBox row2 = new HBox(true, 2);
        Button btnAdd = new Button("Добавить");
        btnAdd.Clicked += OnAddBtnClicked;
        Button btnDel = new Button("Удалить");
        btnDel.Clicked += OnDelBtnClicked;

        row2.PackStart(btnAdd, true, true, 0);
        row2.PackStart(btnDel, true, true, 0);
        mainVBox.PackStart(row2, false, false, 0);

        HBox row3 = new HBox(false, 2);
        filterComboBox = ComboBox.NewText();
        filterComboBox.AppendText("Фильтр по дате");
        filterComboBox.AppendText("Срок истекает сегодня");
        filterComboBox.AppendText("Минимальная годность");
        filterComboBox.Active = 0; // Значение по умолчанию

        Button btnFilter = new Button("Определить");
        btnFilter.Clicked += OnFilterBtnClicked;
        Button btnReset = new Button("Сбросить");
        btnReset.Clicked += OnResetBtnClicked;

        row3.PackStart(filterComboBox, true, true, 0);
        row3.PackStart(btnFilter, false, false, 0);
        row3.PackStart(btnReset, false, false, 0);
        mainVBox.PackStart(row3, false, false, 0);

        ScrolledWindow scrollWindow = new ScrolledWindow();
        scrollWindow.ShadowType = ShadowType.In;
        tableWidget = new TreeView();
        scrollWindow.Add(tableWidget);
        mainVBox.PackStart(scrollWindow, true, true, 0);

        this.Add(mainVBox);
        this.ShowAll();

        InitTable();

        addForm = new AddForm();
        addForm.DataSent += TakeData;
    }

    private void InitTable()
    {
        listStore = new ListStore(typeof(int), typeof(string), typeof(int), typeof(string), typeof(int));
        tableWidget.Model = listStore;

        tableWidget.AppendColumn("Номер", new CellRendererText(), "text", 0);
        tableWidget.AppendColumn("Название", new CellRendererText(), "text", 1);
        tableWidget.AppendColumn("Объем", new CellRendererText(), "text", 2);
        tableWidget.AppendColumn("Дата поставки", new CellRendererText(), "text", 3);
        tableWidget.AppendColumn("Годность", new CellRendererText(), "text", 4);
    }

    protected void OnDownloadBtnClicked(object sender, EventArgs e)
    {
        FileChooserDialog fileChooser = new FileChooserDialog(
            "Выберите файл для загрузки",
            this,
            FileChooserAction.Open,
            "Отмена", ResponseType.Cancel,
            "Открыть", ResponseType.Accept);

        FileFilter filter = new FileFilter();
        filter.Name = "Текстовые файлы (*.txt)";
        filter.AddPattern("*.txt");
        fileChooser.AddFilter(filter);

        if (fileChooser.Run() == (int)ResponseType.Accept)
        {
            filePath = fileChooser.Filename;
            ReadData();
        }
        fileChooser.Destroy();
    }

    protected void OnCreateBtnClicked(object sender, EventArgs e)
    {
        FileChooserDialog fileChooser = new FileChooserDialog(
            "Создать и сохранить файл",
            this,
            FileChooserAction.Save,
            "Отмена", ResponseType.Cancel,
            "Сохранить", ResponseType.Accept);

        if (fileChooser.Run() == (int)ResponseType.Accept)
        {
            filePath = fileChooser.Filename;
            File.Create(filePath).Close();
            ReadData();
        }
        fileChooser.Destroy();
    }

    private void ReadData()
    {
        database.Clear();
        try
        {
            using (StreamReader sr = new StreamReader(filePath))
            {
                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    string[] parts = line.Split(';');
                    if (parts.Length == 5)
                    {
                        DataStruct dataTemp = new DataStruct
                        {
                            Number = int.Parse(parts[0]),
                            Name = parts[1],
                            Size = int.Parse(parts[2]),
                            Date = parts[3],
                            Godnost = int.Parse(parts[4])
                        };
                        database[dataTemp.Number] = dataTemp;
                    }
                }
            }
            UpdateTableData();
        }
        catch (Exception ex)
        {
            ShowMessage(MessageType.Error, "Ошибка чтения файла: " + ex.Message);
        }
    }

    private void WriteData()
    {
        try
        {
            using (StreamWriter sw = new StreamWriter(filePath))
            {
                foreach (var item in database)
                {
                    sw.WriteLine($"{item.Key};{item.Value.Name};{item.Value.Size};{item.Value.Date};{item.Value.Godnost}");
                }
            }
        }
        catch (Exception ex)
        {
            ShowMessage(MessageType.Error, "Ошибка записи файла: " + ex.Message);
        }
    }

    private void UpdateTableData()
    {
        listStore.Clear();
        safe = false;

        foreach (var item in database)
        {
            AddTableItem(item.Key, item.Value);
        }
    }

    private void AddTableItem(int key, DataStruct value)
    {
        listStore.AppendValues(key, value.Name, value.Size, value.Date, value.Godnost);
    }

    private void TakeData(int number, string name, int size, string date, int godnost)
    {
        DataStruct dataTemp = new DataStruct
        {
            Number = number,
            Name = name,
            Size = size,
            Date = date,
            Godnost = godnost
        };

        database[number] = dataTemp;
        UpdateTableData();
    }

    protected void OnAddBtnClicked(object sender, EventArgs e)
    {
        if (string.IsNullOrEmpty(filePath))
        {
            ShowMessage(MessageType.Warning, "Файл не выбран.");
            return;
        }
        addForm.ShowAll();
    }

    protected void OnSaveBtnClicked(object sender, EventArgs e)
    {
        if (!string.IsNullOrEmpty(filePath))
        {
            WriteData();
            ShowMessage(MessageType.Info, "Данные сохранены.");
            safe = true;
        }
        else
        {
            ShowMessage(MessageType.Warning, "Файл не выбран.");
        }
    }

    protected void OnDelBtnClicked(object sender, EventArgs e)
    {
        TreeSelection selection = tableWidget.Selection;
        if (selection.GetSelected(out TreeIter iter))
        {
            int id = (int)listStore.GetValue(iter, 0);
            database.Remove(id);
            UpdateTableData();
        }
        else
        {
            ShowMessage(MessageType.Warning, "Строка не выбрана.");
        }
    }

    protected void OnFilterBtnClicked(object sender, EventArgs e)
    {
        int textIndex = filterComboBox.Active;
        switch (textIndex)
        {
            case 0: FilterItemData(); break;
            case 1: FilterItemSrok(); break;
            case 2: FilterItemGodnost(); break;
        }
    }

    protected void OnResetBtnClicked(object sender, EventArgs e)
    {
        UpdateTableData();
    }

    private void FilterItemGodnost()
    {
        if (database.Count == 0) return;

        int min = int.MaxValue;
        foreach (var val in database.Values)
        {
            if (val.Godnost < min) min = val.Godnost;
        }

        listStore.Clear();
        foreach (var kvp in database)
        {
            if (kvp.Value.Godnost == min)
            {
                AddTableItem(kvp.Key, kvp.Value);
            }
        }
    }

    private void FilterItemSrok()
    {
        listStore.Clear();
        DateTime today = DateTime.Today;

        foreach (var kvp in database)
        {
            if (DateTime.TryParseExact(kvp.Value.Date, "dd.MM.yyyy", null, System.Globalization.DateTimeStyles.None, out DateTime parsedDate))
            {
                if (parsedDate.AddDays(kvp.Value.Godnost) == today)
                {
                    AddTableItem(kvp.Key, kvp.Value);
                }
            }
        }
    }

    private void FilterItemData()
    {
        MessageDialog md = new MessageDialog(this, DialogFlags.Modal, MessageType.Question, ButtonsType.OkCancel, "Введите дату в формате ДД.ММ.ГГГГ:");
        Entry entry = new Entry();
        md.VBox.Add(entry);
        md.ShowAll();

        if (md.Run() == (int)ResponseType.Ok && !string.IsNullOrEmpty(entry.Text))
        {
            if (DateTime.TryParseExact(entry.Text, "dd.MM.yyyy", null, System.Globalization.DateTimeStyles.None, out DateTime targetDate))
            {
                listStore.Clear();
                foreach (var kvp in database)
                {
                    if (DateTime.TryParseExact(kvp.Value.Date, "dd.MM.yyyy", null, System.Globalization.DateTimeStyles.None, out DateTime itemDate))
                    {
                        if (itemDate > targetDate)
                        {
                            AddTableItem(kvp.Key, kvp.Value);
                        }
                    }
                }
            }
            else
            {
                ShowMessage(MessageType.Error, "Неверный формат даты!");
            }
        }
        md.Destroy();
    }

    private void ShowMessage(MessageType type, string message)
    {
        MessageDialog md = new MessageDialog(this, DialogFlags.Modal, type, ButtonsType.Ok, message);
        md.Run();
        md.Destroy();
    }

    protected void OnDeleteEvent(object sender, DeleteEventArgs a)
    {
        if (safe)
        {
            a.RetVal = false;
            return;
        }

        MessageDialog md = new MessageDialog(this, DialogFlags.Modal, MessageType.Question, ButtonsType.YesNo, "Вы уверены, что хотите закрыть программу?\nВсе несохраненные изменения будут потеряны.");
        int response = md.Run();
        md.Destroy();

        if (response == (int)ResponseType.Yes)
        {
            a.RetVal = false; 
        }
        else
        {
            a.RetVal = true;
        }
    }
}

public partial class AddForm : Gtk.Window
{
    private Entry numberEntry;
    private Entry nameEntry;
    private Entry sizeEntry;
    private Entry dateEntry;
    private Entry godnostEntry;

    public event Action<int, string, int, string, int> DataSent;

    public AddForm() : base(Gtk.WindowType.Toplevel)
    {
        this.Title = "Добавление товара";
        this.SetDefaultSize(350, 250);
        this.SetPosition(WindowPosition.Center);

        VBox vbox = new VBox(false, 5);
        vbox.BorderWidth = 10;

        numberEntry = CreateInputRow(vbox, "Номер:");
        nameEntry = CreateInputRow(vbox, "Название:");
        sizeEntry = CreateInputRow(vbox, "Объем:");
        dateEntry = CreateInputRow(vbox, "Дата (ДД.ММ.ГГГГ):");
        godnostEntry = CreateInputRow(vbox, "Годность:");

        Button btnAdd = new Button("Подтвердить");
        btnAdd.Clicked += OnAddBtnClicked;

        vbox.PackStart(btnAdd, false, false, 10);

        this.Add(vbox);
    }

    private Entry CreateInputRow(VBox parent, string labelText)
    {
        HBox hbox = new HBox(false, 5);
        Label label = new Label(labelText);
        label.WidthRequest = 140;
        label.Xalign = 0;

        Entry entry = new Entry();
        hbox.PackStart(label, false, false, 0);
        hbox.PackStart(entry, true, true, 0);

        parent.PackStart(hbox, false, false, 0);
        return entry;
    }

    protected void OnAddBtnClicked(object sender, EventArgs e)
    {
        try
        {
            int number = int.Parse(numberEntry.Text);
            string name = nameEntry.Text;
            int size = int.Parse(sizeEntry.Text);
            string date = dateEntry.Text;
            int godnost = int.Parse(godnostEntry.Text);

            DataSent?.Invoke(number, name, size, date, godnost);

            numberEntry.Text = "";
            nameEntry.Text = "";
            sizeEntry.Text = "";
            dateEntry.Text = "";
            godnostEntry.Text = "";

            this.Hide();
        }
        catch (Exception)
        {
            MessageDialog md = new MessageDialog(this, DialogFlags.Modal, MessageType.Error, ButtonsType.Ok, "Ошибка ввода данных: проверьте форматы чисел.");
            md.Run();
            md.Destroy();
        }
    }
}