#include <iostream>
#include <vector>
#include <map>

using namespace std;

class KyHieu {
protected:
    float truongDo;
public:
    virtual void Nhap();
    virtual bool LaDauLang() const;
    virtual int LayCaoDo() const = 0;
    float getTruongDo() const;
};

float KyHieu::getTruongDo() const {
    return truongDo;
}

bool KyHieu::LaDauLang() const {
    return false;
}

void KyHieu::Nhap() {
    cout << "Nhap gia tri truong do:\n";
    cout << "1.Tron, 2.Trang, 3.Den, 4.Moc don, 5.Moc kep, 6.Moc tam, 7.Moc tu: ";
    int choose;
    cin >> choose;
    switch(choose) {
    case 1:
        truongDo = 4;
        break;
    case 2:
        truongDo = 2;
        break;
    case 3:
        truongDo = 1;
        break;
    case 4:
        truongDo = 0.5;
        break;
    case 5:
        truongDo = 0.25;
        break;
    case 6:
        truongDo = 0.125;
        break;
    case 7:
        truongDo = 0.0625;
        break;
    }
}

class NotNhac : public KyHieu{
private:
    int caoDo;
    string tenNot[8];
    string tenHinhNot[8];
    map<float, int> mucTruongDoTuongUng;

public: 
    NotNhac();
    void Nhap() override;
    int LayCaoDo() const override;
    int getCaoDo() const;
    string getTenNot(int idx) const;
    string getTenHinhNot(float idx) const;
};

string NotNhac::getTenNot(int idx) const {
    return tenNot[idx];
}

string NotNhac::getTenHinhNot(float idx) const {
    int x = mucTruongDoTuongUng.at(idx);
    return tenHinhNot[x];
}

int NotNhac::getCaoDo() const {
    return caoDo;
}

NotNhac::NotNhac() {
    tenNot[1] = "Do(C)";
    tenNot[2] = "Re(D)";
    tenNot[3] = "Mi(E)";
    tenNot[4] = "Fa(F)";
    tenNot[5] = "Son(G)";
    tenNot[6] = "La(A)";
    tenNot[7] = "Si(B)";
    //
    tenHinhNot[1] = "Tron";
    tenHinhNot[2] = "Trang";
    tenHinhNot[3] = "Den";
    tenHinhNot[4] = "Moc don";
    tenHinhNot[5] = "Moc kep";
    tenHinhNot[6] = "Moc tam";
    tenHinhNot[7] = "Moc tu";
    //
    mucTruongDoTuongUng.insert({4, 1});
    mucTruongDoTuongUng.insert({2, 2});
    mucTruongDoTuongUng.insert({1, 3});
    mucTruongDoTuongUng.insert({0.5, 4});
    mucTruongDoTuongUng.insert({0.25, 5});
    mucTruongDoTuongUng.insert({0.125, 6});
    mucTruongDoTuongUng.insert({0.0625, 7});
}



int NotNhac::LayCaoDo() const {
    return caoDo;
}

void NotNhac::Nhap() {
    int choose;
    cout << "Nhap gia tri cao do:\n";
    cout << "1.Do(C), 2.Re(D), 3.Mi(E), 4.Fa(F), 5.Sol(G), 6.La(A), 7.Si(B): ";
    cin >> choose;
    caoDo = choose;
    KyHieu::Nhap();
}

class DauLang : public KyHieu {
public:
    void Nhap() override;
    bool LaDauLang() const override;
    int LayCaoDo() const override;
};

int DauLang::LayCaoDo() const {
    return 0;
}

bool DauLang::LaDauLang() const {
    return true;
}

void DauLang::Nhap() {
    cout << "---\tNhap dau lang\t--\n";
    KyHieu::Nhap();
}


int main() {
    cout << "Nhap so luong cac ky hieu am nhac: ";
    int n; cin >> n;
    KyHieu *banNhac[100];
    for(int i = 0; i < n; i++) {
        cout << "1. Soan not nhac, 2. Soan dau lang: ";
        int choose;
        cin >> choose;
        if(choose == 1) {
            banNhac[i] = new NotNhac();
        }
        else if(choose == 2) {
            banNhac[i] = new DauLang();
        }   
        banNhac[i]->Nhap();
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(banNhac[i]->LaDauLang() && banNhac[i]->getTruongDo() == 1) {
            count++;
        }
    }
    cout << "So dau lang den la: " << count << "\n";
    int max = banNhac[0]->LayCaoDo();
    int idx = 0;
    for(int i = 1; i < n; i++) {
        if(banNhac[i]->LayCaoDo() > max) {
            max = banNhac[i]->LayCaoDo();
            idx = i;
        }
    }
    if(max == 0) {
        cout << "Ban nhac khong hop le chi co dau lang\n";
    }
    else {
        NotNhac *notNhac = dynamic_cast<NotNhac*>(banNhac[idx]);
        cout << "Not nhac co cao do cao nhat trong ban nhac: " << notNhac->getTenNot(notNhac->getCaoDo()) << " " << 
                                                                  notNhac->getTenHinhNot(notNhac->getTruongDo());
        delete notNhac;
    }
    
    for(int i = 0; i < n; i++) {
        delete banNhac[i];
        banNhac[i] = nullptr;
    }
    return 0;
}