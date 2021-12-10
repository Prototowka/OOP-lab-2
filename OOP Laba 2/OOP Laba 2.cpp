#include <iostream>
#include <locale>

using namespace std;

struct info
{
	char nositel[20];
	int size;
	char name[30];
	char vender[30];
};

struct info infos[30];
struct info buffer;
int records = 0, i, j, max_records, select, count;
void enter(), out(), del(), change(), find(), sortirovka();

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Введите максимальное кол-во записей" << endl;
	cin >> max_records;
	while (1)
	{
		cout << "------------------------" << endl;
		cout << "1-Добавление записи" << endl;
		cout << "2-Вывод записи" << endl;
		cout << "3-Удаление записи" << endl;
		cout << "4-Изменение записи" << endl;
		cout << "5-Поиск записей" << endl;
		cout << "6-Сортировка записей" << endl;
		cout << "7-Выход" << endl;
		cout << "------------------------" << endl;
		cin >> select;
		switch (select)
		{
			case 1:enter(); break;
			case 2:out(); break;
			case 3:del(); break;
			case 4:change(); break;
			case 5:find(); break;
			case 6:sortirovka(); break;
			case 7:return 0; break;
		}
	}
}

void enter()//Ввод
{
	if (records < max_records)
	{
		cout << "Запись №" << records + 1 << endl;
		cout << "Тип носителя:" << endl;
		cin >> infos[records].nositel;
		cout << "Объем:" << endl;
		cin >> infos[records].size;
		cout << "Название:" << endl;
		cin >> infos[records].name;
		cout << "Производитель:" << endl;
		cin >> infos[records].vender;
		records++;
	}
	else
	{
		cout << "------------------------" << endl;
		cout << "Введено максимальное кол-во записей" << endl;
		cout << "------------------------" << endl;
	}
}

void out()//Вывод
{
	if (records == 0)cout << "Нет записей" << endl;
	else
	{
		cout << "------------------------" << endl;
		cout << "1-Вывести все записи" << endl;
		cout << "2-Вывести запись под определенным номером" << endl;
		cout << "------------------------" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			for (i = 0; i < records; i++)
			{
				cout << "------------------------" << endl;
				cout << "Запись №" << i + 1 << endl;
				cout << "Тип носителя:" << infos[i].nositel << endl;
				cout << "Объем:" << infos[i].size << endl;
				cout << "Название:" << infos[i].name << endl;
				cout << "Производитель:" << infos[i].vender << endl;
				cout << "------------------------" << endl;
			}
			break;
		case 2:
			cout << "Введите номер записи" << endl;
			cin >> i;
			cout << "------------------------" << endl;
			cout << "Запись №" << i << endl;
			cout << "Тип носителя:" << infos[i-1].nositel << endl;
			cout << "Объем:" << infos[i-1].size << endl;
			cout << "Название:" << infos[i-1].name << endl;
			cout << "Производитель:" << infos[i-1].vender << endl;
			cout << "------------------------" << endl;
			break;
		}
	}
}

void del()//Удаление
{
	cout << "------------------------" << endl;
	cout << "Введите номер записи для удаления" << endl;
	cout << "Для удаления всех записей ввести 0" << endl;
	cout << "------------------------" << endl;
	cin >> select;
	if (select != 0)
	{
		for (i = select - 1; i < records; i++)
			infos[i] = infos[i + 1];
		records = records - 1;
		cout << "------------------------" << endl;
		cout << "Удаление завершено" << endl;
		cout << "------------------------" << endl;
	}
	if (select == 0)
	{
		for (i = 0; i < records; i++)
			infos[i] = buffer;
		records = 0;
		cout << "------------------------" << endl;
		cout << "Удаление завершено" << endl;
		cout << "------------------------" << endl;
	}
}

void change()//Изменение
{
	cout << "------------------------" << endl;
	cout << "Введите номер записи" << endl;
	cout << "------------------------" << endl;
	cin >> i;
	cout << "------------------------" << endl;
	cout << "Тип носителя:" << infos[i - 1].nositel << endl;
	cout << "Объем:" << infos[i - 1].size << endl;
	cout << "Название:" << infos[i - 1].name << endl;
	cout << "Производитель:" << infos[i - 1].vender << endl;
	cout << "------------------------" << endl;
	cout << "------------------------" << endl;
	cout << "0-Изменить всю запись" << endl;
	cout << "1-Изменить тип носителя" << endl;
	cout << "2-Изменить объем" << endl;
	cout << "3-Изменить название" << endl;
	cout << "4-Изменить производителя" << endl;                                                                                  
	cout << "------------------------" << endl;
	cin >> select;
	switch (select)
	{
	case 0:
		cout << "Запись №" << i << endl;
		cout << "Тип носителя:" << endl;
		cin >> infos[i - 1].nositel;
		cout << "Объем:" << endl;
		cin >> infos[i - 1].size;
		cout << "Название:" << endl;
		cin >> infos[i - 1].name;
		cout << "Производитель:" << endl;
		cin >> infos[i - 1].vender;
		break;
	case 1:
		cout << "Введите новый тип носителя" << endl;
		cin >> infos[i - 1].nositel;
		break;
	case 2:
		cout << "Введите новый объем" << endl;
		cin >> infos[i - 1].size;
		break;
	case 3:
		cout << "Введите новое название" << endl;
		cin >> infos[i - 1].name;
		break;
	case 4:
		cout << "Введите нового производителя" << endl;
		cin >> infos[i - 1].vender;
		break;
	}
}

void find()//Поиск
{
	if (records == 0)
		cout << "Нет записей" << endl;
	else
	{
		cout << "------------------------" << endl;
		cout << "Варианты поиска:" << endl;
		cout << "1-Объем" << endl;
		cout << "------------------------" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "------------------------" << endl;
			cout << "Введите объем:" << endl;
			cout << "------------------------" << endl;
			cin >> j;
			for (i = 0; i < records; i++)
			{
				if (infos[i].size == j)
				{
					cout << "------------------------" << endl;
					cout << "Запись №" << i + 1 << endl;
					cout << "Тип носителя:" << infos[i].nositel << endl;
					cout << "Объем:" << infos[i].size << endl;
					cout << "Название:" << infos[i].name << endl;
					cout << "Производитель:" << infos[i].vender << endl;
					cout << "------------------------" << endl;
				}
			}
			break;
		}
	}
}

void sortirovka()//сортировка
{
	cout << "------------------------" << endl;
	cout << "Выберите тип сортировки:" << endl;
	cout << "1-Объем(возрастание)" << endl;
	cout << "2-Объем(убывание)" << endl;
	cout << "------------------------" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
		for (i = 0; i < records - 1; i++)
			for (j = 0; j < records - 1; j++)
				if (infos[j].size > infos[j + 1].size)
				{
					buffer = infos[j + 1];
					infos[j + 1] = infos[j];
					infos[j] = buffer;
				}
		break;
	case 2:
		for (i = 0; i < records - 1; i++)
			for (j = 0; j < records - 1; j++)
				if (infos[j].size < infos[j + 1].size)
				{
					buffer = infos[j + 1];
					infos[j + 1] = infos[j];
					infos[j] = buffer;
				}
		break;
	}
}