#include <iostream>
#include <cmath>

using namespace std;

class DonThuc {
private:
    int heSo;
    int soMu;
public:
    DonThuc(){}

    DonThuc(int heSo, int soMu) {
        this->heSo = heSo;
        this->soMu = soMu;
    }

    long long GiaTriDonThuc(int x) {
        return heSo * pow(x, soMu);
    }

    DonThuc &operator+(DonThuc &donthuc) {
        this->heSo = this->heSo + donthuc.heSo;
        return *this;
    }

    // friend ostream &operator<<(ostream &out, const DonThuc &donthuc) {
    //     cout << donthuc.heSo << "x^" << donthuc.soMu << "\n";
    //     return out;
    // }
};

int main() {

    DonThuc donthuc1(3,4);
    DonThuc donthuc2(5,4);

    cout << donthuc1.GiaTriDonThuc(2);

    DonThuc donthuc3 = donthuc1 + donthuc2;

    return 0;
}