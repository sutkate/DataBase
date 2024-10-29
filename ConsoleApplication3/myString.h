#pragma once
#include <iostream>
#include <fstream>
#include "IO.h"
using namespace std;
class MyString : public IO {
private:
    char* s = nullptr;
    int len;

public:
    MyString();
    MyString(const char* t);
    MyString(const MyString& u);
    ~MyString();
    const char* c_str() const;
    MyString& operator=(const MyString& rhs);
    MyString operator+(const MyString& rhs);
    MyString& operator+=(const MyString& rhs);

    char& item(int index);
    MyString* copy();
    void assign(const char* newString);
    int cmp(const MyString& t) const;
    int equal(const MyString& t) const;

    // Implementation of IO virtual methods
    virtual int input(istream& in);
    virtual void output(ostream& out) const;
    virtual int input(ifstream& in);
    virtual void output(ofstream& out) const;

    // Friends
    friend ostream& operator<<(ostream& os, const MyString& obj);
    friend istream& operator>>(istream& is, MyString& obj);
    friend ifstream& operator>>(ifstream& is, MyString& obj);
};
