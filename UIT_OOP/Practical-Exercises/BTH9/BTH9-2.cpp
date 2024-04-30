#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template<typename T>
class Sort {
public:
    static Sort<T> getInstance();
    void print(const vector<T> &v);
    void sapXepTheoThuTuTangDan(vector<T> v);
    void sapXepGiamDanDuaVaoGiaTriTuyetDoi(vector<T> v);
    void sapXepTheoSoNguyenLe(vector<T> v, bool (*p)(T, T));
    static bool ascending(T a, T b);
    static bool descending(T a, T b);
};

template<typename T>
bool Sort<T>::ascending(T a, T b) {
    return a < b;
}

template<typename T>
bool Sort<T>::descending(T a, T b) {
    return a > b;
}

template<typename T>
void Sort<T>::sapXepTheoSoNguyenLe(vector<T> v, bool (*p)(T, T)) {
    sort(v.begin(), v.end(), [this, p](T a, T b) {
        bool isAOdd = (a % 2 != 0);
        bool isBOdd = (b % 2 != 0);

        if (isAOdd && isBOdd) {
            return p(a, b); 
        } else if (isAOdd) {
            return true; 
        } else if (isBOdd) {
            return false;
        } else {
            return false;
        }
    });
    print(v);
}

template<typename T>
Sort<T> Sort<T>::getInstance() {
    return Sort();
}

template<typename T>
void Sort<T>::print(const vector<T> &v) {
    for(const auto &x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

template<typename T>
void Sort<T>::sapXepTheoThuTuTangDan(vector<T> v) {
    sort(v.begin(), v.end());
    print(v);
}

template<typename T>
void Sort<T>::sapXepGiamDanDuaVaoGiaTriTuyetDoi(vector<T> v) { 
    sort(v.begin(), v.end(), [this](T a, T b) 
    { 
        return abs(a) > abs(b);
    });
    print(v);
}


int main() {
    vector<int> v = {5, 2, 5 , -1, 0, 0, 7, -4, -8, 9, 3};
    cout << "origin: \n";
    Sort<int>::getInstance().print(v);
    cout << "\n";
    Sort<int>::getInstance().sapXepTheoThuTuTangDan(v);
    Sort<int>::getInstance().sapXepGiamDanDuaVaoGiaTriTuyetDoi(v);
    Sort<int>::getInstance().sapXepTheoSoNguyenLe(v, Sort<int>::getInstance().ascending);
    Sort<int>::getInstance().sapXepTheoSoNguyenLe(v, Sort<int>::getInstance().descending);

    return 0;
}