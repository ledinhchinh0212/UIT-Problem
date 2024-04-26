#include <iostream>
#include <cmath>

using namespace std;

class SoPhuc {
private:
    float thuc, ao;
public:
    SoPhuc(float thuc = 0.0f, float ao = 0.0f);
    friend istream &operator>>(istream &in, SoPhuc &soPhuc);
    friend ostream &operator<<(ostream &out, const SoPhuc &soPhuc);
    void setThuc(float thuc);
    void setAo(float ao);
    SoPhuc operator+(const SoPhuc &soPhuc);
    SoPhuc operator-(const SoPhuc &soPhuc);
    SoPhuc operator*(const SoPhuc &soPhuc);
    SoPhuc operator/(const SoPhuc &soPhuc);
};

SoPhuc::SoPhuc(float thuc, float ao) {
    this->thuc = thuc;
    this->ao = ao;
}

void SoPhuc::setThuc(float thuc) {
    this->thuc = thuc;
}

void SoPhuc::setAo(float ao) {
    this->ao = ao;
}

istream &operator>>(istream &in, SoPhuc &soPhuc) {
    in >> soPhuc.thuc >> soPhuc.ao;
    return in;
}

ostream &operator<<(ostream &out, const SoPhuc &soPhuc) {
    cout << soPhuc.thuc;
    if(soPhuc.ao != 0) {
        float ao = soPhuc.ao;
        if(soPhuc.ao > 0) {
            cout << " + ";
        }
        else {
            ao = soPhuc.ao * -1;
            cout << " - ";
        }
        cout << ao << "i";
    }
    return out; 
}

SoPhuc SoPhuc::operator+(const SoPhuc &soPhuc) {
    return SoPhuc(this->thuc + soPhuc.thuc, this->ao + soPhuc.ao);
}

SoPhuc SoPhuc::operator-(const SoPhuc &soPhuc) {
    return SoPhuc(this->thuc - soPhuc.thuc, this->ao + soPhuc.ao);
}
SoPhuc SoPhuc::operator*(const SoPhuc &soPhuc) {
    float thuc = this->thuc * soPhuc.thuc - this->ao * soPhuc.ao;
    float ao = this->thuc * soPhuc.ao + this->ao * soPhuc.thuc;
    return SoPhuc(thuc, ao);
}
SoPhuc SoPhuc::operator/(const SoPhuc &soPhuc) {
    float thuc = (this->thuc * soPhuc.thuc + this->ao * soPhuc.ao) / (pow(soPhuc.thuc, 2) + pow(soPhuc.ao, 2));
    float ao = (soPhuc.thuc * this->ao - this->thuc * soPhuc.ao) / (pow(soPhuc.thuc, 2) + pow(soPhuc.ao, 2));
    return SoPhuc(thuc, ao);
}
int main() {
    SoPhuc a, b;
    cout << "Nhap so phuc a:\n";
    cin >> a;
    cout << "Nhap so phuc b:\n";
    cin >> b;
    cout << a << "\n" << b;
    cout << "\nTong: " << a + b;
    cout << "\nHieu: " << a - b;
    cout << "\nTich: " << a * b;
    cout << "\nThuong: " << a / b;
    return 0;
}