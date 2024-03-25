#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sach {
protected:
    string maSach;
    string tenSach;
    string nhaXuatBan;
    int soLuong;
    double donGia;
public:
    Sach(string maSach, string tenSach, string nhaXuatBan, int soLuong, double donGia) {
        this->maSach = maSach;
        this->tenSach = tenSach;
        this->nhaXuatBan = nhaXuatBan;
        this->soLuong = soLuong;
        this->donGia = donGia;
    }

    virtual double ThanhTien() = 0;
    
    virtual void InThongTinSach() {
        cout << "Ma sach: " << maSach << "\n";
        cout << "Ten sach: " << tenSach << "\n";
        cout << "Nha xuat ban: " << nhaXuatBan << "\n";
        cout << "So luong: " << soLuong << "\n";
        cout << "Don gia: " << donGia << "\n";
    }
    static void SachCoThanhTienItNhat(const vector<Sach*> &sach) {
        int min = sach[0]->ThanhTien();
        for(int i = 0; i < sach.size(); i++) {
            int money = sach[i]->ThanhTien();
            if(money < min) {
                min = money;
            }
        }

        for(int i = 0; i < sach.size(); i++) {
            if(sach[i]->ThanhTien() == min) {
                sach[i]->InThongTinSach();
                cout << "###############\n";
            }
        }
    }
};

class SachGiaoKhoa : public Sach {
private:
    int tinhTrang; // 0: cu, 1: moi
public:
    SachGiaoKhoa(string maSach, string tenSach, string nhaXuatBan, int soLuong, double donGia, int tinhTrang) :
    Sach(maSach, tenSach, nhaXuatBan, soLuong, donGia){
        this->tinhTrang = tinhTrang;
    }

    double ThanhTien() override {
        if(tinhTrang == 1) {
            return soLuong * donGia;
        }
        return soLuong * donGia * 0.5;
    }
    void InThongTinSach() {
        Sach::InThongTinSach();
        cout << "Tinh trang: ";
        if(tinhTrang == 0) {
            cout << "cu\n";
        }
        else cout << "moi\n";
    }
};

class SachThamKhao : public Sach {
private:
    double tienThue;
public:
    SachThamKhao(string maSach, string tenSach, string nhaXuatBan, int soLuong, double donGia, double tienThue) :
    Sach(maSach, tenSach, nhaXuatBan, soLuong, donGia){
        this->tienThue = tienThue;
    }

    double ThanhTien() override {
        return soLuong * donGia + tienThue;
    }

    void InThongTinSach() {
        Sach::InThongTinSach();
        cout << "Thue: "<< tienThue << "\n";
    }
};

int main() {

    vector<Sach*> sach;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "1: Sach giao khoa, 2: Sach tham khao\n";
        int type;
        cin >> type;
        string maSach;
        cin >> maSach;
        cin.ignore();
        string tenSach;
        getline(cin, tenSach);
        string nhaXuatBan;
        getline(cin, nhaXuatBan);
        int soLuong;
        cin >> soLuong;
        double donGia;
        cin >> donGia;
        if(type == 1) {
            int tinhTrang; 
            cin >> tinhTrang;
            sach.push_back(new SachGiaoKhoa(maSach, tenSach, nhaXuatBan, soLuong, donGia, tinhTrang));
        }
        else if(type == 2) {
            double tienThue;
            cin >> tienThue;
            sach.push_back(new SachThamKhao(maSach, tenSach, nhaXuatBan, soLuong, donGia, tienThue));
        }
    }
    // in thong tin sach ca truong va thanh tien
    for(int i = 0; i < n; i++) {
        sach[i]->InThongTinSach();
        sach[i]->ThanhTien();
        cout << "#################\n";
    }
    // in sach co thanh tien it nhat
    Sach::SachCoThanhTienItNhat(sach);

    for(int i = 0; i < n; i++) {
        delete sach[i];
    }

    return 0;
}