#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo(int tu = 0, int mau = 1);
    bool operator>(const PhanSo &phanSo);
    bool operator<(const PhanSo &phanSo);
    bool operator==(const PhanSo &phanSo);
    friend ostream &operator<<(ostream &out, const PhanSo &phanSo);
};

ostream &operator<<(ostream &out, const PhanSo &phanSo) {
    out << phanSo.tu << "/" << phanSo.mau;
    return out;
}

PhanSo::PhanSo(int tu, int mau) {
    this->tu = tu;
    this->mau = mau;
}

bool PhanSo::operator>(const PhanSo &phanSo) {
    return this->tu * phanSo.mau > phanSo.tu * this->mau;
}

bool PhanSo::operator<(const PhanSo &phanSo) {
    return this->tu * phanSo.mau < phanSo.tu * this->mau;
}

bool PhanSo::operator==(const PhanSo &phanSo) {
    return this->tu * phanSo.mau == phanSo.tu * this->mau;
}

template<typename T>
class Program {
public:
    static Program<T> getInstance();
    T minCuaHaiPhanTu(T a, T b);
    T maxCuaHaiPhanTu(T a, T b);
    T phanTuDuongLonNhat(T a, T b);
    void sapXepMangTangDan(vector<T> v);
};

template<typename T>
Program<T> Program<T>::getInstance() {
    return Program<T>();
}

template<typename T>
T Program<T>::minCuaHaiPhanTu(T a, T b) {
    return (a < b) ? a : b;
}

template<typename T>
T Program<T>::maxCuaHaiPhanTu(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T>
T Program<T>::phanTuDuongLonNhat(T a, T b) {
    if(a > 0 && b <= 0) {
        return a;
    }
    else if(a <= 0 && b > 0) {
        return b;
    }
    if(a == b == 0 || (a < 0 && b < 0)) {
        return -1;
    }
    return maxCuaHaiPhanTu(a, b);
}

template<typename T>
void Program<T>::sapXepMangTangDan(vector<T> v) {
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

int main() {

    PhanSo a(0, 5);
    PhanSo b(-4, 5);
    cout << Program<PhanSo>::getInstance().maxCuaHaiPhanTu(a, b) << "\n";
    vector<PhanSo> v = { {1, 2}, {2, 3}, {1, 4}, {4, 6}, {3, 6} };
    Program<PhanSo>::getInstance().sapXepMangTangDan(v);

    return 0;
}