#include <iostream>
#include <cmath>

using namespace std;

class Hinh {
protected:
    string tenLoaiHinh;
public:
    string getTenLoaiHinh() const;
    virtual float dienTich() const = 0;
    virtual float chuVi() const = 0;
};

string Hinh::getTenLoaiHinh() const {
    return tenLoaiHinh;
}

class HinhChuNhat : public Hinh {
private:
    float chieuDai;
    float chieuRong;
public:
    HinhChuNhat(float chieuDai, float chieuRong);
    float dienTich() const override;
    float chuVi() const override;
};

HinhChuNhat::HinhChuNhat(float chieuDai, float chieuRong) {
    this->chieuDai = chieuDai;
    this->chieuRong = chieuRong;
    this->tenLoaiHinh = "Hinh chu nhat";
}

float HinhChuNhat::dienTich() const {
    return chieuDai * chieuRong;
}

float HinhChuNhat::chuVi() const {
    return 2.0 * (chieuDai + chieuRong);
}

class HinhTamGiac : public Hinh {
private:
    float x, y, z;
public:
    HinhTamGiac(float x, float y, float z);
    float dienTich() const override;
    float chuVi() const override;
};

HinhTamGiac::HinhTamGiac(float x, float y, float z) : x(x), y(y), z(z) {
    this->tenLoaiHinh = "Hinh tam giac";
}

float HinhTamGiac::dienTich() const {
    float s = (x + y + z)/2.0;
    return sqrt(s * (s - x) * (s - y) * (s - z));
}

float HinhTamGiac::chuVi() const {
    return x + y + z;
}

class HinhTron : public Hinh {
private:
    const float PI;
    float banKinh;
public:
    HinhTron(float banKinh);
    float dienTich() const override;
    float chuVi() const override;
};

HinhTron::HinhTron(float banKinh) : PI(3.1415) {
    this->banKinh = banKinh;
    this->tenLoaiHinh = "Hinh tron";
}

float HinhTron::dienTich() const {
    return PI * banKinh * banKinh;
}

float HinhTron::chuVi() const {
    return 2 * PI * banKinh;
}

void Menu() {
    cout << "1. Nhap kich thuoc cac hinh\n";
    cout << "2. Hien thi dien tich va chu vi da nhap\n";
    cout << "3. Ket thuc chuong trinh\n";
}

void ChonHinh() {
    cout << "1. Hinh chu nhat\n";
    cout << "2. Hinh tam giac\n";
    cout << "3. Hinh tron\n";
}

int main() {
    const int n = 3;
    Hinh **hinh = new Hinh*[n];
    for(int i = 0; i < n; i++) {
        hinh[i] = nullptr;
    }
    int choose = 0;
    do {
        Menu();
        cin >> choose;
        if(choose == 1) {
            system("cls");
            cout << "Chon hinh muon nhap:\n\n";
            ChonHinh();
            int choose1; cin >> choose1;
            if(choose1 == 1) {
                cout << "Nhap chieu dai va chieu rong tuong ung: ";
                float chieuDai, chieuRong;
                cin >> chieuDai >> chieuRong;
                if(hinh[0] != nullptr) {
                    delete hinh[0];
                    hinh[0] = nullptr;
                }
                hinh[0] = new HinhChuNhat(chieuDai, chieuRong);
            }
            else if(choose1 == 2) {
                cout << "Nhap 3 canh cua tam giac tuong ung: ";
                float x, y, z;
                cin >> x >> y >> z;
                if(hinh[1] != nullptr) {
                    delete hinh[1];
                    hinh[1] = nullptr;
                }
                hinh[1] = new HinhTamGiac(x, y, z);
            }
            else if(choose1 == 3) {
                cout << "Nhap ban kinh hinh tron: ";
                float banKinh; cin >> banKinh;
                if(hinh[2] != nullptr) {
                    delete hinh[2];
                    hinh[2] = nullptr;
                }
                hinh[2] = new HinhTron(banKinh);
            }
        }
        else if(choose == 2) {
            system("cls");
            for(int i = 0; i < n; i++) {
                if(hinh[i] != nullptr) {
                    cout << hinh[i]->getTenLoaiHinh() << ":\n";
                    cout << "Dien tich: " << hinh[i]->dienTich() << "\n";
                    cout << "Chu vi: " << hinh[i]->chuVi() << "\n\n";
                }
            }
        }
        else if(choose == 3) {
            for(int i = 0; i < n; i++) {
                if(hinh[i] != nullptr) {
                    delete hinh[i];
                    hinh[i] = nullptr;
                }
            }
            continue;
        }
    }
    while(choose != 3);

    delete []hinh;

    return 0;
}