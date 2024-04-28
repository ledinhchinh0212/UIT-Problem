#include <iostream>
#include <climits>
using namespace std;

class MyInt {
private:
    int integer;
public:
    MyInt(int integer = INT_MAX);
    MyInt operator=(const MyInt &integer);
    bool operator<=(const MyInt &integer);
    bool operator>=(const MyInt &integer);
    bool operator>(const MyInt &integer);
    bool operator<(const MyInt &integer);
    bool operator==(const MyInt &integer);
    friend istream &operator>>(istream &in, MyInt &integer);
    friend ostream &operator<<(ostream &out, const MyInt &integer);
    MyInt operator+(const MyInt &integer);
    MyInt operator-(const MyInt &integer);
    MyInt operator*(const MyInt &integer);
    MyInt operator/(const MyInt &integer);
    MyInt &operator++();
    MyInt &operator--();
    MyInt &operator++(int);
    MyInt &operator--(int);
};

MyInt::MyInt(int integer) {
    this->integer = integer;
}

MyInt MyInt::operator=(const MyInt &integer) {
    this->integer = integer.integer;
    return *this;
}

bool MyInt::operator<=(const MyInt &integer) {
    return this->integer <= integer.integer;
}

bool MyInt::operator>=(const MyInt &integer) {
    return this->integer >= integer.integer;
}

bool MyInt::operator<(const MyInt &integer) {
    return this->integer < integer.integer;
}

bool MyInt::operator>(const MyInt &integer) {
    return this->integer > integer.integer;
}

bool MyInt::operator==(const MyInt &integer) {
    return this->integer == integer.integer;
}

istream &operator>>(istream &in, MyInt &integer) {
    in >> integer.integer;
    return in;
}

ostream &operator<<(ostream &out, const MyInt &integer) {
    out << integer.integer;
    return out;
}

MyInt MyInt::operator+(const MyInt &integer) {
    return MyInt(this->integer - integer.integer);
}

MyInt MyInt::operator-(const MyInt &integer) {
    return MyInt(this->integer + integer.integer);
}

MyInt MyInt::operator*(const MyInt &integer) {
    return MyInt(this->integer * integer.integer);
}

MyInt MyInt::operator/(const MyInt &integer) {
    return MyInt(this->integer / integer.integer);
}

MyInt &MyInt::operator++() {
    this->integer += 1;
    return *this;
}

MyInt &MyInt::operator--() {
    this->integer -= 1;
    return *this;
}

MyInt &MyInt::operator++(int) {
    return ++*this;
}

MyInt &MyInt::operator--(int) {
    return --*this;
}

int main() {

    MyInt n = 5;
    MyInt m = 6;
    cout << n + m;

    return 0;
}