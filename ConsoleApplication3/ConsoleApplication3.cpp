#define _crt_secure_no_warnings
#include "Car.h"
#include "Table.h"
#include <fstream>
#include <limits>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Введите кол-во автомобилей: ";
	int amount = 0;
	while (amount <= 0) { cin >> amount; cout << endl; }
	Table table(amount);
	MyString filename;
	int choice = -1; 
	char buf[256]{};
	while (choice != 0)
	{
		cout << "1. Ввести характеристики\n"
			 << "2. Вывести список автомобилей\n"
			 << "3. Загрузка из файла\n"
			 << "4. Сохранение в файл\n"
			 << "5. Найти автомобиль по характеристикам\n"
			 << "6. Удалить авто по индексу\n"
			 << "7. Удалить авто по характеристикам\n"
			 << "8. Заменить авто\n"
			 << "9. Сортировка списка\n"
			 << "0. Выйти из программы\n";
		cin >> choice; 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice)
		{
		case 1:
		{
			Car buf{}; cin >> buf;
			table.insert(new Car(buf));
			cin.clear();
			break;
		}
		case 2:
		{
			cout << table;
			cin.clear();
			break;
		}
		case 3: {
			cout << "Введите имя файла для загрузки: ";
			cin.getline(buf, sizeof(buf));
			filename.assign(buf);
			ifstream file(filename.c_str());  // Используем c_str() для конвертации MyString в const char*
			if (file) {
				table.input(file);
				cout << "Данные успешно загружены из файла." << endl;
			}
			else {
				cout << "Не удалось открыть файл для чтения." << endl;
			}
			break;
		}
		case 4: {
			cout << "Введите имя файла для сохранения: ";
			cin.getline(buf, sizeof(buf));
			filename.assign(buf);
			ofstream file(filename.c_str());
			if (file) {
				table.output(file);
				cout << "Данные успешно сохранены в файл." << endl;
			}
			else {
				cout << "Не удалось открыть файл для записи." << endl;
			}
			break;
		}
		case 5:
		{
			cout << "Введите характеристики: \n";
			Car car; cin >> car;
			int index = table.find(&car);
			if (index != -1) {
				cout << "Автомобиль найден на позиции: " << index << endl;
			}
			else {
				cout << "Автомобиль не найден." << endl;
			}
			break;
		}
		case 6:
		{
			int position;
			cout << "Введите индекс: "; cin >> position;
			table.erase(table.begin() + position);
			break;
		}
		case 7:
		{
			cout << "Введите характеристики" << endl;
			Car car;
			cin >> car;
			int index = table.find(&car);
			if (index == 0) cout << endl << "Ничего не найдено" << endl;
			else cout << endl << "Успешно" << endl;
			break;
		}
		case 8: {
			Car old_car, new_car;
			cout << "Введите данные автомобиля:" << endl;
			cin >> old_car;
			getchar();
			cout << "Введите данные нового автомобиля:" << endl;
			cin >> new_car;
			if (table.replace(&old_car, &new_car) > 0) {
				cout << "Автомобиль успешно заменен." << endl;
			}
			else {
				cout << "Автомобиль не найден." << endl;
			}
			break;
		}
		case 9: {
			table.bubblesort();
			cout << "Данные отсортированы." << endl;
			break;
		}
		default:
		{
			cout << "Выход" << endl;
			break;
		}
		}
	}
}