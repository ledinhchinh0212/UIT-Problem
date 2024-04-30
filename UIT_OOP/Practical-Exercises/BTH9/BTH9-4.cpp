#include <iostream>
#include <string>
#include <fstream>
#include <climits>

using namespace std;

class LoaiKhachSan {
private:
    bool phongVuotTroi;
protected:
    string maPhong;
    int soDem;
public:
    LoaiKhachSan(string maPhong, int soDem);
    string getMaPhong() const;
    void setPhongVuotTroi(bool phongVuotTroi);
    bool getPhongVuotTroi() const;
    virtual double doanhThuPhong() const = 0;
};

LoaiKhachSan::LoaiKhachSan(string maPhong, int soDem) {
    this->maPhong = maPhong;
    this->soDem = soDem;
    this->phongVuotTroi = false;
}

string LoaiKhachSan::getMaPhong() const {
    return maPhong;
}

void LoaiKhachSan::setPhongVuotTroi(bool phongVuotTroi) {
    this->phongVuotTroi = phongVuotTroi;
}

bool LoaiKhachSan::getPhongVuotTroi() const {
    return phongVuotTroi;
}

class Deluxe : public LoaiKhachSan  {
private:
    long long phiDichVu;
    long long phiPhucVu;
public:
    Deluxe(string maPhong, int doDem, long long phiDichVu, long long phiPhucVu);
    double doanhThuPhong() const override;
};

Deluxe::Deluxe(string maPhong, int soDem, long long phiDichVu, long long phiPhucVu) : LoaiKhachSan(maPhong, soDem) {
    this->phiDichVu = phiDichVu;
    this->phiPhucVu = phiPhucVu;
}

double Deluxe::doanhThuPhong() const {
    return (soDem * 75000 + phiDichVu) * (1 + phiPhucVu);
}

class Premium : public LoaiKhachSan {
private:
    long long phiDichVu;
public:
    Premium(string maPhong, int doDem, long long phiDichVu);
    double doanhThuPhong() const override;
};

Premium::Premium(string maPhong, int doDem, long long phiDichVu) : LoaiKhachSan(maPhong, soDem) {
    this->phiDichVu = phiDichVu;
}

double Premium::doanhThuPhong() const {
    return (soDem * 500000 + phiDichVu) * 1.05;
}

class Business : public LoaiKhachSan {
public:
    Business(string maPhong, int doDem);
    double doanhThuPhong() const override;
};

Business::Business(string maPhong, int doDem) : LoaiKhachSan(maPhong, soDem) {}

double Business::doanhThuPhong() const {
    return soDem * 300000;
}

int main() {

    const char *linkReadFile = "C:\\Users\\ADMIN\\Desktop\\SOFITEL.INP"; 
    const char *linkWriteFile = "C:\\Users\\ADMIN\\Desktop\\SOFITEL.OUT";

    ifstream readFile;
    readFile.open(linkReadFile);
    if(readFile.fail()) {
        cout << "Khong mo file de doc duoc\n";
        return -1;
    }

    int d, p, b;
    readFile >> d >> p >> b;
    int n = d + p + b;
    LoaiKhachSan **khachSan = new LoaiKhachSan*[n];
    if(khachSan == nullptr) {
        cout << "Cap phat dong khong thanh cong\n";
        return -1;
    }

    string maPhong;
    int soDem;
    long long phiDichVu;
    long long phiPhucVu;

    for(int i = 0; i < n; i++) {
        readFile >> maPhong >> soDem;
        if(i < d) {
            readFile >> phiDichVu >> phiPhucVu;
            khachSan[i] = new Deluxe(maPhong, soDem, phiDichVu, phiPhucVu);
        }  
        else if(i < d + p) {
            readFile >> phiDichVu;
            khachSan[i] = new Premium(maPhong, soDem, phiDichVu);
        } 
        else {
            khachSan[i] = new Business(maPhong, soDem);
        }
    }

    readFile.close();

    ofstream writeFile;
    writeFile.open(linkWriteFile);
    if(writeFile.fail()) {
        cout << "Khong the mo file de ghi\n";
        return -1;
    }

    double tongDoanhThuLoaiPhongDeluxe = 0.0;
    double tongDoanhThuLoaiPhongPremium = 0.0;
    double tongDoanhThuLoaiPhongBusiness = 0.0;
    int soPhongVuotTroi = 0;

    double (LoaiKhachSan::*ptr)() const = LoaiKhachSan::doanhThuPhong;
    for(int i = 0; i < n; i++) {
        const string str = khachSan[i]->getMaPhong().substr(0, 2);
        double doanhThuPhong = (khachSan[i]->*ptr)();
        double doanhThuThangTruoc = INT_MAX;
        if(i != 0) {
            doanhThuThangTruoc = (khachSan[i - 1]->*ptr)();
        }
        if(str == "DE") {
            tongDoanhThuLoaiPhongDeluxe += doanhThuPhong;
        }
        else if(str == "PE") {
            tongDoanhThuLoaiPhongPremium += doanhThuPhong;
        }
        else if(str == "BU") {
            tongDoanhThuLoaiPhongBusiness += doanhThuPhong;
        }
        if(i != 0 && i != d && i != d + p) {
            if(doanhThuPhong > doanhThuThangTruoc * 1.25) {
                soPhongVuotTroi++;
                khachSan[i]->setPhongVuotTroi(true);
            }
        }
    }
    writeFile << tongDoanhThuLoaiPhongDeluxe << "\n";
    writeFile << tongDoanhThuLoaiPhongPremium << "\n";
    writeFile << tongDoanhThuLoaiPhongBusiness << "\n";

    writeFile << soPhongVuotTroi << "\n";
    for(int i = 0; i < n; i++) {
        if(khachSan[i]->getPhongVuotTroi()) {
            const string str = khachSan[i]->getMaPhong();
            writeFile << str << "\n";
        }
    }

    writeFile.close();

    for(int i = 0; i < n; i++) {
        delete khachSan[i];
    }
    delete []khachSan;
    return 0;
}