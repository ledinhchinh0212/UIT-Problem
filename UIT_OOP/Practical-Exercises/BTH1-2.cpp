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
    bool operator>(const PhanSo &phanSo);
};

bool PhanSo::operator>(const PhanSo &phanSo) {
    return this->tu * phanSo.mau > phanSo.tu * this->mau;
}


void PhanSo::Nhap() {
    cin >> tu >> mau;
}

void PhanSo::Xuat() {
    RutGon();
    cout << tu << "/" << mau;
}

int PhanSo::gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    else return gcd(b, a % b);
}

void PhanSo::RutGon() {
    int n = gcd(tu, mau);
    this->tu = this->tu / n;
    this->mau = this->mau / n;
}

int main() {

    PhanSo phanSo_a, phanSo_b;
    phanSo_a.Nhap(); phanSo_b.Nhap();
    phanSo_a.Xuat(); 
    cout << "\n"; 
    phanSo_b.Xuat();
    if(phanSo_a > phanSo_b) {
        cout << "\nPhan so a lon hon phan so b\n";
    }
    else cout << "\nPhan so b lon hon phan so a\n";

    return 0;
}