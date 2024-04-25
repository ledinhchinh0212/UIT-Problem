#include <iostream>

using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date();
    Date(int day, int month, int year);
    friend ostream &operator<<(ostream &out, const Date &date);
    friend istream &operator>>(istream &in, Date &date);
    Date &NextDate();
    bool isLeapYear();
};

Date::Date() {
    day = month = year = 0;
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

ostream &operator<<(ostream &out, const Date &date) {
    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}

istream &operator>>(istream &in, Date &date) {
    in >> date.day >> date.month >> date.year;
    return in;
}

bool Date::isLeapYear() {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date &Date::NextDate() {
    if(day <= 0 || month <= 0 || year <= 0) {
        return *this;
    }
    int dayInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leapYear = isLeapYear();
    if(leapYear) {
        dayInMonth[2] = 29;
    }
    if(day < dayInMonth[month]) {
        day++;
    }
    else if(day == dayInMonth[month]) {
        day = 1;
        month++;
        if(month > 12) {
            year++;
            month = 1;
        }
    }
    return *this;
}

int main() {

    Date date(31, 12, 2005);
    cout << date << "\n";
    date = date.NextDate();
    cout << date << "\n";

    return 0;
}