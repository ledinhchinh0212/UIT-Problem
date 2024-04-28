#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class ChuongTrinhThongKe {
private:
    const char* linkFile;
    string s;
public:
    ChuongTrinhThongKe();
    string trim(bool space = true);
    void start();
    int soLuongCau() const;
    void soLuongTuTrongCau();
    vector<string> tachChuoi(bool space = true);
    string sapXepChuoi();
};

ChuongTrinhThongKe::ChuongTrinhThongKe() {
    this->linkFile = "C:\\Users\\ADMIN\\Desktop\\ledinhchinh.txt";
}

string ChuongTrinhThongKe::trim(bool space) {
    int len = s.length();
    string copy = "";
    for(int i = 0; i < len; i++) {
        char ch = s[i];
        if(ch == '.' || ch == '!' || ch == '?') {
            if(space) {
                copy = copy + " " + ch;
            }
            else {
                copy += ch;
            }
        }
        else copy += ch;
    }
    return copy;
}

int ChuongTrinhThongKe::soLuongCau() const {
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if(ch == '.' || ch == '!' || ch == '?') {
            count++;
        }
    }
    return count;
}

vector<string> ChuongTrinhThongKe::tachChuoi(bool space) {
    string chuoiTach =  trim(space);
    stringstream ss(chuoiTach);
    string empty = "";
    vector<string> mangChuoiTach;
    while(ss >> empty) {
        mangChuoiTach.push_back(empty);
    }
    return mangChuoiTach;
} 

void ChuongTrinhThongKe::soLuongTuTrongCau() {
    vector<string> mangChuoiTach = tachChuoi();
    int dem = 0;
    int demTrongCau = 0;
    for(int i = 0; i < mangChuoiTach.size(); i++) {
        string copy = mangChuoiTach[i];
        if(copy == ".") {
            demTrongCau++;
            cout << "Cau thu " << demTrongCau << " co " << dem << " tu\n";
            dem = 0;
        }
        else {
            dem++;
        }
    }
}

string ChuongTrinhThongKe::sapXepChuoi() {
    vector<string> mangChuoiTach = tachChuoi(false);
    string copy = "";
    sort(mangChuoiTach.begin(), mangChuoiTach.end());
    for(string x : mangChuoiTach) {
        copy = copy + x + " ";
    }
    return copy;
}

void ChuongTrinhThongKe::start() {
    ifstream file;
    file.open(this->linkFile);
    if(file.fail()) {
        cout << "Mo file khong thanh cong\n";
        return;
    }
    getline(file, this->s);
    cout << "So luong cau: " << soLuongCau() << "\n";
    soLuongTuTrongCau();
    cout << "Doan van sau khi da sap xep:\n";
    cout << sapXepChuoi();

    file.close();
}

int main() {

    ChuongTrinhThongKe *p = new ChuongTrinhThongKe();

    p->start();

    delete p;
    return 0;
}