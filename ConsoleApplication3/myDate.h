#pragma once
#include <iostream>
#include <fstream>
#include "IO.h"

class MyDate : public IO {
private:
    int day, month, year;
    static int daytab[2][13];
    static const char* MonthName[13];
    static const char* DayNames[8];

public:
    MyDate();
    MyDate(int d, int m, int y);
    MyDate(const MyDate& k);
    ~MyDate();

    int get_day() const;
    int get_month() const;
    int get_year() const;

    void set_day(int d);
    void set_month(int m);
    void set_year(int y);

    void AddDays(int d);
    void AddMonths(int m);
    void AddYears(int y);

    static int vis(int y);
    int validate();

    void assign(const MyDate& t);
    MyDate* copy();
    int equal(const MyDate& t) const;
    int cmp(const MyDate& t);

    virtual int input(istream& in);
    virtual void output(ostream& out) const;
    virtual int input(ifstream& in);
    virtual void output(ofstream& out) const;
    long get_AllDays() const;

    friend ostream& operator<<(ostream& os, const MyDate& date);
    friend ofstream& operator<<(ofstream& os, const MyDate& date);
    friend istream& operator>>(istream& is, MyDate& date);
    friend ifstream& operator>>(ifstream& is, MyDate& date);

    MyDate operator+(const MyDate& other) const;
    MyDate operator-(const MyDate& other) const;
    MyDate& operator+=(const MyDate& other);
    MyDate& operator-=(const MyDate& other);
};
