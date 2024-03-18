#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class NhomMau {
protected:
    vector<string> nhomMauCho;
    vector<string> nhomMauNhan;
    string tenNhomMau;
    char khangNguyenD;
public:
    void inDanhSachNhomMau() {
        for(int i = 0; i < nhomMauNhan.size(); i++) {
            cout << nhomMauNhan[i] << " ";
        }
    }
    
    char getKhangNguyen() {
        return khangNguyenD;
    }

    string getTenNhomMau() {
        return tenNhomMau;
    }

    virtual vector<string> getNhomMauCho() {
        return nhomMauCho;
    }

    virtual vector<string> getNhomMauNhan() {
        return nhomMauNhan;
    }

};

class NhomMauA : public NhomMau {
public:
    NhomMauA(char khangNguyenD = '0') {
        tenNhomMau = "A";
        this->khangNguyenD = khangNguyenD;
        nhomMauCho.push_back("A");
        nhomMauCho.push_back("AB");

        nhomMauNhan.push_back("A");
        nhomMauNhan.push_back("O");
    }
    vector<string> getNhomMauCho() {
        return nhomMauCho;
    }

    vector<string> getNhomMauNhan() {
        return nhomMauNhan;
    }
};

class NhomMauB : public NhomMau {
public:
    NhomMauB(char khangNguyenD = '0') {
        tenNhomMau = "B";
        this->khangNguyenD = khangNguyenD;
        nhomMauCho.push_back("B");
        nhomMauCho.push_back("AB");

        nhomMauNhan.push_back("B");
        nhomMauNhan.push_back("O");
    }
    vector<string> getNhomMauCho() {
        return nhomMauCho;
    }

    vector<string> getNhomMauNhan() {
        return nhomMauNhan;
    }
};

class NhomMauAB : public NhomMau {
public:
    NhomMauAB(char khangNguyenD = '0') {
        tenNhomMau = "AB";
        this->khangNguyenD = khangNguyenD;
        nhomMauCho.push_back("AB");

        nhomMauNhan.push_back("A");
        nhomMauNhan.push_back("B");
        nhomMauNhan.push_back("AB");
        nhomMauNhan.push_back("O");
    }
    vector<string> getNhomMauCho() {
        return nhomMauCho;
    }

    vector<string> getNhomMauNhan() {
        return nhomMauNhan;
    }
};


class NhomMauO : public NhomMau {
public:
    NhomMauO(char khangNguyenD = '0') {
        tenNhomMau = "O";
        this->khangNguyenD = khangNguyenD;
        nhomMauCho.push_back("AB");
        nhomMauCho.push_back("A");
        nhomMauCho.push_back("A");
        nhomMauCho.push_back("O");

        nhomMauNhan.push_back("O");
    }
    vector<string> getNhomMauNhan() {
        return nhomMauNhan;
    }
    vector<string> getNhomMauCho() {
        return nhomMauCho;
    }
};



bool KiemTraQuyLuatDiTruyen(NhomMau *&nguoiBo, NhomMau *&nguoiMe, NhomMau *&nguoiCon) {
    string tenNhomMau1 = nguoiBo->getTenNhomMau();
    string tenNhomMau2 = nguoiMe->getTenNhomMau();  
    string tenNhomMauNguoiCon = nguoiCon->getTenNhomMau();
    
    if(tenNhomMauNguoiCon == "O") {
        if(tenNhomMau1 == "AB" || tenNhomMau2 == "AB") {
            return false;
        }
        return true;
    }

    //
    string khanang1 = "", khanang2 = "", khanang3 = "", khanang4 = "";
    if(tenNhomMau1 == "AB" || tenNhomMau2 == "AB") {
        khanang1 = "A"; khanang2 = "B";
        if(tenNhomMau1 != "O" && tenNhomMau2 != "O") {
            khanang3 = "AB";
        }
    }
    else if(tenNhomMau1 == "O" || tenNhomMau2 == "O") {
        if(tenNhomMau1 == "AB" || tenNhomMau2 == "AB") {
            khanang1 = "A"; khanang2 = "B";
        }
        else {
            khanang1 = "O";
            khanang2 = (tenNhomMau1 == "O") ? tenNhomMau2 : tenNhomMau1;
        }
    }
    else {
        khanang1 = tenNhomMau1;
        khanang2 = tenNhomMau2;
        if(khanang1 != khanang2) {
            khanang3 = khanang1 + khanang2;
        }
        khanang4 = "O";
    }
    //
    if(tenNhomMauNguoiCon == khanang1 || tenNhomMauNguoiCon == khanang2 || tenNhomMauNguoiCon == khanang3 ||
        tenNhomMauNguoiCon == khanang4) {
            return true;
        }

    return false;
}

void LietKeNguoiCoTheChoMau(vector<NhomMau*> &mau, int N, int indexN) {
    vector<string> check = mau[indexN]->getNhomMauNhan();

    for(int i = 0; i < N; i++) {
        for(int j = 0;  j < check.size(); j++) {
            if(mau[i]->getTenNhomMau() == check[j]) {
                if(mau[i]->getKhangNguyen() == '+') { // người cho
                    if(mau[indexN]->getKhangNguyen() == '-') { // người nhận
                        continue;
                    }
                    else {
                        cout << mau[i]->getTenNhomMau() << mau[i]->getKhangNguyen() << "\n";
                    }
                }
                else {
                    cout << mau[i]->getTenNhomMau() << mau[i]->getKhangNguyen() << "\n";
                }
            }
        }
    }

}

int main() {
    // Lập danh sách các nhóm máu của một nhóm người
    int num;
    cin >> num;
    vector<NhomMau*> mau;
    for(int i = 0; i < num; i++) {
        cout << "Nguoi thu " << i + 1 << ":\n";
        cout << "Nhap nhom mau:\n";
        string nhomMau;
        cin >> nhomMau;
        cout << "Nhap khang nguyen:\n";
        char khangNguyen;
        cin >> khangNguyen;
        if(nhomMau == "O") {
            mau.push_back(new NhomMauO(khangNguyen));
        }
        else if(nhomMau == "A") {
            mau.push_back(new NhomMauA(khangNguyen));
        }
        else if(nhomMau == "B") {
            mau.push_back(new NhomMauB(khangNguyen));
        }
        else if(nhomMau == "AB") {
            mau.push_back(new NhomMauAB(khangNguyen));
        }
    }
    // kiểm tra nhóm máu phù hợp với quy luật di truyền
    NhomMau* nguoiBo = new NhomMauB();
    NhomMau* nguoiMe = new NhomMauAB();
    NhomMau* nguoicon = new NhomMauO();
    if(KiemTraQuyLuatDiTruyen(nguoiBo, nguoiMe, nguoicon)) {
        cout << "Nhom mau phu hop voi quy luat di truyen\n";
    }
    else cout << "Nhom mau khong phu hop voi quy luat di truyen\n";

    // liệt kê người có thể cho máu

    LietKeNguoiCoTheChoMau(mau, num, 1);

    delete nguoiBo;
    delete nguoiMe;
    delete nguoicon;

    for(int i = 0; i < num; i++) {
        delete mau[i];
    }

    return 0;
}