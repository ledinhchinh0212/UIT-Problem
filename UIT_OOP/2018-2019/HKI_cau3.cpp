#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Customer {
protected:
    string name;
    string cccd;
    int registrationTime; // month
    int numberClass;   
    int basicFee;
    int classFee;
    int saunaService;
    int PTSupport;
public:
    int getPTSupport() {
        return PTSupport;
    }

    int getSaunaService() {
        return saunaService;
    }

    int getClassFee() {
        return classFee;
    }

    int getBasicFee() {
        return basicFee;
    }

    int getRegistrationTime() {
        return registrationTime;
    }

    Customer(string name, string cccd, int registrationTime, int numberClass, int basicFee, int classFee,
    int saunaService, int PTSupport) {
        this->name = name;
        this->cccd = cccd;
        this->registrationTime = registrationTime;
        this->numberClass = numberClass;
        this->basicFee = basicFee;
        this->classFee = classFee;
        this->saunaService = saunaService;
        this->PTSupport = PTSupport;
    }

    void printInfomationCustomer() {
        cout << "Ho ten: " << name << "\n";
        cout << "CCCD: " <<  cccd << "\n";
        cout << "Thoi gian dang ky: " << registrationTime << " thang\n";
        if(numberClass > 0) {
            cout << "So lop hoc: " << numberClass << "\n";
        }
        cout << "Phi co ban: " << basicFee << "\n";
        //
        cout << "Phi lop hoc: ";
        if(classFee == 0) {
            cout << "Mien phi\n";
        }
        else if(classFee != -1) {
            cout << classFee << "\n";
        }
        else {
            cout << "Khong co\n"; 
        }
        //
        cout << "Dich vu xong hoi: "; 
        if(saunaService == 0) {
            cout << "Mien phi\n";
        }
        else if(saunaService != -1){
            cout << saunaService << "\n";
        }
        else {
            cout << "Khong co\n"; 
        }
        //
        cout << "Ho tro PT: ";
        if(PTSupport == 0){
            cout << "Mien phi\n";
        }
        else {
            cout << PTSupport << "\n";
        }
    }
};

class Premium : public Customer {
public:
    Premium(string name, string cccd, int registrationTime, int numberClass = 0) :
    Customer(name, cccd, registrationTime, 0, 1000, 0, 0, 0) {
    }
};

class Basic : public Customer {
public:
    Basic(string name, string cccd, int registrationTime, int numberClass) :
    Customer(name, cccd, registrationTime, numberClass, 500, 100  * numberClass, -1, 100){}   
};

class NonMember : public Customer {
public:
    NonMember(string name, string cccd, int registrationTime, int numberClass = 0) :
    Customer(name, cccd, registrationTime, numberClass, 200, -1, -1, 200){
        
    }
};

int RichCustomer(vector<Customer*> cs, int N) {
    int totalMoney = 0;
    int max = -1;
    for(int i = 0; i < N; i++) {
        int num = cs[i]->getClassFee();
        if(cs[i]->getClassFee() == -1) {
            num = 0;
        }
        totalMoney = cs[i]->getBasicFee() + num + cs[i]->getPTSupport();
        totalMoney = totalMoney * cs[i]->getRegistrationTime();
        cs[i]->printInfomationCustomer();
        if(totalMoney > max) {
            max = totalMoney;
        }
    }
    return max;
}

int main() {

    vector<Customer*> cs;
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cout << "Nhap che do khach hang, 1: Premium, 2: Basic, 3: Non-Member\n";
        int type;
        cin >> type;
        cin.ignore();
        cout << "Nhap ten khach hang: ";
        string name;
        getline(cin, name);
        cout << "Nhap cccd khach hang: ";
        string cccd;
        cin >> cccd;
        cout << "Nhap thoi gian su dung dich vu (thang): ";
        int thoigiansudung;
        cin >> thoigiansudung;
        if(type == 1) {
            cs.push_back(new Premium(name, cccd, thoigiansudung));
        }
        else if(type == 2) {
            cout << "Nhap so lop muon tham gia: ";
            int soLopThamGia;
            cin >> soLopThamGia;
            cs.push_back(new Basic(name, cccd, thoigiansudung, soLopThamGia));
        }
        else if(type == 3) {
            cs.push_back(new NonMember(name, cccd, thoigiansudung));
        }
    }
    // in thong tin khach hang
    for(int i = 0; i < N; i++) {
        cs[i]->printInfomationCustomer();
        cout << "----------------\n";
    }

    cout << RichCustomer(cs, N);

    for(int i = 0; i < N; i++) {
        delete cs[i];
    }

    return 0;
}