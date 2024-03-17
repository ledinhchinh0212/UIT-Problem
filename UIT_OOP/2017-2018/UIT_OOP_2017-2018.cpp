#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class ChuongNgaiVat {
protected:
    string tenChuongNgaiVat;
public:   
    virtual bool vuotChuongNgaiVat(vector<int> player) = 0;
    virtual string show() = 0;
};

class KhuRungChong : public ChuongNgaiVat{
private:
    vector<int> jungles;
public:
    KhuRungChong(vector<int> jungles) {
        this->jungles = jungles;
        this->tenChuongNgaiVat = "Jungle";
    }
    bool vuotChuongNgaiVat(vector<int> player) override {
        for(int i = 0; i < 7; i++) {
            if(player[i] < jungles[i]) {
                return false;
            }
        }
        return true;
    }
    string show() override{
        return tenChuongNgaiVat;
    }
};

class DuongHamNui : public ChuongNgaiVat{
private:
    vector<int> tunnels;
    int size;
public:
    DuongHamNui(vector<int> tunnels, int size) {
        this->tunnels = tunnels;
        this->size = size;
        this->tenChuongNgaiVat = "Tunnel";
    }
    bool vuotChuongNgaiVat(vector<int> player) override {
        for(int i = 0; i < size; i++) {
            if(player[i] > tunnels[i]) {
                return false;
            }
        }
        return true;
    }
    string show() override{
        return tenChuongNgaiVat;
    }
};

class QuaiVat : public ChuongNgaiVat {
private:
    vector<int> monsters;
public:
    QuaiVat(vector<int> monsters) {
        this->monsters = monsters;
        this->tenChuongNgaiVat = "Monster";
    }
    bool vuotChuongNgaiVat(vector<int> player) override{
        int count = 0;
        for(int i = 0; i < 5; i++) {
            if(player[i] > monsters[i]) {
                count++;
            }
        }
        return 2 *count > monsters.size();
    }
    string show() override{
        return tenChuongNgaiVat;
    }
};

int main() {
    cout << "Nhap so chuong ngai vat:\n";
    int N;
    cin >> N;

    vector<ChuongNgaiVat*> chuongngaivat;
    // main threads:
    // nhap danh sach chuong ngai vat
    for(int i = 0; i < N; i++) {
        cout << "Nhap loai chuong ngai vat (1: Khu rung chong, 2: Duong ham, 3: Quai vat): \n";
        int type;
        cin >> type;
        if(type == 1) {
            cout << "Nhap chieu cao cac cay chong:\n";
            vector<int> jungles(7);
            for(int j = 0; j < 7; j++) {
                cin >> jungles[j];
            }

            chuongngaivat.push_back(new KhuRungChong(jungles));
        }
        else if(type == 2) {
            cout << "Nhap so duong ham:\n";
            int size;
            cin >> size;
            cout << "Nhap chieu cao cua tung duong ham:\n";
            vector<int> tunnels(size);
            for(int j = 0; j < size; j++) {
                cin >> tunnels[j];
            }

            chuongngaivat.push_back(new DuongHamNui(tunnels, size));
        }
        else if(type == 3) {
            cout << "Nhap suc manh cua quai vat tung chieu:\n";
            vector<int> monsters(5);
            for(int j = 0; j < 5; j++) {
                cin >> monsters[j];
            }

            chuongngaivat.push_back(new QuaiVat(monsters));
        }

    }
    // nhap danh sach nguoi choi
    cout << "Nhap 7 thong so cua nguoi choi the hien suc nhay:\n";
    vector<int> jump(7);
    for(int i = 0; i < 7; i++) {
        cin >> jump[i];
    }
    cout << "Nhap chieu cao cua nguoi choi khi di qua duong ham:\n";
    int chieuCao;
    cin >> chieuCao;
    vector<int> high(1000,chieuCao);
    cout << "Nhap do manh o 5 chieu khi chien dau voi quai vat:\n";
    vector<int> strength(5);
    for(int i = 0; i < 5; i++) {
        cin >> strength[i];
    }
    //
    srand(time(nullptr));
    int appleIndex;
    bool loss = false;
    for(int i = 0; i < N; i++) {
        cout << chuongngaivat[i]->show() << "\n";
        if(chuongngaivat[i]->show() == "Jungle") {
            appleIndex = rand() % 3 + 0;
            for(auto &x : jump) {
                x = x + appleIndex;
            }
            if(!chuongngaivat[i]->vuotChuongNgaiVat(jump)) {
                loss = true;
                break;
            }
        }
        else if(chuongngaivat[i]->show() == "Tunnel") {
            if(!chuongngaivat[i]->vuotChuongNgaiVat(high)) {
                loss = true;
                break;
            }
        }
        else {
            if(!chuongngaivat[i]->vuotChuongNgaiVat(strength)) {
                loss = true;
                break;
            }
        }
    }

    if(loss) {
        cout << "Nguoi choi khong the tim duoc kho bau\n";
    }
    else {
        cout << "Nguoi choi tim duoc kho bau !\n";
    }

    for(int i = 0; i < chuongngaivat.size(); i++) {
        delete chuongngaivat[i];
    }

    return 0;
}