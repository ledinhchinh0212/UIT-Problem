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
    if(b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

void PhanSo::RutGon() {
    int n = gcd(tu, mau);
    this->tu = this->tu / n;
    this->mau = this->mau / n;
}

int main() {

    PhanSo phanSo;
    phanSo.Nhap();
    phanSo.RutGon();
    phanSo.Xuat();
    // dam bao rang mau luon khac 0

    return 0;
}