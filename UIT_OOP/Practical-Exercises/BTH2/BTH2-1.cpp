#include <iostream>

using namespace std;

class PhanSo {
private:
    int tu;
    int mau;
public:
    PhanSo(int tu = 0, int mau = 1);
    void setTu(int tu);
    void setMau(int mau);
    int gcd(int tu, int mau) const;
    friend istream &operator>>(istream &in, PhanSo &phanSo);
    friend ostream &operator<<(ostream &out, const PhanSo &phanSo);
    PhanSo operator+(const PhanSo &phanSo);
    PhanSo operator-(const PhanSo &phanSo);
    PhanSo operator*(const PhanSo &phanSo);
    PhanSo operator/(const PhanSo &phanSo);
    friend PhanSo operator+(int value, const PhanSo &b);
};

PhanSo operator+(int value, const PhanSo &b) {
    PhanSo temp(value);
    return temp + b;
}

int PhanSo::gcd(int tu, int mau) const {
    if(mau == 0) {
        return tu;
    }
    else {
        return gcd(mau, tu % mau);
    }
}

PhanSo::PhanSo(int tu, int mau) {
    this->tu = tu;
    this->mau = mau;
}

void PhanSo::setTu(int tu) {
    this->tu = tu;
}

void PhanSo::setMau(int mau) {
    this->mau = mau;
}

istream &operator>>(istream &in, PhanSo &phanSo) {
    in >> phanSo.tu >> phanSo.mau;
    return in;
}

ostream &operator<<(ostream &out, const PhanSo &phanSo) {
    int n = phanSo.gcd(phanSo.tu, phanSo.mau);
    out << phanSo.tu / n << "/" << phanSo.mau / n;
    return out;
}

PhanSo PhanSo::operator+(const PhanSo &phanSo) {
    return PhanSo(this->tu * phanSo.mau + phanSo.tu * this->mau, this->mau * phanSo.mau);
}

PhanSo PhanSo::operator-(const PhanSo &phanSo) {
    return PhanSo(this->tu * phanSo.mau - phanSo.tu * this->mau, this->mau * phanSo.mau);
}

PhanSo PhanSo::operator*(const PhanSo &phanSo) {
    return PhanSo(this->tu * phanSo.tu, this->mau * phanSo.mau);
}

PhanSo PhanSo::operator/(const PhanSo &phanSo) {
    return PhanSo(this->tu * phanSo.mau, this->mau * phanSo.tu);
}


int main() {
    // giả sử với mẫu số với mọi của phân số luôn luôn khác 0
    // và luôn luôn thoả mãn khi thực hiện các phép tính (phép thương)
    PhanSo a;
    PhanSo b;
    cout << "Nhap phan so a:\n";
    cin >> a;
    cout << "Nhap phan so b:\n";
    cin >> b;
    cout << a << " " << b << "\n";
    cout << "Tong: " << a + b << "\n";
    cout << "Hieu: " << a - b << "\n";
    cout << "Tich: " << a * b << "\n";
    cout << "Thuong: " << a / b << "\n";

    cout << 2 + a;

    return 0;
}
