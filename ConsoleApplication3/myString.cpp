#define _CRT_SECURE_NO_WARNINGS
#include "myString.h"
#include <cstring>
#include <cstdio>

MyString::MyString() : s(new char[1]), len(0) {
    s[0] = '\0';
}

MyString::MyString(const char* t) : len(strlen(t)), s(new char[len + 1]) {
    strcpy(s, t);
}

MyString::MyString(const MyString& u) : len(u.len), s(new char[len + 1]) {
    strcpy(s, u.s);
}

MyString::~MyString() {
    delete[] s;
}

MyString& MyString::operator=(const MyString& rhs) {
    if (this != &rhs) {
        delete[] s;
        len = rhs.len;
        s = new char[len + 1];
        strcpy(s, rhs.s);
    }
    return *this;
}

char& MyString::item(int index) {
    if (index >= 0 && index < len) {
        return s[index];
    }
    cout << "ERROR: Index out of range" << endl;
    static char err = '\0';
    return err;
}

void MyString::assign(const char* newString) {
    if (s)
        delete[] s;
    len = strlen(newString);
    s = new char[len + 1];
    strcpy(s, newString);
}
const char* MyString::c_str() const {
    return s; 
}
int MyString::cmp(const MyString& t) const {
    return strcmp(s, t.s);
}

int MyString::equal(const MyString& t) const {
    return strcmp(s, t.s) == 0;
}

int MyString::input(istream& in) {
    char buffer[1024];
    if (in.getline(buffer, 1024)) {
        assign(buffer);
        return 1;
    }
    return 0;
}

void MyString::output(ostream& out) const {
    out << s;
}

int MyString::input(ifstream& in) {
    return input(static_cast<istream&>(in));
}

void MyString::output(ofstream& out) const {
    out << s;
}

MyString* MyString::copy() {
    return new MyString(*this);
}
ostream& operator<<(ostream& os, const MyString& obj) {
    obj.output(os);
    return os;
}
istream& operator>>(istream& is, MyString& obj) {
    obj.input(is);
    return is;
}

ifstream& operator>>(ifstream& is, MyString& obj) {
    obj.input(is);
    return is;
}