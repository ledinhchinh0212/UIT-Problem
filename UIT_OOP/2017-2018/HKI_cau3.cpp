#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CaSy {
protected:
    string hoTen;
    int soNamLamViec;
    int soDiaBanDuoc;
    int soBuoiTrinhDienThamGia;
    virtual int Luong() = 0;
public:
    CaSy(string hoTen, int soNamLamViec, int soDiaBanDuoc, int soBuoiTrinhDienThamGia) {
        this->hoTen = hoTen;
        this->soNamLamViec = soNamLamViec;
        this->soDiaBanDuoc = soDiaBanDuoc;
        this->soBuoiTrinhDienThamGia = soBuoiTrinhDienThamGia;
    }
    int getLuong() {
        return Luong();
    }
    string getHoTen() {
        return hoTen;
    }
};

class CaSyChuaNoiTieng : public CaSy{
public:
    int Luong() override {
        return 3000000 + 500000 * soNamLamViec + 1000 * soDiaBanDuoc + 200000 * soBuoiTrinhDienThamGia;
    }
    CaSyChuaNoiTieng(string hoTen, int soNamLamViec, int soDiaBanDuoc, int soBuoiTrinhDienThamGia)
    : CaSy(hoTen, soNamLamViec, soDiaBanDuoc, soBuoiTrinhDienThamGia){}
};

class CaSyNoiTieng : public CaSy{
private:
    int soGameShow;
public:
    int Luong() override {
        return 5000000 + 500000 * soNamLamViec + 1200 * soDiaBanDuoc + 500000 * soBuoiTrinhDienThamGia
        + 500000 * soGameShow;
    }
    CaSyNoiTieng(string hoTen, int soNamLamViec, int soDiaBanDuoc, int soBuoiTrinhDienThamGia, int soGameShow) 
    : CaSy(hoTen, soNamLamViec, soDiaBanDuoc, soBuoiTrinhDienThamGia), soGameShow(soGameShow){}
};  

void CaSyLuongCaoNhat(vector<CaSy*> &casi) {
    int max = (casi.empty()) ? -1 : casi[0]->getLuong();
    for(int i = 0; i < casi.size(); i++) {
        int luong = casi[i]->getLuong();
        if(luong > max) {
            max = luong;
        }
    }
    for(auto cs : casi) {
        if(cs->getLuong() == max) {
            cout << "Ca si: " << cs->getHoTen() << "\n";
            cout << "Luong: " << cs->getLuong() << "\n";
            break;
        }
    }
}

int main() {

    int num;
    cin >> num;

    vector<CaSy*> casi(num);

    for(int i = 0; i < num; i++) {
        cout << "1: Ca si noi tieng, 2: Ca si chua noi tieng:\n";
        int type;
        cin >> type;
        cin.ignore();
        cout << "Ho ten ca si: ";
        string name;
        getline(cin, name);
        cout << "So nam lam viec cho cong ty: ";
        int namLamViec;
        cin >> namLamViec;
        cout << "So dia ban duoc: ";
        int soDiaBan;
        cin >> soDiaBan;
        cout << "So buoi trinh dien da tham gia: ";
        int soBuoiTrinhDien;
        cin >> soBuoiTrinhDien;
        if(type == 1) {
            cout << "so GameShow da tham gia: ";
            int soGameShow;
            cin >> soGameShow;
            casi.push_back(new CaSyNoiTieng(name, namLamViec, soDiaBan, soBuoiTrinhDien, soGameShow));
        }
        else if(type == 2) {
            casi.push_back(new CaSyChuaNoiTieng(name, namLamViec, soDiaBan, soBuoiTrinhDien));
        }
    }

    CaSyLuongCaoNhat(casi);

    for(int i = 0; i < num; i++) {
        delete casi[i];
    }

    return 0;
}