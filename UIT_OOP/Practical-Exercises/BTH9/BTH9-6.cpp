#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <cmath>

using namespace std;

class DonThuc {
private:
    int heSo;
    int soMu;
public:
    DonThuc(int heSo, int soMu);
    int getHeSo() const;
    int getSoMu() const;
};

DonThuc::DonThuc(int heSo, int soMu) {
    this->heSo = heSo;
    this->soMu = soMu;
}

int DonThuc::getHeSo() const {
    return heSo;
}

int DonThuc::getSoMu() const {
    return soMu;
}

class HamSo {
protected:
    vector<DonThuc> donThuc;
    vector<DonThuc> daoHam;
public:
    int giaTriHamSo(int value, bool tinhDaoHam = false) const;
};

int HamSo::giaTriHamSo(int value, bool tinhDaoHam) const {
    int n = donThuc.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(tinhDaoHam) {
            if(value == 0 && daoHam[i].getSoMu() < 0) {
                continue;
            }
            //cout << value << " " << daoHam[i].getSoMu() << " " <<  pow(value, daoHam[i].getSoMu()) << "\n";
            sum = sum + daoHam[i].getHeSo() * pow(value, daoHam[i].getSoMu());
        }
        else {
            sum = sum + donThuc[i].getHeSo() * pow(value, donThuc[i].getSoMu());
        }
    }
    return sum;
}

class FX : public HamSo {
public:
    FX(int k);
};

FX::FX(int k) {
    this->donThuc = {{k, 1} , {-3, 0}};
    this->daoHam = {{k, 0}, {0, -1}};
}

class GX : public HamSo {
public:
    GX(int k);
};

GX::GX(int k) {
    this->donThuc = {{-3, 2} , {k, 1}};
    this->daoHam = {{-6, 1}, {k, 0}};
}

class HX : public HamSo {
public:
    HX(int k);
};

HX::HX(int k) {
    this->donThuc = {{7, 3} , {k, 2}, {-5, 0}};
    this->daoHam = {{7*3, 2}, {2*k, 1}, {0, -1}};
}

int main() {

    const char *linkReadFile = "C:\\Users\\ADMIN\\Desktop\\KHAOSAT.INP";
    const char *linkWriteFile = "C:\\Users\\ADMIN\\Desktop\\KHAOSAT.OUT";

    ifstream readFile;
    readFile.open(linkReadFile);
    if(readFile.fail()) {
        cout << "Mo file de doc khong thanh cong\n";
        return -1;
    }

    int k1, k2, k3;
    readFile >> k1 >> k2 >> k3;
    int min, max, step;
    readFile >> min >> max >> step;

    readFile.close();

    ofstream writeFile;
    writeFile.open(linkWriteFile);
    if(writeFile.fail()) {
        cout << "Mo file de ghi khong thanh cong\n";
        return -1;
    }

    HamSo **hamSo = new HamSo*[3];
    hamSo[0] = new FX(k1);
    hamSo[1] = new GX(k2);
    hamSo[2] = new HX(k3);
    
    for(int i = min; i <= max; i += step) {
        writeFile << i << " ";
    }
    writeFile << "\n";
    for(int i = 0; i < 3; i++) {
        for(int j = min; j <= max; j += step) {
            writeFile << hamSo[i]->giaTriHamSo(j) << " ";
        }
        writeFile << "\n";
    }
    for(int i = 0; i < 3; i++) {
        for(int j = min; j <= max; j += step) {
            writeFile << hamSo[i]->giaTriHamSo(j, true) << " ";
        }
        writeFile << "\n";
    }

    writeFile.close();

    for(int i = 0; i < 3; i++) {
        delete hamSo[i];
    }

    delete []hamSo;

    return 0;
}