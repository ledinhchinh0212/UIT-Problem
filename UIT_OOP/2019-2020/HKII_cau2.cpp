#include <iostream>

using namespace std;

class CPhanSo {
private:
    int tu;
    int mau;
public:
    CPhanSo(){
        this->tu = this->mau = 1;
    }

    CPhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
    }

    CPhanSo operator+(CPhanSo &phanso) {
        CPhanSo kq;
        kq.tu = this->tu * phanso.mau + phanso.tu * this->mau;
        kq.mau = this->mau * phanso.mau;
        return kq;
    }

    friend istream &operator>>(istream &in, CPhanSo &phanso) {
        in >> phanso.tu;
        in >> phanso.mau;
        return in;
    }

    friend ostream &operator<<(ostream &out, const CPhanSo &phanso) {
        out << phanso.tu << "/" << phanso.mau << "\n";
        return out;
    }

    bool operator==(CPhanSo &phanso) {
        return this->tu * phanso.mau == phanso.tu * this->mau;
    }
};

int main() {
    CPhanSo a(5, 3);    
    CPhanSo b, c, kq;
    cin >> b >> c;
    kq = a + b + c;
    cout << "Ket qua la: " << kq;
    if(a == b) {
        cout << "Phan so a bang phan so b" << endl;
    }
    return 0;
}