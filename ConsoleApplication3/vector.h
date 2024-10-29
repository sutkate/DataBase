#pragma once
#include "Car.h"
#include <iostream> 
using namespace std;
class vec {
private:
	T* v;
	int size;
public:
	T* begin() const { return v; }
	T* end() const { return v + size; }
	int getsize() { return size; }
	vec();
	vec(int sz);
	vec(const vec&);
	~vec();
	T& item(int l);
	void resize(int);
	void assign(const vec& t);
	T& operator[](int index);
	vec& operator=(const vec& w);
};