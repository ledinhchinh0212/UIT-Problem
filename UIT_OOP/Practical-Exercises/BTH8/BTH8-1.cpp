#include <iostream>

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

class Sach {
private:
    string tenSach;
    Date ngayXuatBan;
    string tenTacGia;
    float giaBan;
protected:
    string theLoaiSach;
public:
    Sach();
    void Nhap();
    void Xuat();
};

Sach::Sach() {
    this->theLoaiSach = "";
}

void Sach::Nhap() {
    cout << "Ten sach: "; getline(cin >> ws, tenSach);
    cout << "Ngay xuat ban: "; cin >> ngayXuatBan;
    cout << "Ten tac gia: "; getline(cin >> ws, tenTacGia);
    cout << "Gia ban: "; cin >> giaBan;
}

void Sach::Xuat() {
    cout << "Ten sach: " << tenSach << "\n";
    cout << "The loai sach: " << theLoaiSach << "\n";
    cout << "Ngay xuat ban: " << ngayXuatBan << "\n";
    cout << "Ten tac gia: " << tenTacGia << "\n";
    cout << "Gia ban " << giaBan << "vnd\n";
}

class SachGiaoKhoa : public Sach {
public:
    SachGiaoKhoa();
};

SachGiaoKhoa::SachGiaoKhoa() {
    this->theLoaiSach = "Sach giao khoa";
}

class TieuThuyet : public Sach {
public:
    TieuThuyet();
};

TieuThuyet::TieuThuyet() {
    this->theLoaiSach = "Tieu thuyet";
}

class TapChi : public Sach {
public:
    TapChi();
};

TapChi::TapChi() {
    this->theLoaiSach = "Tap chi";
}

int main() {

    Sach **sach = new Sach*();
    cout << "Nhap so luong sach: ";
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "1. Sach giao khoa, 2. Tieu thuyet, 3. Tap chi: ";
        int type;
        cin >> type;
        if(type == 1) {
            sach[i] = new SachGiaoKhoa();
        }
        else if(type == 2) {
            sach[i] = new TieuThuyet();
        }
        else {
            sach[i] = new TapChi();
        }
        sach[i]->Nhap();
    }
    cout << "\n";
    for(int i = 0; i < n; i++) {
        sach[i]->Xuat();
        cout << "\n";
    }
    for(int i = 0; i < n; i++) {
        delete sach[i];
    }

    delete []sach;

    return 0;
}