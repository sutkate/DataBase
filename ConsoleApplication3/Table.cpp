#include "Table.h"

Table::Table(int _cars) : v(_cars), cars(_cars) { current = begin(); }
Table::~Table() { clear(); }
void Table::clear() { current = begin(); }

T* Table::begin() { return v.begin(); }
T* Table::end() { return current; }
T* Table::begin() const { return v.begin(); }
T* Table::end() const { return current; }

int Table::length() const { return current - begin(); }

int Table::getsize() { return v.getsize(); }

T* Table::insert(const T& item) 
{
    int prev = length();
    if (prev >= getsize()) 
    {
        v.resize(2 * length());
        current = begin() + prev;
    }
    *current++ = item->copy();
    return current;
}

T* Table::erase(T* pos) 
{
    if (pos < begin() || pos >= end()) return end();
    for (T* i = pos; i < end() - 1; ++i) *i = *(i + 1);
    current--;
    return pos;
}

int Table::remove(const T& item) 
{
    int n = 0;
    for (T* i = begin(); i < end(); ) 
    {
        if ((*i)->equal(*item)) 
        {
            erase(i);
            n++;
        }
        else ++i;
    }
    return n;
}

int Table::find(const T& item) 
{
    for (T* i = begin(); i < end(); ++i)  if ((*i)->equal(*item)) return i - begin();
    return -1;
}

int Table::replace(const T& OLD, const T& NEW) 
{
    int count = 0;
    for (T* i = begin(); i < end(); ++i) 
    {
        if ((*i)->equal(*OLD)) 
        {
            *i = NEW->copy();
            count++;
        }
    }
    return count;
}

void Table::bubblesort() { Car::bubblesort(begin(), length()); }

int Table::input(istream& Cin) 
{
    Car buf;
    int count = 0;
    while (buf.input(Cin)) 
    {
        insert(&buf);
        count++;
    }
    return count;
}

void Table::output(ostream& Cout) const 
{
    for (T* i = begin(); i != end(); ++i) (*i)->output(Cout);
}

int Table::input(ifstream& Fin) 
{
    clear();
    char buffer[100];
    Fin.getline(buffer, 100);
    int size = atoi(buffer);
    for (int i = 0; i < size; i++) 
    {
        Car buf;
        buf.input(Fin);
        insert(&buf);
    }
    return 1;
}

void Table::output(ofstream& Fout) const 
{
    Fout << length() << endl;
    for (T* i = begin(); i != end(); ++i)  (*i)->output(Fout);
}
ostream& operator<<(ostream& os, const Table& table) 
{
    table.output(os);
    return os;
}
istream& operator>>(istream& is, Table& table) 
{
    table.input(is);
    return is;
}