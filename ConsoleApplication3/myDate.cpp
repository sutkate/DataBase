#include "myDate.h"
#include <iostream>
#include <cstring>
#include <sstream>

// Статические члены класса
int MyDate::daytab[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
const char* MyDate::MonthName[13] = { "null", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const char* MyDate::DayNames[8] = { "null", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
int MyDate::validate() {
    return year > 0 && month > 0 && month <= 12 && day > 0 && day <= daytab[vis(year)][month];
}

// Конструкторы и деструктор
MyDate::MyDate() : day(0), month(0), year(0) {}
MyDate::MyDate(int d, int m, int y) : day(d), month(m), year(y) {
    if (!validate()) {
        cout << "Invalid date" << endl;
        day = month = year = 0;
    }
}
MyDate::MyDate(const MyDate& k) : day(k.day), month(k.month), year(k.year) {}
MyDate::~MyDate() {}

// Методы доступа
int MyDate::get_day() const { return day; }
int MyDate::get_month() const { return month; }
int MyDate::get_year() const { return year; }

// Методы модификации
void MyDate::set_day(int d) {
    int tmp = day;
    day = d;
    if (!validate()) day = tmp;
}
void MyDate::set_month(int m) {
    int tmp = month;
    month = m;
    if (!validate()) month = tmp;
}
void MyDate::set_year(int y) {
    int tmp = year;
    year = y;
    if (!validate()) year = tmp;
}

// Методы работы с датой
void MyDate::AddDays(int d) {
    if (d > 0) {
        while (d--) {
            day++;
            if (day > daytab[vis(year)][month]) {
                day = 1;
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
        }
    }
    else {
        while (d++) {
            day--;
            if (day < 1) {
                month--;
                if (month < 1) {
                    month = 12;
                    year--;
                }
                day = daytab[vis(year)][month];
            }
        }
    }
}

void MyDate::AddMonths(int m) {
    month += m;
    while (month > 12) {
        month -= 12;
        year++;
    }
    while (month < 1) {
        month += 12;
        year--;
    }
    if (day > daytab[vis(year)][month]) {
        day = daytab[vis(year)][month];
    }
}

void MyDate::AddYears(int y) {
    year += y;
}

// Проверка високосного года
int MyDate::vis(int y) {
    return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 1 : 0;
}

// Валидация даты

// Методы ввода-вывода
int MyDate::input(istream& in) {
    in >> day >> month >> year;
    return validate() ? 1 : 0;
}
long MyDate::get_AllDays() const {
    long totalDays = 0;
    // Считаем все полные годы до данного года.
    for (int i = 1; i < year; ++i) {
        totalDays += 365 + vis(i);  // Добавляем високосные года
    }
    // Считаем дни за месяцы текущего года.
    for (int i = 1; i < month; ++i) {
        totalDays += daytab[vis(year)][i];
    }
    // Добавляем дни текущего месяца.
    totalDays += day;

    return totalDays;
}

void MyDate::output(ostream& out) const {
    out << day << " " << MonthName[month] << " " << year << " (" << DayNames[(get_AllDays() % 7) + 1] << ")";
}

int MyDate::input(ifstream& in) {
    return input(static_cast<istream&>(in));
}

void MyDate::output(ofstream& out) const {
    out << day << " " << month << " " << year << endl;
}
// Оператор сложения даты с другой датой
MyDate MyDate::operator+(const MyDate& other) const {
    MyDate result(*this); // начинаем с текущей даты
    result.AddDays(other.day);
    result.AddMonths(other.month);
    result.AddYears(other.year);
    return result;
}

// Оператор вычитания даты из текущей даты
MyDate MyDate::operator-(const MyDate& other) const {
    MyDate result(*this); // начинаем с текущей даты
    result.AddDays(-other.day);
    result.AddMonths(-other.month);
    result.AddYears(-other.year);
    return result;
}

// Оператор добавления даты к текущей
MyDate& MyDate::operator+=(const MyDate& other) {
    this->AddDays(other.day);
    this->AddMonths(other.month);
    this->AddYears(other.year);
    return *this;
}

// Оператор вычитания даты из текущей
MyDate& MyDate::operator-=(const MyDate& other) {
    this->AddDays(-other.day);
    this->AddMonths(-other.month);
    this->AddYears(-other.year);
    return *this;
}

// Дружественный оператор вывода
ostream& operator<<(ostream& os, const MyDate& date) {
    const char* dayName = MyDate::DayNames[(date.get_AllDays() % 7) + 1];
    os << date.day << "-" << date.month << "-" << date.year << " (" << dayName << ")";
    return os;
}
ofstream& operator<<(ofstream& os, const MyDate& date) {
    os << date.day << " " << date.month << " " << date.year;
    return os;
}

// Дружественный оператор ввода
istream& operator>>(istream& is, MyDate& date) {
    is >> date.day >> date.month >> date.year;
    if (!date.validate()) {
        cout << "Invalid date entered." << endl;
        date.day = date.month = date.year = 0; // Сбросить дату при ошибке
    }
    return is;
}
ifstream& operator>>(ifstream& is, MyDate& date) {
    char buffer[100];
    char buffer2[100];
    is.getline(buffer, 100);
    stringstream stream{ buffer };
    stream.getline(buffer2, 100, ' ');
    date.day = atoi(buffer2);
    stream.getline(buffer2, 100, ' ');
    date.month = atoi(buffer2);
    stream.getline(buffer2, 100, ' ');
    date.year = atoi(buffer2);
    if (!date.validate()) {
        date.day = date.month = date.year = 0; // Сбросить дату при ошибке
    }
    return is;
}

int MyDate::equal(const MyDate& t) const {
    return (day == t.day && month == t.month && year == t.year);
}