#include <iostream>
#include <string>
#include <vector>

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

class ConNguoi {
protected:
    string hoTen;
    Date ngaySinh;
public:
    virtual void Nhap();
    virtual void Xuat();
};

void ConNguoi::Nhap() {
    cout << "Ho ten: "; getline(cin >> ws, hoTen);
    cout << "Ngay sinh: "; cin >> ngaySinh;
}

void ConNguoi::Xuat() {
    cout << "Ho ten: " << hoTen << "\n";
    cout << "Ngay sinh: " << ngaySinh << "\n";
}

class HocSinh : public ConNguoi {
private:
    float diemTrungBinh;
public:
    void Nhap() override;
    void Xuat() override;
};

void HocSinh::Nhap() {
    ConNguoi::Nhap();
    cout << "Diem trung binh: "; cin >> diemTrungBinh;
}

void HocSinh::Xuat() {
    ConNguoi::Xuat();
    cout << "Diem trung binh: " << diemTrungBinh << "\n";
}

class CongNhan : public ConNguoi {
private:
    int soNgayLamViec;
    float luong;
public:
    void Nhap() override;
    void Xuat() override;
};

void CongNhan::Nhap() {
    ConNguoi::Nhap();
    cout << "So ngay lam viec: "; cin >> soNgayLamViec;
    cout << "Luong: "; cin >> luong;
}

void CongNhan::Xuat() {
    ConNguoi::Xuat();
    cout << "So ngay lam viec: " << soNgayLamViec << "\n";
    cout << "Luong: " << luong << "\n";
}

class NgheSi : public ConNguoi {
private:
    int soTienTuThien;
    float luong;
public:
    void Nhap() override;
    void Xuat() override;
};

void NgheSi::Nhap() {
    ConNguoi::Nhap();
    cout << "So tien tu thien: "; cin >> soTienTuThien;
    cout << "Luong: "; cin >> luong;
}

void NgheSi::Xuat() {
    ConNguoi::Xuat();
    cout << "So tien tu thien: " << soTienTuThien << "\n";
    cout << "Luong: " << luong << "\n";
}

class CaSi : public ConNguoi {
private:
    int soAlbum;
    int soGioLamViec;
    float luong;
public:
    void Nhap() override;
    void Xuat() override;
};

void CaSi::Nhap() {
    ConNguoi::Nhap();
    cout << "So Album: "; cin >> soAlbum;
    cout << "So gio lam viec: "; cin >> soGioLamViec;
    cout << "Luong: "; cin >> luong;
}

void CaSi::Xuat() {
    ConNguoi::Xuat();
    cout << "So Album: " << soAlbum << "\n";
    cout << "So gio lam viec: " << soGioLamViec << "\n";
    cout << "Luong: " << luong << "\n";
}

int main() {

    cout << "1. Hoc sinh, 2. Cong nhan, 3. Nghe si, 4. Ca si: ";
    int type; cin >> type;
    ConNguoi *conNguoi = nullptr;
    if(type == 1) {
        conNguoi = new HocSinh();
    }
    else if(type == 2) {
        conNguoi = new CongNhan();
    }
    else if(type == 3) {
        conNguoi = new NgheSi();
    }
    else if(type == 4){  
        conNguoi = new CaSi();
    }
    if(conNguoi != nullptr) {
        conNguoi->Nhap();
        conNguoi->Xuat();
        
        delete conNguoi;
    }
    return 0;
}