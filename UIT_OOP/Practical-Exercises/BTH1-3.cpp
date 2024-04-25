#include <iostream>

using namespace std;

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo() {}
    PhanSo(int tu, int mau);
    void Nhap();
    void Xuat();
    void RutGon();
    int gcd(int a, int b);
    PhanSo operator+(const PhanSo &phanSo);
    PhanSo operator-(const PhanSo &phanSo);
    PhanSo operator*(const PhanSo &phanSo);
    PhanSo operator/(const PhanSo &phanSo);
    friend ostream &operator<<(ostream &out, const PhanSo &phanSo);
};

ostream& operator<<(ostream& out, const PhanSo& phanSo) {
    out << phanSo.tu << "/" << phanSo.mau;
    return out;
}

PhanSo::PhanSo(int tu, int mau) {
    this->tu = tu;
    this->mau = mau;
}

PhanSo PhanSo::operator+(const PhanSo &phanSo) {
    PhanSo kq;
    kq.tu = this->tu * phanSo.mau + phanSo.tu * this->mau;
    kq.mau = this->mau * phanSo.mau;
    return kq;
}

PhanSo PhanSo::operator-(const PhanSo &phanSo) {
    PhanSo kq;
    kq.tu = this->tu * phanSo.mau - phanSo.tu * this->mau;
    kq.mau = this->mau * phanSo.mau;
    return kq;
}

PhanSo PhanSo::operator*(const PhanSo &phanSo) {
    PhanSo kq;
    kq.tu = this->tu * phanSo.tu;
    kq.mau = this->mau * phanSo.mau;
    return kq;
}

PhanSo PhanSo::operator/(const PhanSo &phanSo) {
    PhanSo kq;
    kq.tu = this->tu * phanSo.mau;
    kq.mau = this->mau * phanSo.tu;
    return kq;
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

    // gia su mau luon khac 0
    PhanSo phanSo_a, phanSo_b;
    phanSo_a.Nhap();
    phanSo_b.Nhap();
    cout << "Tong: "; (phanSo_a + phanSo_b).Xuat();
    cout << "\nHieu: "; (phanSo_a - phanSo_b).Xuat();
    cout << "\nTich: "; (phanSo_a * phanSo_b).Xuat();
    cout << "\nThuong: "; (phanSo_a / phanSo_b).Xuat();

    return 0;
}