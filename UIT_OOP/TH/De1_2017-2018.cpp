#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhanVien {
protected:
    string maNhanVien;
    string hoTen;
    string ngayThangNamSinh;
public:
    NhanVien(string maNhanVien, string hoTen, string ngayThangNamSinh) {
        this->maNhanVien = maNhanVien;
        this->hoTen = hoTen;
        this->ngayThangNamSinh = ngayThangNamSinh;
    }

    string getMaNhanVien() {
        return maNhanVien;
    }

    string getHoTen() {
        return hoTen;
    }

    string getNgayThangNamSinh() {
        return ngayThangNamSinh;
    }

    virtual bool TieuChuanXetTuyenLaoDongTienTien() const = 0;
};

class GiangVien : public NhanVien{
private:
    int soTietGiangDayTrongNam;
    int soDeTaiKhoaLuan;
public:
    GiangVien(string maNhanVien, string hoTen, string ngayThangNamSinh, int soTietGiangDayTrongNam, int soDeTaiKhoaLuan) :
    NhanVien(maNhanVien, hoTen, ngayThangNamSinh) {
        this->soTietGiangDayTrongNam = soTietGiangDayTrongNam;
        this->soDeTaiKhoaLuan = soDeTaiKhoaLuan;
    }

    int getSoTietGiangDayTrongNam() {
        return soTietGiangDayTrongNam;
    }

    int getSoDeTaiKhoaLuan() {
        return soDeTaiKhoaLuan;
    }

    bool TieuChuanXetTuyenLaoDongTienTien() const override {
        return (soTietGiangDayTrongNam >= 300 && soDeTaiKhoaLuan >= 5);
    } 
};

class NghienCuuVien : public NhanVien {
private:
    int soDeTaiNghienCuu;
    int soBaiBaoKhoaHoc;
public:
    NghienCuuVien(string maNhanVien, string hoTen, string ngayThangNamSinh, int soDeTaiNghienCuu, int soBaiBaoKhoaHoc) :
    NhanVien(maNhanVien, hoTen, ngayThangNamSinh) {
        this->soDeTaiNghienCuu = soDeTaiNghienCuu;
        this->soBaiBaoKhoaHoc = soBaiBaoKhoaHoc;
    }

    int getSoDeTaiNghienCuu() {
        return soDeTaiNghienCuu;
    }

    int getSoBaiBaoKhoaHoc() {
        return soBaiBaoKhoaHoc;
    }

    bool TieuChuanXetTuyenLaoDongTienTien() const override {
        return (soDeTaiNghienCuu >= 1 && soBaiBaoKhoaHoc >= 2);
    }
};

class NhanVienVanPhong : public NhanVien {
private:
    int soLopBoiDuongChuyenMon;
    int soGioLaoDongCongIch;
public:
    NhanVienVanPhong(string maNhanVien, string hoTen, string ngayThangNamSinh, int soLopBoiDuongChuyenMon, int soGioLaoDongCongIch) :
    NhanVien(maNhanVien, hoTen, ngayThangNamSinh) {
        this->soLopBoiDuongChuyenMon = soLopBoiDuongChuyenMon;
        this->soGioLaoDongCongIch = soGioLaoDongCongIch;
    }

    int getSoLopBoiDuongChuyenMon() {
        return soLopBoiDuongChuyenMon;
    }

    int getSoGioLaoDongCongIch() {
        return soGioLaoDongCongIch;
    }

    bool TieuChuanXetTuyenLaoDongTienTien() const override {
        return (soLopBoiDuongChuyenMon >= 1 && soGioLaoDongCongIch >= 20);
    }
};

class QuanLiNhanVien {
private:
    vector<NhanVien*> danhSachNhanVien;
    int size;
public:
    QuanLiNhanVien() {
        this->size = 0;
    }

    ~QuanLiNhanVien() {
        for(int i = 0; i < size; i++) {
            delete danhSachNhanVien[i];
        }
    }

    void Nhap() {
        cin >> size;
        for(int i = 0; i < size; i++) {
            cout << "Nhap ma nhan vien: "; string maNhanVien;
            cin >> maNhanVien;
            cout << "Nhap ho ten nhan vien: "; string hoTen;
            cin.ignore(); getline(cin, hoTen);
            cout << "Nhap ngay thang nam sinh: "; string ngayThangNamSinh;
            cin >> ngayThangNamSinh;
            cout << "Nhap loai nhan vien (1 - Giang vien, 2 - Nghien cuu vien, 3 - Nhan vien van phong): ";
            int typeNhanVien; cin >> typeNhanVien;
            if(typeNhanVien == 1) {
                cout << "Nhap so tiet giang day trong nam: "; int choose1;
                cin >> choose1;
                cout << "So de tai khoa luan giang vien huong dan: "; int choose2;
                cin >> choose2; 

                danhSachNhanVien.push_back(new GiangVien(maNhanVien, hoTen, ngayThangNamSinh, choose1, choose2));
            }
            else if(typeNhanVien == 2) {
                cout << "So de tai nghien cuu tham gia: "; int choose1;
                cin >> choose1;
                cout << "So bai bao khoa hoc nghien cuu hoac dong tac gia: "; int choose2;
                cin >> choose2;

                danhSachNhanVien.push_back(new NghienCuuVien(maNhanVien, hoTen, ngayThangNamSinh, choose1, choose2));
            }
            else if(typeNhanVien == 3) {
                cout << "So lop boi duong chuyen mon tham du: "; int choose1;
                cin >> choose1;
                cout << "So gio lao dong cong ich: "; int choose2;
                cin >> choose2;

                danhSachNhanVien.push_back(new NhanVienVanPhong(maNhanVien, hoTen, ngayThangNamSinh, choose1, choose2));
            }
        }
    }

    void Xuat() {
        for(int  i = 0; i < size; i++) {
            GiangVien *giangVien = dynamic_cast<GiangVien*>(danhSachNhanVien[i]);
            NghienCuuVien *nghienCuuVien = dynamic_cast<NghienCuuVien*>(danhSachNhanVien[i]);
            NhanVienVanPhong *nhanVienVanPhong = dynamic_cast<NhanVienVanPhong*>(danhSachNhanVien[i]);

            if(giangVien != nullptr && giangVien->TieuChuanXetTuyenLaoDongTienTien() ||
                nghienCuuVien != nullptr && nghienCuuVien->TieuChuanXetTuyenLaoDongTienTien() ||
                nhanVienVanPhong != nullptr && nhanVienVanPhong->TieuChuanXetTuyenLaoDongTienTien()) {
                cout << "Ma nhan vien: " << danhSachNhanVien[i]->getMaNhanVien() << "\n";
                cout << "Ho ten nhan vien: " << danhSachNhanVien[i]->getHoTen() << "\n";
                cout << "Ngay thang nam sinh: " << danhSachNhanVien[i]->getNgayThangNamSinh() << "\n";
            }

            if(giangVien != nullptr && giangVien->TieuChuanXetTuyenLaoDongTienTien()) {
                cout << "So tiet giang day trong nam: " << giangVien->getSoTietGiangDayTrongNam() << "\n";
                cout << "So de tai khoa luan giang vien huong dan: " << giangVien->getSoDeTaiKhoaLuan() << "\n";
                delete giangVien;
            }
            if(nghienCuuVien != nullptr && nghienCuuVien->TieuChuanXetTuyenLaoDongTienTien()) {
                cout << "So de tai nghien cuu tham gia: " << nghienCuuVien->getSoDeTaiNghienCuu() << "\n";
                cout << "So bai bao khoa hoc la tac gia hoac dong tac gia: " << nghienCuuVien->getSoBaiBaoKhoaHoc() << "\n";
                delete nghienCuuVien;
            }
            if(nhanVienVanPhong != nullptr && nhanVienVanPhong->TieuChuanXetTuyenLaoDongTienTien()) {
                cout << "So lop boi duong chuyen mon: " << nhanVienVanPhong->getSoLopBoiDuongChuyenMon() << "\n";
                cout << "So gio lao dong cong ich do truong to chuc: " << nhanVienVanPhong->getSoGioLaoDongCongIch() << "\n";
                delete nhanVienVanPhong;
            }

        }
    }
};

int main() {

    QuanLiNhanVien a;

    a.Nhap();

    a.Xuat();

    return 0;
}