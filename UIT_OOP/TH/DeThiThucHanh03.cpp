#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ThoiGian {
private:
    int ngay, thang, nam;
public:
    friend istream &operator>>(istream &in, ThoiGian &thoigian) {
        in >> thoigian.ngay >> thoigian.thang >> thoigian.nam;

        return in;
    }

    friend ostream &operator<<(ostream &out, const ThoiGian &thoigian) {
        out << thoigian.ngay << "/" << thoigian.thang << "/" << thoigian.nam;

        return out;
    }

    bool operator>(const ThoiGian &thoigian) {
        if (nam > thoigian.nam) {
            return true;
        } else if (nam == thoigian.nam) {
            if (thang > thoigian.thang) {
                return true;
            } else if (thang == thoigian.thang) {
                if (ngay > thoigian.ngay) {
                    return true;
            }
        }
    }
    return false;
    }
};

class HocSinh {
private:
    int maHocSinh;
    string hoTen;
    string gioiTinh;
    ThoiGian ngaySinh;
    string diaChi;
public:
    friend istream &operator>>(istream &in, HocSinh &hocsinh) {
        in >> hocsinh.maHocSinh;
        in.ignore();
        getline(in, hocsinh.hoTen);
        in >> hocsinh.gioiTinh;
        in >> hocsinh.ngaySinh;
        in.ignore();
        getline(in, hocsinh.diaChi);

        return in;
    }

    friend ostream &operator<<(ostream &out, const HocSinh &hocsinh) {
        out << "Ma hoc sinh: " << hocsinh.maHocSinh << "\n";
        out << "Ho ten: " << hocsinh.hoTen << "\n";
        out << "Gioi tinh: " << hocsinh.gioiTinh << "\n";
        out << "Ngay sinh: " << hocsinh.ngaySinh << "\n";
        out << "Dia chi: " << hocsinh.diaChi << "\n";

        return out;
    }
};

class LopHoc {
private:
    string tenLop;
    int siSo;
    vector<HocSinh*> dsHocSinh;
};

int main() {

    HocSinh hocsinh;
    cin >> hocsinh;
    cout << hocsinh;

    return 0;
}