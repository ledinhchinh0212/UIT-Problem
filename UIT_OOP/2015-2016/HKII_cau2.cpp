#include <iostream>

using namespace std;

class Time {
private:
    int seconds;
public:
    friend istream &operator>> (istream in, Time &time);
    friend ostream &operator<< (ostream out, const Time &time);
    Time operator++();
    Time operator++(int);
};

istream &operator>> (istream in, Time &time) {
    int hours, minutes, seconds;
    hours = minutes = seconds = 0;
    in >> hours >> minutes >> seconds;
    time.seconds = hours * 3600 + minutes * 60 + seconds;
    return in;
}

ostream &operator<< (ostream out, const Time &time) {
    int hours = time.seconds / 3600;
    int minutes = (time.seconds % 3600) / 60;
    int seconds = time.seconds % 60;
    cout << hours << ":" << minutes << ":" << seconds;

    return out;
}

Time Time::operator++() {
    this->seconds++;
    return *this;
}

Time Time::operator++(int) {
    Time ret = *this;
    ret.seconds++;
    return ret;
}

int main() {

    return 0;
}