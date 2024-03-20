#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;
public:
    friend istream &operator>>(istream &in, Time &time) {
        in >> time.hours;
        in >> time.minutes;
        in >> time.seconds;

        return in;
    }

    friend ostream &operator<<(ostream &out, const Time &time) {
        out << time.hours << ":" << time.minutes << ":" << time.seconds << "\n";

        return out;
    }

    void MinusSecondsTime() {
        if(seconds == 0) {
            if(minutes == 0) {
                hours--;
                minutes = 59;
            }
            else {
                minutes--;
            }
            seconds = 59;
        }
        else {
            seconds--;
        }
        if(hours < 0) {
            hours = minutes = seconds = 0;
        }
    }

    Time &operator--() {
        MinusSecondsTime();
        return *this;
    }

    Time &operator--(int) {
        MinusSecondsTime();
        return *this;
    }

};

int main() {

    Time time;
    cin >> time;
    --time;
    time--;
    cout << time;

    return 0;
}