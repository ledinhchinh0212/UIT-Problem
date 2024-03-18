/*
    code này làm hơi ẩu vì chưa test lần nào
    vì chỉ code thôi..
    Vấn đề về sai sót hay muốn góp ý thì 
    liền hệ.. Cảm ơn !

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NguoiSoHuu {
private:
    string hoTen;
    int namSinh;
    int CMND;
    string diaChiThuongTru;
public:
    NguoiSoHuu(string hoTen, int namSinh, int CMND, string diaChiThuongTru) {
        this->hoTen = hoTen;
        this->namSinh = namSinh;
        this->CMND = CMND;
        this->diaChiThuongTru = diaChiThuongTru;
    }
    string getHoTen() {
        return hoTen;
    }
    
    int getNamSinh() {
        return namSinh;
    }
    
    int getCMND() {
        return CMND;
    }

    string getDiaChiThuongTru() {
        return diaChiThuongTru;
    }
};

class GiaySuDungDat {
protected:
    string soGiayChungNhan;
    int soThuaDat;
    int soToBanDo;
    string diaChiThuaDat;
    float dienTich;
    string ngayCap;
    float thue;
    NguoiSoHuu *nguoiSoHuu;
    string tenLoaiDat;
    string thoiHanSuDung;
public:
    virtual ~GiaySuDungDat() {
        delete nguoiSoHuu;
    }

    GiaySuDungDat(string soGiayChungNhan, int soThuaDat, int soToBanDo, string diaChiThuaDat,
    float dienTich, string ngayCap, float thue, NguoiSoHuu *nguoiSoHuu) { // dd/mm/yyyy
        this->soGiayChungNhan = soGiayChungNhan;
        this->soThuaDat = soThuaDat;
        this->soToBanDo = soToBanDo;
        this->diaChiThuaDat = diaChiThuaDat;
        this->dienTich = dienTich;
        this->ngayCap = ngayCap;
        this->thue = thue;
        this->nguoiSoHuu = nguoiSoHuu;
    }
    string getNgayCap() {
        return ngayCap;
    }

    float TinhTienThue() {
        return this->thue * this->dienTich;
    }

    virtual void InThongTinDat() = 0;

    string getTenLoaiDat() {
        return tenLoaiDat;
    }

    string getThoiHanSuDung() {
        return thoiHanSuDung;
    }
    
    static void ThuaDatNongNghiepHetThoiHan(vector<GiaySuDungDat*> giaysudungdat, int N) {
        int orginalYear = 2024;
        for(int i = 0; i < N; i++) {
            if(giaysudungdat[i]->getTenLoaiDat() == "Dat nong nghiep") {
                int thoiHanSuDung =  stoi(giaysudungdat[i]->getThoiHanSuDung());
                int ngayCap = stoi(giaysudungdat[i]->getNgayCap().substr(6));
                
                if(thoiHanSuDung + ngayCap > orginalYear) {
                    giaysudungdat[i]->InThongTinDat();
                }
            }
        }
    }

    static void ThuaDatDongNhieuTienNhat(vector<GiaySuDungDat*> giaysudungdat, int N) {
        float max = 0;
        int index = 0;
        for(int i = 0; i < N; i++) {
            float thue = giaysudungdat[i]->TinhTienThue();
            if(thue > max) {
                max = thue;
                index = i;
            }
        }
        giaysudungdat[index]->InThongTinDat();
    }
};

class GiaySuDungDatNongNghiep : public GiaySuDungDat {
public:
    GiaySuDungDatNongNghiep(string soGiayChungNhan, int soThuaDat, int soToBanDo, string diaChiThuaDat,
                    float dienTich, string ngayCap, float thue, NguoiSoHuu *nguoiSoHuu, string thoiHanSuDung) 
                    : GiaySuDungDat(soGiayChungNhan, soThuaDat, soToBanDo, diaChiThuaDat, dienTich, ngayCap, thue, nguoiSoHuu) {
    this->thoiHanSuDung = thoiHanSuDung;
    this->tenLoaiDat = "Dat nong nghiep";
    }

    void InThongTinDat() override {
        cout << soGiayChungNhan << "\n";
        cout << soThuaDat << "\n";
        cout << soToBanDo << "\n";
        cout << diaChiThuaDat << "\n";
        cout << dienTich << "\n";
        cout << ngayCap << "\n";
        cout << thue << "\n";
        cout << nguoiSoHuu->getHoTen() << "\n";
        cout << nguoiSoHuu->getCMND() << "\n";
        cout << nguoiSoHuu->getNamSinh() << "\n";
        cout << nguoiSoHuu->getDiaChiThuongTru() << "\n";
        cout << thoiHanSuDung << "\n";
    }
};


class GiaySuDungDatPhiNongNghiep : public GiaySuDungDat {
public:
    GiaySuDungDatPhiNongNghiep(string soGiayChungNhan, int soThuaDat, int soToBanDo, string diaChiThuaDat,
                    float dienTich, string ngayCap, float thue, NguoiSoHuu *nguoiSoHuu) 
                    : GiaySuDungDat(soGiayChungNhan, soThuaDat, soToBanDo, diaChiThuaDat, dienTich, ngayCap, thue, nguoiSoHuu) {
        this->tenLoaiDat = "Dat phi nong nghiep";
    }

    void InThongTinDat() override {
        cout << soGiayChungNhan << "\n";
        cout << soThuaDat << "\n";
        cout << soToBanDo << "\n";
        cout << diaChiThuaDat << "\n";
        cout << dienTich << "\n";
        cout << ngayCap << "\n";
        cout << thue << "\n";
        cout << nguoiSoHuu->getHoTen() << "\n";
        cout << nguoiSoHuu->getCMND() << "\n";
        cout << nguoiSoHuu->getNamSinh() << "\n";
        cout << nguoiSoHuu->getDiaChiThuongTru() << "\n";
    }
};

int main() {

    int N;
    cin >> N;
    vector<GiaySuDungDat*> giaysudungdat;

    for(int i = 0; i < N; i++) {
        cout << "Nhap loai giay muon su dung, 1: dat nong ngiep, 2: dat phi nong nghiep\n";
        int type; cin >> type;
        cin.ignore();
        string soGiayChungNhan;
        getline(cin, soGiayChungNhan);
        int soThuaDat;
        cin >> soThuaDat;
        int soToBanDo;
        cin >> soToBanDo;
        cin.ignore();
        string diaChiThuaDat;
        getline(cin, diaChiThuaDat);
        float dienTich;
        cin >> dienTich;
        cin.ignore();
        string ngayCap;
        getline(cin, ngayCap);
        float thue;
        cin >> thue;
        cin.ignore();
        string name;
        getline(cin, name);
        int namSinh;
        cin >> namSinh;
        int CMND;
        cin >> CMND;
        cin.ignore();
        string diaChiThuongTru;
        getline(cin, diaChiThuongTru);
        if(type == 1) {
            string thoiHanSuDung;
            getline(cin, thoiHanSuDung);
            giaysudungdat.push_back(new GiaySuDungDatNongNghiep(soGiayChungNhan, soThuaDat, soToBanDo, diaChiThuaDat,
                                        dienTich, ngayCap, thue, new NguoiSoHuu(name, namSinh, CMND, diaChiThuongTru), thoiHanSuDung));
        }  
        else {
            giaysudungdat.push_back(new GiaySuDungDatPhiNongNghiep(soGiayChungNhan, soThuaDat, soToBanDo, diaChiThuaDat,
                                        dienTich, ngayCap, thue, new NguoiSoHuu(name, namSinh, CMND, diaChiThuongTru)));
        }     
    }

    // 
    GiaySuDungDat::ThuaDatDongNhieuTienNhat(giaysudungdat, N);
    //
    cout << "--------------\n";

    GiaySuDungDat::ThuaDatNongNghiepHetThoiHan(giaysudungdat, N);

    for(int i = 0; i < N; i++) {
        delete giaysudungdat[i];
    }

    return 0;
}