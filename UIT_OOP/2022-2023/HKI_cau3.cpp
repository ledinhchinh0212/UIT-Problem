#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class KhachHang {
private:
    string maKhachHang;
    string tenKhachHang;
    string soDienThoai;
public:
    KhachHang(string maKhacHang, string tenKhachHang, string soDienThoai) {
        this->maKhachHang = maKhacHang;
        this->tenKhachHang = tenKhachHang;
        this->soDienThoai = soDienThoai;
    }

    string getSoDienThoai() {
        return this->soDienThoai;
    }

    void ThongTinKhachHang() {
        cout << "Ma khach hang: " << maKhachHang << "\n";
        cout << "Ten khach hang: " << tenKhachHang << "\n";
        cout << "So dien thoai khach hang: " << soDienThoai << "\n";
    }
};

class SanPham {
protected:
    string tenSanPham;
    int maSo;
    string tieuDe;
    long long giaBan;
public:
    SanPham(int maSo, string tieuDe, long long giaBan) {
        this->maSo = maSo;
        this->tieuDe = tieuDe;
        this->giaBan = giaBan;
    }

    string getTenSanPham() {
        return tenSanPham;
    }

    virtual void ThongTinSanPham() = 0; 
};

class TranhAnh : public SanPham {
private:
    float chieuRong;
    float chieuCao;
    string tenHoaSi;
public:
    TranhAnh(int maSo, string tieuDe, long long giaBan, float chieuRong, float chieuCao, string tenHoaSi) :
    SanPham(maSo, tieuDe, giaBan){
        this->chieuRong = chieuRong;
        this->chieuCao = chieuCao;
        this->tenHoaSi = tenHoaSi;
        this->tenSanPham = "Tranh Anh";
    }

    void ThongTinSanPham() override {
        cout << "Ten san pham: " << tenSanPham << "\n";
        cout << "Ma so: " << maSo << "\n";
        cout << "Tieu de: " << tieuDe << "\n";
        cout << "Gia ban: " << giaBan << "\n";
        cout << "Kich thuoc: " << chieuRong << "x" << chieuCao << "\n";
        cout << "Ten hoa si: " << tenHoaSi << "\n";
    }
};

class CDAmNhac : public SanPham {
private:
    string tenCaSi;
    string tenDonViSanXuat;
public:
    CDAmNhac(int maSo, string tieuDe, long long giaBan, string tenCaSi, string tenDonViSanXuat) :
    SanPham(maSo, tieuDe, giaBan){
        this->tenCaSi = tenCaSi;
        this->tenDonViSanXuat = tenDonViSanXuat;
        this->tenSanPham = "CD am nhac";
    }

    void ThongTinSanPham() override {
        cout << "Ten san pham: " << tenSanPham << "\n";
        cout << "Ma so: " << maSo << "\n";
        cout << "Tieu de: " << tieuDe << "\n";
        cout << "Gia ban: " << giaBan << "\n";
        cout << "Ten ca si: " << tenCaSi << "\n";
        cout << "Ten don vi san xuat: " << tenDonViSanXuat << "\n";
    }
};

class HoaDon {
private:
    string maHoaDon; 
    KhachHang *thongTinKhachHang;
    string ngayLapHoaDon;
    SanPham *danhSachSanPham;
    long long tongGia;
public:
    HoaDon(string maHoaDon, KhachHang *thongTinKhachHang, string ngayLapHoaDon, SanPham *danhSachSanPham, long long tongGia) {
        this->maHoaDon = maHoaDon; 
        this->thongTinKhachHang = thongTinKhachHang;
        this->ngayLapHoaDon = ngayLapHoaDon;
        this->danhSachSanPham = danhSachSanPham;
        this->tongGia = tongGia;
    }

    KhachHang* getThongTinKhachHang() {
        return thongTinKhachHang;
    }

    void ThongTinHoaDon() {
        danhSachSanPham->ThongTinSanPham();
    }

    long long getTongGia() {
        return tongGia;
    }

    static long long TongThuNhapCuaHang(vector<HoaDon*> &hoadon) {
        long long money = 0;
        for(int i = 0; i < hoadon.size(); i++) {
            money = money + hoadon[i]->getTongGia();
        }
        
        return money;
    }

    static void KhachHangMuaNhieuNhat(vector<HoaDon*> &hoadon) {
        map<KhachHang*, long long> store;

        for(int i = 0; i < hoadon.size(); i++) {
            KhachHang *khachHang = hoadon[i]->getThongTinKhachHang();  
            store[khachHang] += hoadon[i]->getTongGia();
        }
        long long money = -1;
        KhachHang* kh = nullptr;
        for(const auto &x : store) {
            if(x.second > money) {
                money = x.second;
                kh = x.first;
            }
        }
        
        if(kh != nullptr) {
            kh->ThongTinKhachHang();
            cout << "\n";
        }
        else {
            cout << "khong co khach hang nao ca\n";
        }
    }
};

int main() {

    vector<HoaDon*> hoadon;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Nhap ma hoa don: "; string maHoaDon;
        cin >> maHoaDon;
        cout << "Nhap ma khach hang: "; string maKhachHang;
        cin >> maKhachHang;
        cin.ignore();
        cout << "Nhap ten khach hang: "; string tenKhachHang;
        getline(cin, tenKhachHang);
        cout << "Nhap so dien thoai khach hang: "; string soDienThoai;
        cin >> soDienThoai;
        cout << "Nhap ngay lap hoa don: "; string ngayLapHoaDon;
        cin >> ngayLapHoaDon;
        cout << "Nhap tong gia: "; long long tongGia;
        cin >> tongGia;
        cout << "Nhap ten san pham: "; string tenSanPham;
        cin.ignore();
        getline(cin, tenSanPham);
        cout << "Nhap maso: "; int maSo;
        cin >> maSo;
        cin.ignore();
        cout << "Nhap tieu de: "; string tieuDe;
        getline(cin, tieuDe);
        cout << "Nhap gia ban: "; long long giaBan;
        cin >> giaBan;
        cin.ignore();
        if(tenSanPham == "Tranh anh") {
            cout << "Nhap chieu rong buc anh: "; float chieuRong;
            cin >> chieuRong;
            cout << "Nhap chieu cao buc anh: "; float chieuCao;
            cin >> chieuCao;
            cout << "Nhap ten hoa si: "; string tenHoaSi;
            cin.ignore();
            getline(cin, tenHoaSi);
            hoadon.push_back(new HoaDon(maHoaDon, new KhachHang(maKhachHang, tenKhachHang, soDienThoai), ngayLapHoaDon,
                             new TranhAnh(maSo, tieuDe, giaBan, chieuRong, chieuCao, tenHoaSi), tongGia));
        }
        else if(tenSanPham == "CD am nhac") {
            cout << "Nhap ten ca si: "; string tenCaSi;
            cin.ignore();
            getline(cin, tenCaSi);
            cout << "Nhap ten don vi san xuat: "; string tenDonViSanXuat;
            getline(cin, tenDonViSanXuat);
            hoadon.push_back(new HoaDon(maHoaDon, new KhachHang(maKhachHang, tenKhachHang, soDienThoai), ngayLapHoaDon,
                             new CDAmNhac(maSo, tieuDe, giaBan, tenCaSi, tenDonViSanXuat), tongGia));
        }
    }

// in thong tin moi hoa don
    for(int i = 0; i < n; i++) {
        hoadon[i]->ThongTinHoaDon();
    }
//
    cout << "###########\n";
    cout << HoaDon::TongThuNhapCuaHang(hoadon) << "\n";
//
    HoaDon::KhachHangMuaNhieuNhat(hoadon);

    for(int i = 0; i < n; i++) {
        delete hoadon[i];
    }

    return 0;
}