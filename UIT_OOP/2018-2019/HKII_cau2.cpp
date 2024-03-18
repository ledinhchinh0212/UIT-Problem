#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minute;
    int second;
public:
    friend istream &operator>>(istream &in, Time &time) {
        in >> time.hours;
        in >> time.minute;
        in >> time.second;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Time &time) {
        out << time.hours << ":" << time.minute << ":" << time.second << "\n";
        return out;
    }

    Time &operator++(int) {
        if(second == 59) {
            if(minute ==  59) {
                hours++;
                minute = second = 0;
            }
            else {
                minute++;
                second = 0;
            }
        }
        else {
            second++;
        }

        return *this;
    }
};

int main() {

    Time time;
    cin >> time;
    time++;
    cout << time;

    return 0;
}