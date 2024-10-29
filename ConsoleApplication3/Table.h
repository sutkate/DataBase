#pragma once

#include "Car.h"
#include "IO.h"
#include "vector.h"
#include "myString.h"
#include <iostream>
class Table : public IO {
private:
    vec v;
    int cars;
    T* current;

public:
    Table(int car);
    ~Table();
    T* begin();
    T* end();
    int length() const;
    int getsize();
    T* insert(const T& item);
    T* erase(T* pos);
    void clear();
    int remove(const T& item);
    int find(const T& item);
    int replace(const T& OLD, const T& NEW);
    void bubblesort();
    T* begin() const;
    T* end() const;

    virtual int input(istream& Cin);
    virtual void output(ostream& Cout) const;
    virtual int input(ifstream& Fin);
    virtual void output(ofstream& Fout) const;

    friend ostream& operator<<(ostream& os, const Table& table);
    friend istream& operator>>(istream& is, Table& table);
};