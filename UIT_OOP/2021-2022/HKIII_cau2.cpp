#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PHANSO {
private:
    int x, y;
public:
    PHANSO(){}

    PHANSO(int x, int y) {
        this->x = x;
        this->y = y;
    }

    friend istream &operator>>(istream &in, PHANSO &phanso) {
        in >> phanso.x;
        in >> phanso.y;
        return in;
    }

    friend ostream &operator<<(ostream &out, const PHANSO &phanso) {
        out << phanso.x << "/" << phanso.y;
        return out;
    }

    PHANSO operator+(PHANSO &phanso) {
        PHANSO kq;
        kq.x = this->x * phanso.y + phanso.x * this->y;
        kq.y = this->y * phanso.y;
        return kq;
    } 

    PHANSO operator+(int num) {
        PHANSO kq;
        kq.x = this->x + this->y * num;
        kq.y = this->y;
        return kq;
    } 

    friend PHANSO operator+(int num, const PHANSO &phanso) {
        return PHANSO(num * phanso.y + phanso.x, phanso.y);
    }
};

int main() {

    PHANSO ps1, ps2(-2, 3), ps3;
    cin >> ps1;
    ps3 =  5 + ps1 + ps2;
    cout << "ps1 = " << ps1 << endl << "ps2 = " << ps2 << endl << "ps3 = " << ps3 << endl;

    return 0;
}