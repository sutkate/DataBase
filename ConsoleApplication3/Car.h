#pragma once
#include <iostream>
#include "myString.h"
#include "myDate.h"
#include "IO.h"
using namespace std;
class Car : public IO
{
private:

	MyString model_name;
	MyString company;
	unsigned short int mass;
	float price;
	MyDate date;
	
public:
	Car();
	Car(const Car& obj); // конструктор копирования
	~Car();

	virtual int input(istream& Cin);
	virtual void output(ostream& Cout) const;
	virtual int input(ifstream& Fin);
	virtual void output(ofstream& Fout) const;

	static int CMP(Car& car, Car& car1);
	static void bubblesort(Car** cars, int n);

	bool equal(const Car& other) const;
	Car* copy() const;

	friend ostream& operator<<(ostream& os, const Car& car);
	friend istream& operator>>(istream& is, Car& car);
	friend class Table;
};
typedef Car* T;
