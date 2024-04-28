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


int main() {

    Integer n = 5;
    Integer m = 6;
    cin >> n;
    cout << n << " " << m;

    return 0;
}