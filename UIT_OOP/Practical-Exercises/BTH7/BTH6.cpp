#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

using namespace std;

class GiaSuc {
protected:
    string tenGiaSuc;
    int soLuongSinhCon;
public:
    GiaSuc();
    friend istream &operator>>(istream &in, GiaSuc &giaSuc);
    friend ostream &operator<<(ostream &out, const GiaSuc &giaSuc);
    virtual string tiengKeu() const = 0;
    virtual int getSoLitSua() const = 0;
    string getTenGiaSuc() const;
};

GiaSuc::GiaSuc() {
    this->soLuongSinhCon = 0;
    this->tenGiaSuc = "";
}

istream &operator>>(istream &in, GiaSuc &giaSuc) {
    cout << "So luong sinh con: "; cin >> giaSuc.soLuongSinhCon;
    return in;
}

ostream &operator<<(ostream &out, const GiaSuc &giaSuc) {
    out << "Ten gia suc: " << giaSuc.getTenGiaSuc() << "\n";
    out << "So luong sinh con: " << giaSuc.soLuongSinhCon << "\n";
    out << "So lit sua: " << giaSuc.getSoLitSua() << "\n";
    return out;
}

string GiaSuc::getTenGiaSuc() const {
    return tenGiaSuc;
}

class Bo : public GiaSuc {
public:
    Bo();
    string tiengKeu() const override;
    int getSoLitSua() const override;
};

Bo::Bo() {
    this->tenGiaSuc = "Bo";
}

string Bo::tiengKeu() const {
    return "moo moo moo ..";
}

int Bo::getSoLitSua() const {
    srand(time(nullptr));
    return rand() % 20 + 0;
}

class Cuu : public GiaSuc {
public:
    Cuu();
    string tiengKeu() const override;
    int getSoLitSua() const override;
};

Cuu::Cuu() {
    this->tenGiaSuc = "Cuu";
}

string Cuu::tiengKeu() const {
    return "Bee bee bee ...";
}

int Cuu::getSoLitSua() const {
    srand(time(nullptr));
    return rand() % 5 + 0;
}

class De : public GiaSuc {
public:
    De();
    string tiengKeu() const override;
    int getSoLitSua() const override;
};

De::De() {
    this->tenGiaSuc = "De";
}

string De::tiengKeu() const {
    return "Bleat bleat bleat ...";
}

int De::getSoLitSua() const {
    srand(time(nullptr));
    return rand() % 10 + 0;
}

int main() {

    cout << "Nhap so luong gia suc ban dau cua moi loai: ";
    int n; cin >> n;
    GiaSuc **nongTrai = new GiaSuc*[n];
    for(int i = 0; i < n; i++) {
        cout << "1. Bo, 2. Cuu, 3. De: ";
        int type; cin >> type;
        if(type == 1) {
            nongTrai[i] = new Bo();
        }
        else if(type == 2) {
            nongTrai[i] = new Cuu();
        }
        else {
            nongTrai[i] = new De();
        }
        cin >> *nongTrai[i];
    }
    set<string> s;
    for(int i = 0; i < n; i++) {
        s.insert(nongTrai[i]->tiengKeu());
    }
    cout << "\nNhung tien keu nghe duoc trong nong trai:\n";
    for(const string &x : s) {
        cout << x << "\n";
    }
    cout << "\nThong ke thong tin trong nong trai:\n";
    for(int i = 0; i < n; i++) {
        cout << *nongTrai[i] << "\n";
    }

    for(int i = 0; i < n; i++) {
        delete nongTrai[i];
    }

    delete []nongTrai;

    return 0;
}