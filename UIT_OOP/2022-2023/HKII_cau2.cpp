#include <iostream>

using namespace std;

class Money {
private:
    int iEuro;
    int iCent;
public:
    friend istream &operator>>(istream &in, Money &money) {
        in >> money.iEuro;
        in >> money.iCent;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Money &money) {
        out << money.iEuro << " " << money.iCent << "\n";
        return out;
    }

    void PlusCentMoney() {
        iCent++;
        if (iCent >= 100) {
            iEuro += iCent / 100;
            iCent %= 100;
        }
    }

    Money &operator++() {
        PlusCentMoney();
        return *this;
    }

    Money &operator++(int) {
        PlusCentMoney();
        return *this;
    }
};

int main() {

    Money money;
    cin >> money;
    ++money;
    money++;
    cout << money;

    return 0;
}