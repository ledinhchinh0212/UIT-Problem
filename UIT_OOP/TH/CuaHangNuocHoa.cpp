#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KhachHang {               // khach hang
private:
    string maKhachHang;
    string tenKhachHang;
    string diaChi;
    string soDienThoai;
public:
    KhachHang(string maKhachHang, string tenKhachHang, string diaChi, string soDienThoai) {
        this->maKhachHang = maKhachHang;
        this->tenKhachHang = tenKhachHang;
        this->diaChi = diaChi;
        this->soDienThoai = soDienThoai;
    }

    string getMaKhachHang() {
        return maKhachHang;
    }

    string getTenKhachHang() {
        return tenKhachHang;
    }

    string getdiaChiKhachHang() {
        return diaChi;
    }

    string getSoDienThoai() {
        return soDienThoai;
    }
};

class NuocHoa {
protected:
    string maSoNuocHoa;
    string loaiNuocHoa;
    float dungTich;
public:
    NuocHoa(string maSoNuocHoa, string loaiNuocHoa, float dungTich) {
        this->maSoNuocHoa = maSoNuocHoa;
        this->loaiNuocHoa = loaiNuocHoa;
        this->dungTich = dungTich;
    }

    string getMaSoNuocHoa() {
        return maSoNuocHoa;
    }

    string getLoaiNuocHoa() {
        return loaiNuocHoa;
    }

    float getDungTich() {
        return dungTich;
    }

    virtual double GiaTien() const = 0;
};

class NuocHoaHong : public NuocHoa {
public:
    NuocHoaHong(string maSoNuocHoa, string loaiNuocHoa, float dungTich) :
    NuocHoa(maSoNuocHoa, loaiNuocHoa, dungTich) {}

    double GiaTien() const override {
        return dungTich * 20;
    }
};

class NuocHoaCuc : public NuocHoa {
public:
    NuocHoaCuc(string maSoNuocHoa, string loaiNuocHoa, float dungTich) :
    NuocHoa(maSoNuocHoa, loaiNuocHoa, dungTich) {}

    double GiaTien() const override {
        return dungTich * 15;
    }
};

class DauGoiDau {
protected:
    string maSoDauGoiDau;
    string loaiDauGoiDau;
    float dungTich;
public:
    DauGoiDau(string maSoDauGoiDau, string loaiDauGoiDau, float dungTich) {
        this->maSoDauGoiDau = maSoDauGoiDau;
        this->loaiDauGoiDau = loaiDauGoiDau;
        this->dungTich = dungTich;
    }

    string getMaSoDauGoiDau() {
        return maSoDauGoiDau;
    }

    string getLoaiDauGoiDau() {
        return loaiDauGoiDau;
    }

    float getDungTich() {
        return dungTich;
    }

    virtual int getTieuChuanKiemDinh() {
        return 0;
    }

    virtual double GiaTien() const = 0;
};

class DauGoiTocKho : public DauGoiDau {
public:
    DauGoiTocKho(string maSoDauGoiDau, string loaiDauGoiDau, float dungTich) :
    DauGoiDau(maSoDauGoiDau, loaiDauGoiDau, dungTich) {}

    double GiaTien() const override {
        return dungTich * 20;
    }
};

class DauGoiTocDau : public DauGoiDau {
private:
    int tieuChuanKiemDinh;
public:
    DauGoiTocDau(string maSoDauGoiDau, string loaiDauGoiDau, float dungTich, int tieuChuanKiemDinh) :
    DauGoiDau(maSoDauGoiDau, loaiDauGoiDau, dungTich) {
        this->tieuChuanKiemDinh = tieuChuanKiemDinh;
    }

    int getTieuChuanKiemDinh() override {
        return tieuChuanKiemDinh;
    }

    double GiaTien() const override {
        if(tieuChuanKiemDinh == 1) {
            return dungTich * 30;
        }
        return dungTich * 40;
    }
};

class SuaTam {
protected:
    string maSoSuaTam;
    string loaiSuaTam;
    float dungTich;
public:
    SuaTam(string maSoSuaTam, string loaiSuaTam, float dungTich) {
        this->maSoSuaTam = maSoSuaTam;
        this->loaiSuaTam = loaiSuaTam;
        this->dungTich = dungTich;
    }

    string getMaSoSuaTam() {
        return maSoSuaTam;
    }

    string getLoaiSuaTam() {
        return loaiSuaTam;
    }

    float getDungTich() {
        return dungTich;
    }

    virtual double GiaTien() const = 0;
};

class SuaTamDaKho : public SuaTam {
public:
    SuaTamDaKho(string maSoSuaTam, string loaiSuaTam, float dungTich) :
    SuaTam(maSoSuaTam, loaiSuaTam, dungTich) {}

    double GiaTien() const override {
        return dungTich * 20;
    }
};

class SuaTamDaNhon : public SuaTam {
public:
    SuaTamDaNhon(string maSoSuaTam, string loaiSuaTam, float dungTich) :
    SuaTam(maSoSuaTam, loaiSuaTam, dungTich) {}

    double GiaTien() const override {
        return dungTich * 40;
    }
};

class SanPham {
protected:
    string maGoiSanPham;
    string loaiGoiSanPham;
    double giaGoiSanPham;
public:
    SanPham() {}

    SanPham(string maGoiSanPham, string loaiGoiSanPham) {
        this->maGoiSanPham = maGoiSanPham;
        this->loaiGoiSanPham = loaiGoiSanPham;
    }

    string getMaGoiSanPham() {
        return maGoiSanPham;
    }

    string getLoaiGoiSanPham() {
        return loaiGoiSanPham;
    }

    double getGiaGoiSanPham() {
        return giaGoiSanPham;
    }

    virtual ~SanPham() {}
};

class Romantic : public SanPham {
private:
    NuocHoa *nuochoa;
    DauGoiDau *daugoidau;
    SuaTam *suatam;
public:
    Romantic(string maGoiSanPham, string loaiGoiSanPham, NuocHoa *nuochoa, DauGoiDau *DauGoiDau, SuaTam *suatam) : 
    SanPham(maGoiSanPham, loaiGoiSanPham) {
        this->nuochoa = nuochoa;
        this->daugoidau = daugoidau;
        this->suatam = suatam;
    }

    NuocHoa *&getNuocHoaptr() {
        return nuochoa;
    }

    DauGoiDau *&getDauGoiDauPtr() {
        return daugoidau;
    }

    SuaTam *&getSuaTamPtr() {
        return suatam;
    }

    ~Romantic() {
        delete nuochoa, daugoidau, suatam;
    }
};

class FreshAir : public SanPham {
private:
    NuocHoa *nuochoa;
    DauGoiDau *daugoidau;
    SuaTam *suatam;
public:
    FreshAir(string maGoiSanPham, string loaiGoiSanPham, NuocHoa *nuochoa, DauGoiDau *daugoidau, SuaTam *suatam) :
    SanPham(maGoiSanPham, loaiGoiSanPham) {
        
    }

    NuocHoa *&getNuocHoaptr() {
        return nuochoa;
    }

    DauGoiDau *&getDauGoiDauPtr() {
        return daugoidau;
    }

    SuaTam *&getSuaTamPtr() {
        return suatam;
    }

    ~FreshAir() {
        delete nuochoa, daugoidau, suatam;
    }
};

class DonHang {// don hang
private:
    string maDonHang;
    KhachHang *thongTinKhachHang;
    string ngayLapHoaDon;
    double giaDonHang;
    SanPham *sanPham;
public:
    DonHang(string maDonHang, KhachHang *thongTinKhachHang, string ngayLapHoaDon, SanPham *sanPham) {
        this->maDonHang = maDonHang;
        this->thongTinKhachHang = thongTinKhachHang;
        this->ngayLapHoaDon = ngayLapHoaDon;
        this->sanPham = sanPham;
        this->giaDonHang = 0;
    }

    ~DonHang() {
        delete thongTinKhachHang, sanPham;
    }

    friend ostream &operator<<(ostream &out, DonHang &donhang) {
        out << "\tMa don hang: " << donhang.maDonHang << "\n"; 

        out << "\tThong tin khach hang\n";
        out << "\t\tMa khach hang: " << donhang.thongTinKhachHang->getMaKhachHang() << "\n";
        out << "\t\tTen khach hang: " << donhang.thongTinKhachHang->getTenKhachHang() << "\n";
        out << "\t\tDia chi khach hang: " << donhang.thongTinKhachHang->getdiaChiKhachHang() << "\n";
        out << "\t\tSo dien thoai: " << donhang.thongTinKhachHang->getSoDienThoai() << "\n";

        out << "\tNgay lap hoa don: " << donhang.ngayLapHoaDon << "\n";

        out << "\tGia don hang: " << donhang.giaDonHang << "\n";

        out << "\tThong tin san pham\n";
        out << "\t\tMa goi san pham: " << donhang.sanPham->getMaGoiSanPham() << "\n";
        out << "\t\tLoai goi san pham: " << donhang.sanPham->getLoaiGoiSanPham() << "\n";
    
        if(donhang.sanPham != nullptr) {
            
            Romantic *romanticPtr = dynamic_cast<Romantic*>(donhang.sanPham);
            FreshAir *FreshAirPtr = dynamic_cast<FreshAir*>(donhang.sanPham);
            
            if(romanticPtr != nullptr) {
                out << "\t\tNuoc hoa:\n";
                out << "\t\t\tMa so nuoc hoa: " << romanticPtr->getNuocHoaptr()->getMaSoNuocHoa() << "\n";
                out << "\t\t\tLoai nuoc hoa: " << romanticPtr->getNuocHoaptr()->getLoaiNuocHoa() << "\n";
                out << "\t\t\tDung tich: " << romanticPtr->getNuocHoaptr()->getDungTich() << "\n";
                
                out << "\t\tDau goi dau:\n";
                out << "\t\t\tMa so dau goi dau: " << romanticPtr->getDauGoiDauPtr()->getMaSoDauGoiDau() << "\n";
                out << "\t\t\tLoai dau goi dau: " << romanticPtr->getDauGoiDauPtr()->getLoaiDauGoiDau() << "\n";
                out << "\t\t\tDung tich: " << romanticPtr->getDauGoiDauPtr()->getDungTich() << "\n";

                DauGoiTocKho *daugoitockho = dynamic_cast<DauGoiTocKho*>(romanticPtr->getDauGoiDauPtr());
                if(daugoitockho != nullptr) {
                    out << "\t\t\tTieu chuan kiem dinh loai: " << daugoitockho->getTieuChuanKiemDinh() << "\n";
                }

                out << "\t\tSua tam:\n";
                out << "\t\t\tMa so sua tam: " << romanticPtr->getSuaTamPtr()->getMaSoSuaTam() << "\n";
                out << "\t\t\tLoai sua tam: " << romanticPtr->getSuaTamPtr()->getLoaiSuaTam() << "\n";
                out << "\t\t\tDung tich: " << romanticPtr->getSuaTamPtr()->getDungTich() << "\n";

                delete daugoitockho;
            }
            if(FreshAirPtr != nullptr) {
                out << "\t\tNuoc hoa:\n";
                out << "\t\t\tLoai nuoc hoa: " << FreshAirPtr->getNuocHoaptr()->getLoaiNuocHoa() << "\n";
                out << "\t\t\tMa so nuoc hoa: " << FreshAirPtr->getNuocHoaptr()->getMaSoNuocHoa() << "\n";
                out << "\t\t\tDung tich: " << FreshAirPtr->getNuocHoaptr()->getLoaiNuocHoa() << "\n";

                out << "\t\tDau goi dau:\n";
                out << "\t\t\tMa so dau goi dau: " << FreshAirPtr->getDauGoiDauPtr()->getMaSoDauGoiDau() << "\n";
                out << "\t\t\tLoai dau goi dau: " << FreshAirPtr->getDauGoiDauPtr()->getLoaiDauGoiDau() << "\n";
                out << "\t\t\tDung tich: " << FreshAirPtr->getDauGoiDauPtr()->getDungTich() << "\n";

                DauGoiTocKho *daugoitockho = dynamic_cast<DauGoiTocKho*>(FreshAirPtr->getDauGoiDauPtr());
                if(daugoitockho != nullptr) {
                    out << "\t\t\tTieu chuan kiem dinh loai: " << daugoitockho->getTieuChuanKiemDinh() << "\n";
                }

                out << "\t\tSua tam:\n";
                out << "\t\t\tMa so sua tam: " << FreshAirPtr->getSuaTamPtr()->getMaSoSuaTam() << "\n";
                out << "\t\t\tLoai sua tam: " << FreshAirPtr->getSuaTamPtr()->getLoaiSuaTam() << "\n";
                out << "\t\t\tDung tich: " << FreshAirPtr->getSuaTamPtr()->getDungTich() << "\n";

                delete daugoitockho;
            }

            // free data pointers
            //**$
            delete romanticPtr, FreshAirPtr;
        }
        else {
            out << "Chua co thong tin cac loai san pham !\n";
        }
        
        return out;
    }
};

int main() {

    cout << "Nhap so luong don hang: "; 
    int N; cin >> N;

    vector<DonHang*> danhSachDonHang;
    for(int i = 0; i < N; i++) {
        cout << "Nhap thong tin don hang " << i + 1 << ": \n";
        cout << "\tMa don hang: ";
        string maDonHang; cin >> maDonHang;
        cout << "\tNgay lap don hang: ";
        string ngayLapHoaDon; cin >> ngayLapHoaDon;
        cout << "\tThong tin khach hang: \n";
        cout << "\t\tMa khach hang: ";
        string maKhachHang; cin >> maKhachHang;
        cout << "\t\tTen khach hang: ";
        string tenKH; cin.ignore();
        getline(cin, tenKH);
        cout << "\t\tDia chi: ";
        string diaChi;
        getline(cin, diaChi);
        cout << "\t\tSo dien thoai: ";
        string sdt; cin >> sdt;

        KhachHang *thongTinKhachHang = new KhachHang(maKhachHang, tenKH, diaChi, sdt);

        cout << "\tNhap thong so goi san pham \n";
        cout << "\tNhom goi san pham (1 - Romantic, 2 - Fresh-Air): ";
        int type; cin >> type;
        cout << "\tNhap ma so: ";
        string maGoiSanPham; cin >> maGoiSanPham;
        cout << "\tNhap ten goi san pham: ";
        string tenGoiSanPham; cin.ignore();
        getline(cin, tenGoiSanPham);

        string maSoNuocHoa;
        int chonNuocHoa; 
        if(type == 1) {
            cout << "\tNuoc hoa: \n";
            cout << "\t\tMa so nuoc hoa: ";
            cin >> maSoNuocHoa;

        }
        else {
            cout << "\tChon nuoc hoa: (1 - nuoc hoa hong, 2 - nuoc hoa cuc): ";
            cin >> chonNuocHoa; 
            cout << "\t\tMa so nuoc hoa: ";
            cin >> maSoNuocHoa;   
        }
        cout << "\t\tNhap dung tich: ";
        float dungTichNuocHoa; cin >> dungTichNuocHoa;

        int chonDauGoi; 
        if(type == 2) {
            cout << "\tDau goi: \n";
        }
        else {
            cout << "\tChon dau goi: (1 - cho toc kho, 2 - cho toc dau): ";
            cin >> chonDauGoi;
        }
        cout << "\t\tMa so dau goi: ";
        string maSoDauGoi; cin >> maSoDauGoi;
        int tieuChuanDauGoi;
        if(chonDauGoi == 2) {
           cout << "\t\tDat tieu chuan (1 - tieu chuan 1, 2 - tieu chuan 2): ";
            cin >> tieuChuanDauGoi;
        }
        cout << "\t\tNhap dung tich: ";
        float dungTichDauGoi; cin >> dungTichDauGoi;
        // su tam
        cout << "\tChon sua tam (1 - cho da kho, 2 - cho da nhon): ";
        int typeSuaTam; cin >> typeSuaTam;
        cout << "\t\tMa so sua tam: ";
        string maSoSuaTam; cin >> maSoSuaTam;
        cout << "\t\tNhap ten sua tam: ";
        string tenSuaTam; cin.ignore();
        getline(cin, tenSuaTam);            // xac dinh loai sua tam: da kho, da nhon
        cout << "\t\tNhap dung tich: ";
        float dungTichSuaTam; cin >> dungTichDauGoi;
        
        SanPham *sanpham = nullptr;
        NuocHoa *nuochoa = nullptr;
        DauGoiDau *daugoidau = nullptr;
        SuaTam *suatam = nullptr;
        if(type == 1) {         // ~ ~ Romantic
            nuochoa = new NuocHoaHong(maSoNuocHoa, "Nuoc hoa hong", dungTichNuocHoa);
            if(chonDauGoi == 1) {
                daugoidau = new DauGoiTocKho(maSoDauGoi, "Dau goi toc kho", dungTichDauGoi);
            }
            else if(chonDauGoi == 2) {
                daugoidau = new DauGoiTocDau(maSoDauGoi, "Dau goi toc dau", dungTichDauGoi, tieuChuanDauGoi);
            }
        }
        else if(type == 2) {    // ~ ~ Fresh Air
            if(chonNuocHoa == 1) {
                nuochoa = new NuocHoaHong(maSoNuocHoa, "Nuoc hoa hong", dungTichNuocHoa);
            }
            else if(chonNuocHoa == 2) {
                nuochoa = new NuocHoaCuc(maSoNuocHoa, "Nuoc hoa cuc", dungTichNuocHoa);
            }
            daugoidau = new DauGoiTocKho(maSoDauGoi, "Dau goi toc kho", dungTichDauGoi);
        }

        if(typeSuaTam == 1) {
            suatam = new SuaTamDaKho(maSoSuaTam, tenSuaTam, dungTichSuaTam);
        }
        else if(typeSuaTam == 2) {
            suatam = new SuaTamDaNhon(maSoSuaTam, tenSuaTam, dungTichSuaTam);
        }

        // add into product
        if(type == 1) {
            sanpham = new Romantic(maGoiSanPham, tenGoiSanPham, nuochoa, daugoidau, suatam);
        }
        else if(type == 2) {
            sanpham = new FreshAir(maGoiSanPham, tenGoiSanPham, nuochoa, daugoidau, suatam);
        }

        // add don hang
        danhSachDonHang.push_back(new DonHang(maDonHang, thongTinKhachHang, ngayLapHoaDon, sanpham));

    }

    // print information customers
    for(int i = 0; i < N; i++) {
        cout << *danhSachDonHang[i];
    }

    // free data ptr
    for(int i = 0; i < N; i++) {
        delete danhSachDonHang[i];
    }

    return 0;
}