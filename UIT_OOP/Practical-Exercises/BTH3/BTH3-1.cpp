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
};

int main() {

    return 0;
}