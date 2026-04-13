//Задание 0.
//Вариант 15.
//Определить комбинированный(структурный) тип для представления информации
//по горным вершинам, состоящей из названия вершины, ее высоты, стране
//местонахождения, типе горы(вулканическая, складчатая, платообразная и др.).
//Ввести информацию по 20 вершинам.Вывести среднее значение высот всех 20
//вершин.Затем вывести информацию, отсортированную по убыванию высоты
//вершины(рационально переставлять все поля структуры разом).Вывести сведения
//по странам местонахождения 4 - х восьмитысячников.Реализовать функцию
//изменения данных горной вершины по ее названию.В отдельный массив поместить
//все горные вершины в одной стране(страну вводить с клавиатуры).Реализовать
//вывод отфильтрованных данных в виде оберточной функции.

//Задание 1
//Считать из текстового файла данные числового поля для вашей.
//Уточнение. Файл состоит из 3 признаков: название ГОРЫ, ВЫСОТА, СТРАНА (именно в этом порядке и считывается)

//Задание 2. 
//Сделать чтение / запись своей структуры в бинарный файл.
//Оформить в виде подпрограмм.



#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;
typedef const char* cstr;
typedef const int cint;


cint S = 20;


enum type {
	Vulkane,
	Platoobraznaia,
	Skladchataia
};
struct set_chars {
	char name[20];
	char country[20];
	type Type;
};
struct mountain {
	set_chars Chars;
	int h;
};

//Используемые функции
void print_step(mountain& Gory);
void printl(char a[][20], int k);
cstr type_to_str(type a);
type str_to_type(char* a);
void print(mountain* Gory);
void sr_z(mountain* Gory);
void puz(mountain* Gory);
void eight(mountain* Gory);
int find_mount(mountain* a, cstr str);
void change(mountain& a);
void replace(mountain* a);
void find_country(mountain* a, void printl(char a[][20], int k));
void change(mountain& a, int b, cstr c);
void read_file(mountain* a);
void bin_file_out(mountain* a);
void bin_file_in();



int main() {
	setlocale(LC_ALL, "");
	mountain Gory[S];
	Gory[0] = { "Dgamaluga", "India", Vulkane, 8067 };
	Gory[1] = { "Natasha",  "Russia", Platoobraznaia ,8809 };
	Gory[2] = { "Supera", "China", Skladchataia , 1000 };
	Gory[3] = { "Russkaia", "Russia",Vulkane , 1488 };
	Gory[4] = { "Denik", "USA", Skladchataia , 876 };
	Gory[5] = { "Kallokvium", "Matanalize", Platoobraznaia , 300 };
	Gory[6] = { "Daty", "Belorus", Vulkane , 548 };
	Gory[7] = { "Kirkorov", "USA", Vulkane , 1145 };
	Gory[8] = { "Bashov", "Russia", Platoobraznaia , 3898 };
	Gory[9] = { "Telegram", "Brazil", Skladchataia, 666 };
	Gory[10] = { "Krootaia", "France", Platoobraznaia , 8124 };
	Gory[11] = { "Russo", "Engliand", Skladchataia , 1234 };
	Gory[12] = { "ZnakChety", "Cheta", Vulkane , 8997 };
	Gory[13] = { "Mr.Tse", "Cheta", Skladchataia , 1240 };
	Gory[14] = { "Keke", "France", Platoobraznaia , 8355 };
	Gory[15] = { "Lelele", "USA", Skladchataia , 2004 };
	Gory[16] = { "Saproniyat", "USA", Vulkane , 579 };
	Gory[17] = { "Rustem", "USA", Skladchataia, 1645 };
	Gory[18] = { "KingSneg", "France", Platoobraznaia , 124 };
	Gory[19] = { "Fefe", "China", Skladchataia , 765 };

	print(Gory);
	sr_z(Gory);
	puz(Gory);
	eight(Gory);
	replace(Gory);
	find_country(Gory, printl);
	read_file(Gory);
	bin_file_out(Gory);

	return 0;
}
void printl(char a[][20], int k) {
	cout << "\t\tВсе горные веришны в искомой стране:\n";
	for (int i = 0; i < k; ++i) {
		cout << i + 1 << " " << a[i] << endl;
	}
}
void print(mountain* Gory) {
	for (int i = 0; i < S; ++i) {
		print_step(Gory[i]);
	}
}
cstr type_to_str(type a) {
	switch (a) {
	case Vulkane: return "Vulkane";
	case Platoobraznaia: return "Platoobraznaia";
	case Skladchataia: return "Skladchataia";
	}
	return "  ";
}
type str_to_type(char* a) {
	if (strcmp(a, "Vulkane") == 0) return Vulkane;
	if (strcmp(a, "Platoobraznaia") == 0) return Platoobraznaia;
	if (strcmp(a, "Skladchataia") == 0) return Skladchataia;
	return Vulkane;
}
void print_step(mountain& Gory) {
	cout << Gory.Chars.name << " " << Gory.Chars.country << " " << type_to_str(Gory.Chars.Type) << " " << Gory.h << endl;
}
void sr_z(mountain* Gory) {
	cout << "////////////" << endl << "Ср.знач. для гор:";
	int sum = 0;
	for (int i = 0; i < S; ++i) {
		sum = sum + Gory[i].h;
	}
	cout << (float)sum / S << endl;
}
void puz(mountain* Gory) {
	cout << "\n\n" << "Пузырек" << "\n\n";
	for (int i = 0; i < S - 1; ++i) {
		for (int j = 0; j < S - 1 - i; ++j) {
			if (Gory[j].h < Gory[j + 1].h) {
				mountain z = Gory[j];
				Gory[j] = Gory[j + 1];
				Gory[j + 1] = z;
			}
		}
	}
	print(Gory);
}
void eight(mountain* Gory) {
	cout << "\n\nСтраны с восьмитысячниками\n" << endl;
	int flag = 1, i = 0;
	while (flag != 5 && i < S) {
		if (Gory[i].h > 8000) {
			cout << flag << " " << (Gory[i].Chars.country) << endl;
			++flag;
		}
		i++;
	}
	if (flag < 5) cout << "///////\nВ списке больше нет гор, больше 8000 м" << endl;
}
int find_mount(mountain* a, cstr str) {
	for (int j = 0; j < S; ++j) {
		if (strcmp(a[j].Chars.name, str) == 0) return j;
	}
	return -1;

}
void change(mountain& a) {
	cout << "Изменение данных:\n\t\t";
	cout << "Страна\n\t\t";
	cin >> a.Chars.country;
	cout << "Высота (В ЧИСЛАХ)\n\t\t";
	cin >> a.h;
	char name_type[20];
	cout << "Тип (если был введен не верный тип - гора будет иметь тип Vulkane)\n\t\t";
	cin >> name_type;
	a.Chars.Type = str_to_type(name_type);
	print_step(a);
}
void replace(mountain* a) {
	cout << "\n\n\n////////////\nИзменение данных  для каждой горы" << endl;
	cout << "Сколько нужно вершин изменить?\nВвод: число от 0 и до 5 включительно (больше много)" << endl;
	int i = 0;
	scanf_s("%i", &i);
	if (i < 0 || i > 5) {
		cout << "Введено число, большее ограничения. Берется остаток от деления этого абсолютного числа на 5:" << i << " = ";
		i = abs(i) % 5;
		cout << i << endl;
	}
	int j = 0;
	int searchnum = 0;
	while (j < i) {
		char str[20];
		cout << "\t\tВведите название интересующей горы :" << "\n\t\t";
		cin >> str;
		searchnum = find_mount(a, str);
		if (searchnum != -1) {
			change(a[searchnum]);
			++j;
		}
		else cout << "Такой вершины нет" << endl;
	}
}
void find_country(mountain* a, void y(char a[][20], int k)) {
	char str[20];
	cout << "\n\n/////////\nВсе горные вершины страны.\nВведите искомую страну:\t";
	cin >> str;
	int k = 0;
	char array[S][20];
	for (int i = 0; i < S; ++i) {
		if (strcmp(str, a[i].Chars.country) == 0) {
			strcpy_s(array[k], a[i].Chars.name);
			++k;
		}
	}
	if (k == 0)cout << "\nТакой страны не существует" << endl;
	else y(array, k);
}


void change(mountain& a, int b, cstr c) {
	a.h = b;
	strcpy_s(a.Chars.country, c);
}
void read_file(mountain* a) {

	cout << "\n\n\t\tДо ввывода из текстового файла:" << endl;
	print(a);
	ifstream fin;
	string str[3];
	int search_num = 0;
	fin.open("Gory.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> str[0] >> str[1] >> str[2];
			search_num = find_mount(a, str[0].c_str());
			if (search_num != -1) {
				change(a[search_num], stoi(str[1]), str[2].c_str());
			}
		}
	}
	cout << "\n\n\t\tПосле ввывода из текстового файла: " << endl;
	print(a);
}
void bin_file_in() {
	mountain Gore[20];
	cout << "\n\n\n\n\nЧТЕНИЕ ИЗ БИНАРНОГО ФАЙЛА" << endl;
	fstream in("test.bin", ios::binary | ios::in);
	for (int i = 0; i < S; ++i) { in.read((char*)&Gore[i], sizeof(Gore[i])); }
	in.close();
	print(Gore);
}
void bin_file_out(mountain* a) {
	cout << "\n\n\n\n\nЗАПИСЬ В БИНАРНЫЙ ФАЙЛ" << endl;
	ofstream out("test.bin", ios::binary | ios::out);
	for (int i = 0; i < S; ++i) { out.write((char*)&a[i], sizeof(a[i])); }
	out.close(); //Закрываем открытый файл
	cout << "УСПЕШНО" << endl;
	bin_file_in();
}
