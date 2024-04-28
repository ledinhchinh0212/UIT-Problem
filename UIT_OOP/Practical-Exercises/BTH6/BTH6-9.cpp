#include <iostream>
#include <climits>
using namespace std;

class Integer {
private:
    int integer;
public:
    Integer(int integer = INT_MAX);
    Integer operator=(const Integer &integer);
    bool operator<=(const Integer &integer);
    bool operator>=(const Integer &integer);
    bool operator>(const Integer &integer);
    bool operator<(const Integer &integer);
    bool operator==(const Integer &integer);
    friend istream &operator>>(istream &in, Integer &integer);
    friend ostream &operator<<(ostream &out, const Integer &integer);
    Integer operator+(const Integer &integer);
    Integer operator-(const Integer &integer);
    Integer operator*(const Integer &integer);
    Integer operator/(const Integer &integer);
    Integer &operator++();
    Integer &operator--();
    Integer &operator++(int);
    Integer &operator--(int);
};

Integer::Integer(int integer) {
    this->integer = integer;
}

Integer Integer::operator=(const Integer &integer) {
    this->integer = integer.integer;
    return *this;
}

bool Integer::operator<=(const Integer &integer) {
    return this->integer <= integer.integer;
}

bool Integer::operator>=(const Integer &integer) {
    return this->integer >= integer.integer;
}

bool Integer::operator<(const Integer &integer) {
    return this->integer < integer.integer;
}

bool Integer::operator>(const Integer &integer) {
    return this->integer > integer.integer;
}

bool Integer::operator==(const Integer &integer) {
    return this->integer == integer.integer;
}

istream &operator>>(istream &in, Integer &integer) {
    in >> integer.integer;
    return in;
}

ostream &operator<<(ostream &out, const Integer &integer) {
    out << integer.integer;
    return out;
}

Integer Integer::operator+(const Integer &integer) {
    return Integer(this->integer + integer.integer);
}

Integer Integer::operator-(const Integer &integer) {
    return Integer(this->integer - integer.integer);
}

Integer Integer::operator*(const Integer &integer) {
    return Integer(this->integer * integer.integer);
}

Integer Integer::operator/(const Integer &integer) {
    return Integer(this->integer / integer.integer);
}

Integer &Integer::operator++() {
    this->integer += 1;
    return *this;
}

Integer &Integer::operator--() {
    this->integer -= 1;
    return *this;
}

Integer &Integer::operator++(int) {
    return ++*this;
}

Integer &Integer::operator--(int) {
    return --*this;
}

int main() {

    Integer n = 5;
    Integer m = 6;
    cout << ++n << " " << m++ << "\n";
    cout << n << " " << ++m;

    return 0;
}