#include <iostream>

using namespace std;

class PhanSo {
private:
    int tu, mau;
public:
    void Nhap();
    void Xuat();
    void RutGon();
    int gcd(int a, int b);
};

void PhanSo::Nhap() {
    cin >> tu >> mau;
}

void PhanSo::Xuat() {
    cout << tu << "/" << mau;
}

int PhanSo::gcd(int a, int b) {
    if(b != 0) {
        gcd(b, a % b);
    }
    return a;
}

void PhanSo::RutGon() {
    int n = gcd(tu, mau);
    this->tu = this->tu / n;
    this->mau = this->mau / n;
}

int main() {

    return 0;
}