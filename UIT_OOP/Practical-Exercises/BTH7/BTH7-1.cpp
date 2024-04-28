#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int ngay, thang, nam;
public:
    friend istream &operator>>(istream &in, Date &date);
    friend ostream &operator<<(ostream &out, const Date &date);
};

istream &operator>>(istream &in, Date &date) {
    in >> date.ngay >> date.thang >> date.nam;
    return in;
}

ostream &operator<<(ostream &out, const Date &date) {
    out << date.ngay << "/" << date.thang << "/" << date.nam;
    return out;
}

class NhanVien {
protected:
    string hoTen;
    Date ngaySinh; 
public:
    virtual void Nhap();
    virtual void Xuat();
    virtual float LuongNhanVien() const = 0;
};

void NhanVien::Nhap() {
    cout << "Ho ten: "; getline(cin >> ws, hoTen);
    cout << "Ngay sinh: "; cin >> ngaySinh; 
}

void NhanVien::Xuat() {
    cout << "Ho ten: " << hoTen << "\n";
    cout << "Nhay sinh: " << ngaySinh << "\n";
}

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;
public: 
    void Nhap() override;
    void Xuat() override;
    float LuongNhanVien() const override;
};

float NhanVienVanPhong::LuongNhanVien() const {
    return soNgayLamViec * 100000;
}

void NhanVienVanPhong::Nhap() {
    NhanVien::Nhap();
    cout << "So ngay lam viec: "; cin >> soNgayLamViec;
}

void NhanVienVanPhong::Xuat() {
    NhanVien::Xuat();
    cout << "So ngay lam viec: " << soNgayLamViec << "\n";
    cout << "Luong nhan vien: " << LuongNhanVien() << "\n";
}

class NhanVienSanXuat : public NhanVien {
private:
    float luongCanBan;
    int soSanPham;
public:
    void Nhap() override;
    void Xuat() override;
    float LuongNhanVien() const override;
};

float NhanVienSanXuat::LuongNhanVien() const {
    return luongCanBan + soSanPham * 5000;
}

void NhanVienSanXuat::Nhap() {
    NhanVien::Nhap();
    cout << "Luong can ban: "; cin >> luongCanBan;
    cout << "So san pham: "; cin >> soSanPham;
}

void NhanVienSanXuat::Xuat() {
    NhanVien::Xuat();
    cout << "Luong can ban: " << luongCanBan << "\n";
    cout << "So san pham: " << soSanPham << "\n";
    cout << "Luong nhan vien: " << LuongNhanVien() << "\n";
}

int main() {

    return 0;
}