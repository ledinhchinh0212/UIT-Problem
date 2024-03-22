#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NgayThang {
private:
    int ngay, thang, nam;
public:
    NgayThang() {}

    NgayThang(int ngay, int thang, int nam) {
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }

    friend istream &operator>>(istream &in, NgayThang &ngayThang) {
        in >> ngayThang.ngay >> ngayThang.thang >> ngayThang.nam;

        return in;
    }
};

class Nguoi {
protected:
    string ten;
    NgayThang ngaySinh;
public:
    friend istream &operator>>(istream &in, Nguoi &nguoi) {
        in.ignore();
        getline(in, nguoi.ten);
        NgayThang ngayThang;
        cin >> ngayThang;
        nguoi.ngaySinh = ngayThang;
        return in;
    }

    virtual ~Nguoi() {}
};

class SinhVien : public Nguoi {
private:
    string tenLop;
    float diemToan, diemLy, diemHoa;
public:
    friend istream &operator>>(istream &in, SinhVien &sinhVien) {
        in >> static_cast<Nguoi&>(sinhVien);
        in >> sinhVien.tenLop;
        in >> sinhVien.diemToan;
        in >> sinhVien.diemLy;
        in >> sinhVien.diemHoa;

        return in;
    }

    float getDiemToan() const {
        return diemToan;
    }

    float getDiemLy() const {
        return diemLy;
    }

    float getDiemHoa() const {
        return diemHoa;
    }

    float diemTrungBinh() const {
        return (diemToan + diemLy + diemHoa) / 3;
    }

    static void ThongTinSinhVien(const vector<Nguoi*> &nguoi) {
        for(int i = 0; i < nguoi.size(); i++) {
            SinhVien* sinhVienPtr = dynamic_cast<SinhVien*>(nguoi[i]);
            if(sinhVienPtr) {
                cout << sinhVienPtr->getDiemToan() << "\n";
                cout << sinhVienPtr->getDiemLy() << "\n";
                cout << sinhVienPtr->getDiemHoa() << "\n";
                cout << sinhVienPtr->diemTrungBinh() << "\n";
                cout << "\n";
            }
        }
    }
};

class CongNhan : public Nguoi {
private:
    string tenCongTy;
    int soNgayLamViec;
public:
    friend istream &operator>>(istream &in, CongNhan &congNhan) {
        in >> static_cast<Nguoi&>(congNhan);
        in >> congNhan.tenCongTy;
        in >> congNhan.soNgayLamViec;

        return in;
    }

    long long tienLuong() {
        return soNgayLamViec * 200000;
    }

    static void LuongCongNhan(const vector<Nguoi*> &nguoi) {
        for(int i = 0; i < nguoi.size(); i++) {
            CongNhan *congNhanPtr = dynamic_cast<CongNhan*>(nguoi[i]);
            if(congNhanPtr) {
                cout << congNhanPtr->tienLuong() << "\n";
            }
        }
    }
};

int main() {

    int N; cin >> N;
    vector<Nguoi*> nguoi;

    for(int i = 0; i < N; i++) {
        cout << "<1: Sinh vien, 2: Cong nhan: ";
        int type; cin >> type;
        if(type == 1) {
            SinhVien *sinhVien = new SinhVien();
            cin >> *sinhVien;
            nguoi.push_back(sinhVien);
        }
        else if(type == 2) {
            CongNhan *congNhan = new CongNhan();
            cin >> *congNhan;
            nguoi.push_back(congNhan);
        }
    }

    //
    SinhVien::ThongTinSinhVien(nguoi);
    //
    CongNhan::LuongCongNhan(nguoi);

    for(int i = 0; i < N; i++) {
        delete nguoi[i];   
    }

    return 0;
}