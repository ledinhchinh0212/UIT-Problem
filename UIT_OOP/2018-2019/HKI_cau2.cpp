#include <iostream>

using namespace std;

class CDate {
private:
    int day;
    int month;
    int year;
public:
    CDate(){
        this->day = 1;
        this->month = 1;
        this->year = 1;
    }

    CDate(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    friend istream &operator>>(istream &in, CDate &date) {
        in >> date.day;
        in >> date.month;
        in >> date.year;
        return in;
    }

    friend ostream &operator<<(ostream &out, const CDate &date) {
        out << date.day << "/" << date.month << "/" << date.year << "\n"; // dd/mm/yyyy
        return out;
    }

    bool CheckLeapYear() {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool PlusDate() {
        bool leapYear = CheckLeapYear();
        
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if(day == 31) {
                day = 1;
                if(month == 12) {
                    year++;
                    month = 1;
                }
            }
            else {
                day++;
            }
        }
        else {
            if(month != 2) {
                if(day == 30) {
                    day = 1;
                    month++;
                }
                else {
                    day++;
                }
            }
            else {
                if(day == 29) {
                    day = 1;
                    month++;
                }
                else {
                    if(day == 28 && leapYear) {
                        day = 1;
                        month++;
                    }
                    else {
                        day++;
                    }
                }
            }
        }

    }

    CDate operator++() {
        PlusDate();
        return *this;
    }

    CDate operator++(int) {
        PlusDate();
        return *this;
    }
};

int main() {

    CDate date;
    
    cin >> date;
    cout << ++date;
    cout << date++;

    return 0;
}