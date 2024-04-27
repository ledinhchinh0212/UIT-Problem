#include <iostream>

using namespace std;

class Time {
private:
    int gio, phut, giay;
public:
    Time();
    Time(int gio, int phut, int giay);
    friend istream &operator>>(istream &in, Time &time);
    friend ostream &operator<<(ostream &out, const Time &time);
    Time operator++();
    Time operator++(int);
};

Time::Time() : gio(1), phut(1), giay(1) {}

Time::Time(int gio, int phut, int giay) {
    this->gio = gio;
    this->phut = phut;
    this->giay = giay;
}

istream &operator>>(istream &in, Time &time) {
    in >> time.gio >> time.phut >> time.giay;
    return in;
}

ostream &operator<<(ostream &out, const Time &time) {
    cout << time.gio << ":" << time.phut << ":" << time.giay;
    return out;
}

Time Time::operator++() {
    if(giay == 59) {
        giay = 0;
        if(phut == 59) {
            phut = 0;
            gio++;
        }
        else {
            phut++;
        }
    }
    else {
        giay++;
    }
    return *this;
}

Time Time::operator++(int) {
    return ++*this;
}

int main() {

    Time time;
    cin >> time;
    time++;
    cout << time;

    return 0;
}