#include "Car.h"
#include <sstream>

Car::Car() : mass(0), price(0.0) {}

Car::Car(const Car& other)
    : model_name(other.model_name), company(other.company), mass(other.mass),
    price(other.price), date(other.date) {}

Car::~Car() {}

int Car::input(istream& Cin) {
    cout << "Model name: ";
    model_name.input(Cin);

    cout << "Company name: ";
    company.input(Cin);

    cout << "Mass: ";
    Cin >> mass;
    Cin.ignore();

    cout << "Price: ";
    Cin >> price;
    Cin.ignore();

    cout << "Date: " << endl;
    date.input(Cin);
    return 1;
}

void Car::output(ostream& Cout) const {
    Cout << model_name << "\n";
    Cout << company << "\n";
    Cout << mass << "\n";
    Cout << price << "\n";
    Cout << date << "\n";
}

int Car::input(ifstream& Fin) {
    Fin >> model_name;
    Fin >> company;

    char buffer[100];
    char buffer2[100];
    Fin.getline(buffer, 100);
    mass = atoi(buffer);
    Fin.getline(buffer, 100);
    price = atof(buffer);

    Fin >> date;
    return 1;
}

void Car::output(ofstream& Fout) const {
    Fout << model_name << "\n";
    Fout << company << "\n";
    Fout << mass << "\n";
    Fout << price << "\n";
    Fout << date << "\n";
}

Car* Car::copy() const {
    return new Car(*this);
}

bool Car::equal(const Car& other) const {
    return model_name.equal(other.model_name) && company.equal(other.company) &&
        mass == other.mass && price == other.price &&
        date.equal(other.date);
}

istream& operator>>(istream& is, Car& car) {
    is.clear();
    cout << "Model name: ";
    is >> car.model_name;

    cout << "Company name: ";
    is >> car.company;

    cout << "Mass: ";
    is >> car.mass;

    cout << "Price: ";
    is >> car.price;

    cout << "Date: ";
    is >> car.date;
    return is;
}
void Car::bubblesort(Car** cars, int n) {
    // Пузырьковая сортировка
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Если элементы не в правильном порядке, меняем их местами
            if (CMP(*cars[j], *cars[j + 1]) > 0) {
                Car* temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }
}
int Car::CMP(Car& car1, Car& car2) {
	// Сравниваем по всем полям
	int model_name_comparison = car1.model_name.equal(car2.model_name);
	if (model_name_comparison != 0) {
		return model_name_comparison; // Если имена различны, возвращаем результат сравнения имен
	}
	// Сравниваем позиции
	int company_comparison = car1.company.equal(car2.company);
    if (company_comparison != 0) {
        return company_comparison; // Если позиции различны, возвращаем результат сравнения позиций
    }
	// Сравниваем возрасты
	if (car1.mass != car2.mass) {
		return car1.mass - car2.mass; // Если возрасты различны, возвращаем разницу между ними
	}

	// Сравниваем зарплаты
	if (car1.price != car2.price) {
		return car1.price < car2.price ? -1 : 1; // Если зарплаты различны, возвращаем -1 или 1 в зависимости от их относительного значения
	}



}