#include <iostream>

using namespace std;

class HocSinh {
private:
    string ten;
    float diemToan;
    float diemVan;
public:
    friend istream &operator>>(istream &in, HocSinh &hocSinh);
    friend ostream &operator<<(ostream &out, const HocSinh &hocSinh);
    float DiemTrungBinh() const;
};

float HocSinh::DiemTrungBinh() const {
    return (diemToan + diemVan) / 2;
}

istream &operator>>(istream &in, HocSinh &hocSinh) {
    getline(in >> ws, hocSinh.ten);
    in >> hocSinh.diemToan >> hocSinh.diemVan;
    return in;
}

ostream &operator<<(ostream &out, const HocSinh &hocSinh) {
    out << "Ten: " << hocSinh.ten << "\n";
    out << "Diem Toan: " << hocSinh.diemToan << "\n";
    out << "Diem Van: " << hocSinh.diemVan << "\n";
    out << "Diem Trung Binh: " << hocSinh.DiemTrungBinh();
    return out;
}

int main() {

    HocSinh hocSinh;
    cin >> hocSinh;
    cout << hocSinh;

    return 0;   
}