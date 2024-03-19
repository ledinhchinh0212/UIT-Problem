#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sim {
protected:
    string tenLoaiSim;
    long long soSerial;      //12234
    string maNhaMang;        //(+001: Verizon, +002: AT&T, +003: Sprint)
    string soDienThoai;      // (+001) 123456789
    int trangThai;
public:
    Sim(long long soSerial, string maNhaMang, string soDienThoai, int trangThai) {
        this->soSerial = soSerial;
        this->maNhaMang = maNhaMang;
        this->soDienThoai = soDienThoai;
        this->trangThai = trangThai;
    }

    virtual ~Sim(){}

    string getTenLoaiSim() {
        return this->tenLoaiSim;
    }

    string getMaNhaMang() {
        return this->maNhaMang;
    }

    virtual float KhuyenMai() = 0;

    virtual long long getSoGhiNo() {
        return 0; 
    }

    virtual void InThongTinSim() {
        cout << "So Serial: " << soSerial << "\n";
        cout << "Ma nha mang: " << maNhaMang << "\n";
        cout << "So dien thoai: " << soDienThoai << "\n";
        cout << "Trang thai: " << trangThai << "\n";
    }
};

class SimTraTruoc : public Sim {
private:
    long long soDuTaiKhoan;
    int soLanNapThe;
public:
    SimTraTruoc(long long soSerial, string maNhaMang, string soDienThoai, int trangThai, long long soDuTaiKhoan, int soLanNapThe) :
    Sim(soSerial, maNhaMang, soDienThoai, trangThai) {
        this->soDuTaiKhoan = soDuTaiKhoan;
        this->soLanNapThe = soLanNapThe;
        this->tenLoaiSim = "Sim tra truoc";
    }

    float KhuyenMai() override {
        if(soLanNapThe < 5) {
            return 0.1;
        }
        if(soLanNapThe >= 5 && soLanNapThe <=10) {
            return 0.2;
        }
        return 0.5;
    }

    void InThongTinSim() override {
        Sim::InThongTinSim();
        cout << "So du tai khoan: " << soDuTaiKhoan << "\n";
        cout << "So lan nap the: " << soLanNapThe << "\n";
    }

    static float TongSoTienKhuyenMaiSimTraTruocAT(const vector<Sim*> &sim) {
        float sum = 0.0;
        for(int i = 0; i < sim.size(); i++) {
            if(sim[i]->getMaNhaMang() == "+002") {
                sum += sim[i]->KhuyenMai();
            }
        }
        
        return sum;
    }

};

class SimTraSau : public Sim {
private:
    string goiCuoc;     //LCAP, MCAP, HCAP
    long long soGhiNo;
public:
    SimTraSau(long long soSerial, string maNhaMang, string soDienThoai, int trangThai, string goiCuoc, long long soGhiNo) :
    Sim(soSerial, maNhaMang, soDienThoai, trangThai) {
        this->soGhiNo = soGhiNo;
        this->goiCuoc = goiCuoc;
        this->tenLoaiSim = "Sim tra sau";
    }

    long long getSoGhiNo() override {
        return soGhiNo;
    } 

    float KhuyenMai() override {
        if(goiCuoc == "LCAP") return 0.05;
        if(goiCuoc == "MCAP") return 0.1;
        return 0.15;
    }

    void InThongTinSim() override {
        Sim::InThongTinSim();
        cout << "Goi cuoc: " << goiCuoc << "\n";
        cout << "So ghi no: " << soGhiNo << "\n";
    }

    static void ThongTinSimTraSauCoSoGhiNoLonNhat(vector<Sim*> &sim) {
        long long max = -1;
        for(int i = 0; i < sim.size(); i++) {
            if(sim[i]->getTenLoaiSim() == "Sim tra sau") {
                long long soGhiNo = sim[i]->getSoGhiNo();
                if(soGhiNo > max) {
                    max = soGhiNo;
                }
            }   
        }

        for(int i = 0; i < sim.size(); i++) {
            if(sim[i]->getSoGhiNo() == max) {
                sim[i]->InThongTinSim();
                cout << "###################\n";
            }
        }
    }
};

int main() {

    vector<Sim*> sim;
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cout << "1: Sim tra truoc, 2: Sim tra sau\n";
        int type; cin >> type;
        long long soSerial;      
        cin >> soSerial;
        string maNhaMang;
        cin >> maNhaMang;        
        string soDienThoai;
        cin >> soDienThoai;      
        int trangThai;
        cin >> trangThai;
        if(type == 1) {
            long long soDuTaiKhoan;
            cin >> soDuTaiKhoan;
            int soLanNapThe;
            cin >> soLanNapThe;
            sim.push_back(new SimTraTruoc(soSerial, maNhaMang, soDienThoai, trangThai, soDuTaiKhoan, soLanNapThe));
        }
        else if(type == 2) {
            string goiCuoc;
            cin >> goiCuoc; 
            long long soGhiNo;
            cin >> soGhiNo;
            sim.push_back(new SimTraSau(soSerial, maNhaMang, soDienThoai, trangThai, goiCuoc, soGhiNo));
        }
    }
    //
    cout << SimTraTruoc::TongSoTienKhuyenMaiSimTraTruocAT(sim) << "\n";
    //
    SimTraSau::ThongTinSimTraSauCoSoGhiNoLonNhat(sim);

    for(int i = 0; i < n; i++) {
        delete sim[i];
    }

    return 0;
}