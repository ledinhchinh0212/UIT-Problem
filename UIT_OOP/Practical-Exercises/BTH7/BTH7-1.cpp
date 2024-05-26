#include <iostream>
#include <string>
#include <algorithm>

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

bool cmp(NhanVien *a, NhanVien *b) {
    return a->LuongNhanVien() > b->LuongNhanVien();
}

int main() {

    cout << "Nhap so luong nhan vien trong cong ty: ";
    int n; cin >> n;
    NhanVien **nhanVien = new NhanVien*[n];
    
    for(int i = 0; i < n; i++) {
        cout << "1. Nhan vien van phong, 2. Nhan vien san xuat: ";
        int type; cin >> type;
        if(type == 1) {
            nhanVien[i] = new NhanVienVanPhong();
        }
        else {
            nhanVien[i] = new NhanVienSanXuat();
        }
        nhanVien[i]->Nhap();
    }
    // luong cua tung nahn vien
    float sum = 0.0f;
    float maxLuong = nhanVien[0]->LuongNhanVien();      int positionMax = 0;
    float minLuong = nhanVien[0]->LuongNhanVien();      int positionMin = 0;
    for(int i = 0; i < n; i++) {
        nhanVien[i]->Xuat(); cout << "\n";
        sum = sum + nhanVien[i]->LuongNhanVien();
        if(maxLuong < nhanVien[i]->LuongNhanVien()) {
            maxLuong = nhanVien[i]->LuongNhanVien();
            positionMax = i;
        }
        if(minLuong > nhanVien[i]->LuongNhanVien()) {
            minLuong = nhanVien[i]->LuongNhanVien();
            positionMin = i;
        }
    }
    cout << "Tong luong ma cong ty can phai tra cho cac nhan vien: " << sum << "\n";
    cout << "\nNhan vien co luong cao nhat: \n";
    
    nhanVien[positionMax]->Xuat();
    
    cout << "\nNhan vien co luong thap nhat: \n";
    
    nhanVien[positionMin]->Xuat();

    cout << "\nSap xep dan sach nhan vien theo luong giam dan:\n\n";
    sort(nhanVien, nhanVien + n, cmp);
    for(int i = 0; i < n; i++)
    {
        nhanVien[i]->Xuat(); cout << "\n";
    }
    return 0;
}