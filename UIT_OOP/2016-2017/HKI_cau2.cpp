#include <iostream>

using namespace std;

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo() {
        tu = 0;
        mau = 1;
    }
    
    PhanSo(int tu, int mau = 1) {
        this->tu = tu;
        this->mau = mau;
    }

    PhanSo operator+(PhanSo &phanso) {
        PhanSo kq;
        kq.tu = this->tu * phanso.mau + this->mau * phanso.tu;
        kq.mau = this->mau * phanso.mau;

        return kq;
    }

    void Xuat() {
        cout << tu << "/" << mau << "\n";
    }
};

int main() {
    PhanSo a;
    PhanSo b(1,2);
    PhanSo c(3);
    a = b + c;
    a.Xuat();
    return 0;
}