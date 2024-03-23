#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Ulility {
public:
    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo() {
        this->tu = 0;
        this->mau = 1;
    }

    PhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
    }

    PhanSo operator+(PhanSo &phanso) {
        PhanSo kq;
        kq.tu = this->tu * phanso.mau + phanso.tu * this->mau;
        kq.mau = this->mau * phanso.mau;
        return kq;
    }

    PhanSo operator-(PhanSo &phanso) {
        PhanSo kq;
        kq.tu = this->tu * phanso.mau - phanso.tu * this->mau;
        kq.mau = this->mau * phanso.mau;
        return kq;
    }    

    PhanSo operator*(PhanSo &phanso) {
        PhanSo kq;
        kq.tu = this->tu * phanso.tu;
        kq.mau = this->mau * phanso.mau;
        return kq;
    }

    PhanSo operator/(PhanSo &phanso) {
        PhanSo kq;
        kq.tu = this->tu * phanso.mau;
        kq.mau = this->mau * phanso.tu;
        return kq;
    }

    bool operator>(PhanSo phanso) {
        return this->tu * phanso.mau > phanso.tu * this->mau;
    }

    bool operator<(PhanSo phanso) {
        return this->tu * phanso.mau < phanso.tu * this->mau;
    }

    bool operator==(PhanSo phanso) {
        return this->tu * phanso.mau == phanso.tu * this->mau;
    }

    friend istream &operator>>(istream &in, PhanSo &phanso) {
        in >> phanso.tu >> phanso.mau;
        return in;
    }

    friend ostream &operator<<(ostream &out, const PhanSo &phanso) {
        out << phanso.tu << "/" << phanso.mau;

        return out;
    }

    static bool cmp(PhanSo* a, PhanSo* b) {
        return (*a) > (*b);
    }

    void RutGon() {
        int ucln = Ulility::gcd(tu, mau);
        tu /= ucln; 
        mau /= ucln;
    }
};

class DayPhanSo {
private:
    vector<PhanSo*> arrPhanSo;
    int size;
public:
    ~DayPhanSo() {
        for(int i = 0; i < size; i++) {
            delete arrPhanSo[i];
        }
    }

    vector<PhanSo*> &getArrPhanSo() {
        return arrPhanSo;
    }

    friend istream &operator>>(istream &in, DayPhanSo &dayPhanSo) {
        in >> dayPhanSo.size;
        for(int i = 0; i < dayPhanSo.size; i++) {
            PhanSo *phanso = new PhanSo();
            in >> *phanso;
            dayPhanSo.arrPhanSo.push_back(phanso);
        }

        return in;
    }

    friend ostream &operator<<(ostream &out, const DayPhanSo &dayPhanSo) {
        for(int i = 0; i < dayPhanSo.size; i++) {
            out << *dayPhanSo.arrPhanSo[i] << "\n";
        }

        return out;
    }

    static const PhanSo *PhanSoNhoNhat(const vector<PhanSo*> &arrPhanSo) {
        if (arrPhanSo.empty()) {
            return nullptr;
        }

        const PhanSo *min = arrPhanSo[0];
        for (int i = 1; i < arrPhanSo.size(); i++) {
            if (*arrPhanSo[i] < *min) {
                min = arrPhanSo[i];
            }
        }

        return min;
    }

    static PhanSo *TongDayPhanSo(const vector<PhanSo*> &arrPhanSo) {
        if (arrPhanSo.empty()) { 
            return nullptr; 
        }
        PhanSo *tong = new PhanSo();
        for(int i = 0; i < arrPhanSo.size(); i++) {
            *tong = *tong + *arrPhanSo[i];
        }

        return tong;
    }
};

int main() {

    DayPhanSo dayPhanSo;
    cout << "Day so thu nhat:\n";
    cin >> dayPhanSo;
    cout << dayPhanSo;
    cout << "Day so thu hai:\n";
    DayPhanSo dayPhanSo2;
    cin >> dayPhanSo2;
    cout << dayPhanSo2;
    cout << "\n";
    cout << "Min: " << *DayPhanSo::PhanSoNhoNhat(dayPhanSo.getArrPhanSo()) << "\n";
    cout << "\nsort\n";
    sort(dayPhanSo.getArrPhanSo().begin(), dayPhanSo.getArrPhanSo().end(), PhanSo::cmp);

    cout << "###\n";
    PhanSo *tongArr = DayPhanSo::TongDayPhanSo(dayPhanSo.getArrPhanSo());
    PhanSo *tongArr1 = DayPhanSo::TongDayPhanSo(dayPhanSo2.getArrPhanSo());
    if(tongArr && tongArr1) {
        tongArr->RutGon(); tongArr1->RutGon();
        cout << *tongArr << " " << *tongArr1 << "\n";
        if(*tongArr > *tongArr) {
            cout << "tong day 1 lon hon tong day 2\n";
        }
        else if(*tongArr == *tongArr1) {
            cout << "tong day 1 bang tong day 2\n";
        }
        else cout << "tong day 1 be hon tong day 2\n";

        delete tongArr, tongArr1;
    }
    return 0;
}