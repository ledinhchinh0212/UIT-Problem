#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

class KhachHang {
protected:
    string tenKhachHang;
    int soDonHang;
    double donGiaHang;
    int soNamThanThiet;
    float thueVAT;
public:
    KhachHang();
    string getTenKhachHang() const;
    virtual double soTienPhaiTra() const = 0;
};

string KhachHang::getTenKhachHang() const {
    return tenKhachHang;
} 

KhachHang::KhachHang() {
    this->thueVAT = 0.1f;
    this->soNamThanThiet = 0;
}

class KhachHangBinhThuong : public KhachHang{
public:
    KhachHangBinhThuong(string tenKhachHang, int soDonHang, float donGiaHang);
    double soTienPhaiTra() const override;
};

KhachHangBinhThuong::KhachHangBinhThuong(string tenKhachHang, int soDonHang, float donGiaHang) {
    this->tenKhachHang = tenKhachHang;
    this->soDonHang = soDonHang;
    this->donGiaHang = donGiaHang;
}

double KhachHangBinhThuong::soTienPhaiTra() const {
    return soDonHang * donGiaHang + thueVAT;
}

class KhachHangThanThiet : public KhachHang{
private:
    float phanTramKhuyenMai;
public:
    KhachHangThanThiet(string tenKhachHang, int soDonHang, float donGiaHang, int soNamThanThiet);
    double soTienPhaiTra() const override;
};

KhachHangThanThiet::KhachHangThanThiet(string tenKhachHang, int soDonHang, float donGiaHang, int soNamThanThiet) {
    this->tenKhachHang = tenKhachHang;
    this->soDonHang = soDonHang;
    this->donGiaHang = donGiaHang;
    this->soNamThanThiet = soNamThanThiet;
    this->phanTramKhuyenMai = (this->soNamThanThiet * 0.05 > 0.5) ? this->soNamThanThiet * 0.05 : 0.5;
}

double KhachHangThanThiet::soTienPhaiTra() const {
    return (soDonHang * donGiaHang) * (1 - phanTramKhuyenMai) + thueVAT;
}

class KhachHangDacBiet : public KhachHang {
public:
    KhachHangDacBiet(string tenKhachHang, int soDonHang, float donGiaHang);
    double soTienPhaiTra() const override;
};

KhachHangDacBiet::KhachHangDacBiet(string tenKhachHang, int soDonHang, float donGiaHang) {
    this->tenKhachHang = tenKhachHang;
    this->soDonHang = soDonHang;
    this->donGiaHang = donGiaHang;
}

double KhachHangDacBiet::soTienPhaiTra() const {
    return (soDonHang * donGiaHang) * 0.5 + thueVAT;
}

int main() {

    ifstream file;
    const char* linkFile = "C:\\Users\\ADMIN\\Desktop\\xyz.inp";
    file.open(linkFile);
    if(file.fail()) {
        cout << "Mo file khong hop le\n";
        return -1;
    }

    int x, y, z;
    file >> x >> y >> z;
    int n = x + y + z;
    KhachHang **khachHang = new KhachHang*[n];
    if(khachHang == nullptr) {
        cout << "nullptr";
        return -1;
    }
    string tenKhachHang;
    int soDonHang;
    float donGiaHang;
    int soNamThanThiet;
    for(int i = 0; i < n; i++) {
        file.ignore();
        getline(file, tenKhachHang);
        file >> soDonHang >> donGiaHang;
        if(i < x) {
            khachHang[i] = new KhachHangBinhThuong(tenKhachHang, soDonHang, donGiaHang);
        }
        else if(i < x + y) {
            file >> soNamThanThiet;
            khachHang[i] = new KhachHangThanThiet(tenKhachHang, soDonHang, donGiaHang, soNamThanThiet);
        } 
        else {
            khachHang[i] = new KhachHangDacBiet(tenKhachHang, soDonHang, donGiaHang);
        }
    }
    file.close();
    ofstream openFile;
    const char *link = "C:\\Users\\ADMIN\\Desktop\\xyz.out";
    openFile.open(link);
    if(openFile.fail()) {
        cout << "Khong the mo file de ghi !";
        return -1;
    }
    double (KhachHang::*ptr)() const = &KhachHang::soTienPhaiTra;
    double sum = 0.0;
    for(int i = 0; i < n; i++) {
        double tienPhaiTra = (khachHang[i]->*ptr)();
        sum += tienPhaiTra;
        openFile << khachHang[i]->getTenKhachHang() << "\n";
        openFile << tienPhaiTra << "\n";
        openFile << "--------------------\n";
    }
    openFile << "Tong so tien cong ty thu duoc: " << sum;
    openFile.close();
    for(int i = 0; i < n; i++) {
        delete khachHang[i];
    }
    delete []khachHang;


    return 0;
}