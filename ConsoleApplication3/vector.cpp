#include "vector.h" 
#include <iostream> 
using namespace std;
vec::vec() {
	v = new T[size = 10];
}

vec::vec(int sz) {
	v = new T[size = sz];
}
vec::vec(const vec& w)
{
	v = new T[size = w.size];
	for (int i = 0; i < size; i++) {
		v[i] = w.v[i];
	}

}
vec::~vec() {
	delete[]v;
}

T& vec::item(int i) {
	if (i < 0 && i >= size) {
		cout << "Index Error";
		exit(1);
	}
	return v[i];
}

void vec::resize(int n) {
	T* t = new T[size + n];
	for (int i = 0; i < size; i++) {
		t[i] = v[i];
		delete[] v;
		v = t;
		size += n;

	}

}

void vec::assign(const vec& t) {
	if (size == t.size) {
		for (int i = 0; i < size; i++) {
			v[i] = t.v[i];

		}
	}
	else {
		cout << "Size Error";
		exit(1);
	}
}

T& vec::operator[](int index) {
	if (index < 0 || index >= size) {
		cout << "Index out of range";
		return v['/0'];
	}
	return v[index];
}
vec& vec::operator=(const vec& w) {
	if (this != &w) { // Защита от самоприсваивания
		delete[] v; // Освобождаем существующий массив

		size = w.size;
		v = new T[size]; // Создаем новый массив

		for (int i = 0; i < size; ++i) {
			v[i] = w.v[i]; // Копируем элементы
		}
	}
	return *this;
}