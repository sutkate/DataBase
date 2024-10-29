#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class IO {
public:
    virtual int input(istream& Cin = cin) = 0;
    virtual void output(ostream& Cout = cout) const = 0;
    virtual int input(ifstream& Fin) = 0;
    virtual void output(ofstream& Fout) const = 0;
    friend ostream& operator<<(ostream&, const IO&); // оператор вывода (заменяет output())
    friend istream& operator>>(istream&, IO&);// оператор ввода (заменяет input()) 
};