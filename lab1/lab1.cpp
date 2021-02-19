#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstring>
#include<stdio.h>
#include<ctime>
#include<utility>
#include<vector>
#include<array>

#define N 30
#define str_sz 15

using namespace std;

int k = 0, mn = 0, j = 0, sz = 0;

string sc[str_sz] = { "A","B","C","D","E","F","G","H","I","J" };
float apprWeight[str_sz] = { 32,1.25,0.2,0.03,3.45,1.93,5.82,9.83, 7.52, 4.62 };
float percent[str_sz] = { 0.00002,0.03,73.2,2.2,2.9,4.81,99.9,81.2, 0.002, 98.1 };
unsigned long long numberOfStars[str_sz] = {55000,12000000000, 293000000000,55000000000, 120391278, 9213218321, 12832138, 21932173, 2198321, 371123  };

struct Space{
	char sc[str_sz];
	float percent, apprWeight;
	unsigned long long numberOfStars;
};
struct Space ms[N], x;

void random_filling(Space);
void keyboard_filling(Space);
void outputting(Space, int);
void sorting(Space, int);

void random_filling(Space* ms) {
	srand(time(0));
	int size = rand() % 7 + 1;
	cout << "Количество элементов: " << size << endl;
	pair<int, bool>mean[str_sz];
	for (int i = 0; i < size; ++i) {
		mean[i].first = i;
		mean[i].second = false;
	}
	for (int h = 0; h < size; ++h) {
		int r;
		r = rand() % 8;
		while (mean[r].second)
			r = rand() % 8;
		mean[r].second = true;
		char temp[str_sz];
		for (int i = 0; i < str_sz; ++i)
			temp[i] = '\0';
		string ss;
		ss.clear();
		int str_size = ms[r].size();
		ss = ms[r];
		for (int i = 0; i < str_size; ++i)
			temp[i] = ss[i];
		ss.clear();
		strcpy(ms[h].sc, temp);
		ms[h].sc = sc[r];
		ms[h].temperature = temperatures[r];
		el[h].viscosity = viscosities[r];
	}
	cout << "Структура заполнена" << endl;
	sz = size;
}

void keyboard_filling(Space* ms ) {
	int size = 0;
	for (int i = 0; i < 10; ++i) {
		cout << i + 1 << ". Введите вещество, атомный номер, температуру (град.С) и вязкость (кг/м*сек)> ";

		cin >> ms[i].sc;
		if (!strcmp(ms[i].sc, "***")) break;
		cin >> ms[i].apprWeight >> ms[i].percent >> ms[i].numberOfStars;
		size++;
	}
	sz = size;
}

void outputting(Space* ms, int size) {
	printf("-------------------------------------------------------------------------------\n");
	printf("| Вязкость металлов в жидком состоянии                                        |\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("| Вещество  | Атомный номер   | Температура (град.С)  | Вязкость (кг/м*сек)   |\n");

	for (int i = 0; i < size; ++i) {
		printf("|-----------|-----------------|-----------------------|-----------------------|\n");
		printf("| %9s | %-16d| %-22d| %-22.2f|\n", el[i].name, el[i].num, el[i].temperature, el[i].viscosity);
	}
	printf("|-----------------------------------------------------------------------------|\n");
	printf("| Примечание: данные даны для температуры плавления                           |\n");
	printf("-------------------------------------------------------------------------------\n\n\n");
}

void sorting(element* el, int size) {
	for (int i = 0; i < size; ++i) {
		mn = i;
		for (j = i + 1; j < size; ++j)
			if (strcmp(el[mn].name, el[j].name) > 0)mn = j;
		if (mn > i) {
			strcpy(x.name, el[i].name);
			x.num = el[i].num;
			x.temperature = el[i].temperature;
			x.viscosity = el[i].viscosity;
			strcpy(el[i].name, el[mn].name);
			el[i].num = el[mn].num;
			el[i].temperature = el[mn].temperature;
			el[i].viscosity = el[mn].viscosity;
			strcpy(el[mn].name, x.name);
			el[mn].num = x.num;
			el[mn].temperature = x.temperature;
			el[mn].viscosity = x.viscosity;
		}
	}
	cout << endl << "Структура отсортирована" << endl << endl;
}

int main() {

	int checker;

	while (true) {
		cout << "Выберите действие: " << endl;
		cout << "1. Заполнение структуры случайным образом" << endl;
		cout << "2. Заполнение структуры с клавиатуры"<<endl;
		cout << "3. Вывести структуру" << endl;
		cout << "4. Отсортировать структуру" << endl;
		cout << "5. Очистить консоль" << endl;
		cout << "Для выхода из программы введите 0" << endl << "> ";

		cin >> checker;

		if (checker < 0 || checker>5) {
			cout << "Введено неверное значение. Попробуйте ещё раз: ";
			continue;
		}

		if (checker == 0)
			return 0;
		if (checker == 1)
			random_filling(el);
		else if (checker == 2)
			keyboard_filling(el);
		else if (checker == 3)
			outputting(el, sz);
		else if (checker == 4)
			sorting(el, sz);
		else if (checker == 5)
			system("cls");
	}
}

