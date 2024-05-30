#include <iostream>

using namespace std;

class QuanCo
{
protected:
    int x, y;
    bool loai; // true if white else black
public:
    QuanCo(int x, int y, bool loai);
    int getX() const {return x;}
    int getY() const {return y;}
    bool getLoai() const {return loai;}
    virtual void CachDiCuaQuanCo() const = 0;
};

QuanCo::QuanCo(int x, int y, bool loai) : x(x), y(y), loai(loai) {}

class TuongKing : public QuanCo
{
public:
    TuongKing(int x, int y, bool loai) : QuanCo(x, y, loai) {}
    void CachDiCuaQuanCo() const override;
};

void TuongKing::CachDiCuaQuanCo() const 
{
    cout << "Di tung o mot, di ngang hoac doc. Tuong luon luon phai o trong pham vi\n";
    cout << "cung va khong duoc ra ngoai. Cung tuc la hinh vuong 2X2 duoc danh dau bang duong\n cheo hinh chu X.\n";
}

class Si : public QuanCo
{
public:
    Si(int x, int y, bool loai) : QuanCo(x, y, loai) {}
    void CachDiCuaQuanCo() const override;
};

void Si::CachDiCuaQuanCo() const 
{
    cout << "Di xeo 1 o moi nuoc. Si luon luon phai o trong cung nhu Tuong.\n";
}

class Tuong : public QuanCo
{
public:
    Tuong(int x, int y, bool loai) : QuanCo(x, y, loai) {}
    void CachDiCuaQuanCo() const override;
};

void Tuong::CachDiCuaQuanCo() const 
{
    cout << "Di cheo 2 o (ngang 2 va doc 2) cho moi nuoc di. Tuong chi duoc phep o mot\n";
    cout << "ben cua ban co, khong duoc di chuyen sang nua ban co cua doi phuong. Nuoc di cua\n";
    cout << "tuong se khong hop le khi co mot quan co nam chan giua duong di.\n";
}

class Xe : public QuanCo
{
public:
    Xe(int x, int y, bool loai) : QuanCo(x, y, loai) {}
    void CachDiCuaQuanCo() const override;
};

void Xe::CachDiCuaQuanCo() const
{
    cout << "Di ngang hay doc tren ban co mien la dung bi quan khac can duong tu diem di\n";
    cout << "den diem den.\n";
}

class Ma : public QuanCo
{
public:
    Ma(int x, int y, bool loai) : QuanCo(x, y, loai) {}
    void CachDiCuaQuanCo() const override;
};

void Ma::CachDiCuaQuanCo() const
{
    cout << "Di ngang 2 o va doc 1 o (hay doc 2 o va ngang 1 o) cho moi nuoc di. Neu co\n";
    cout << "quan nam ngay ben canh ma va can duong ngang 2(hay duong doc2), ma bi can khong\n";
    cout << "duoc di duong do.\n";
}

class Phao : public QuanCo
{
public:
    Phao(int x, int y, bool loai) : QuanCo(x, y, loai) {}
    void CachDiCuaQuanCo() const override;
};

void Phao::CachDiCuaQuanCo() const
{
    cout << "Di ngang va doc giong nhu xe. Diem khac biet la neu phao muon an quan, phao\n";
    cout << "phai nhay qua dung 1 quan nao do. Khi khong an quan, tat ca nhung diem tu cho di den\n";
    cout << "cho den phai khon co quan can.\n";
}

class Tot : public QuanCo
{
public:
    Tot(int x, int y, bool loai) : QuanCo(x, y, loai) {}
    void CachDiCuaQuanCo() const override;
};

void Tot::CachDiCuaQuanCo() const 
{
    cout << "Di mot o moi nuoc. Neu tot chua vuot qua song, no chi co the di thang tien. Khi\n";
    cout << "da vuot song roi, tot co the di ngang 1 buoc hay di thang tien 1 buoc moi nuoc.\n";
}

class BanCo
{
private:
    QuanCo **quanCo;
public:
    BanCo();
    ~BanCo();
    void CachDiCuaQuanCoTuongUng(const QuanCo *quanCo);
};

BanCo::BanCo()
{
    quanCo = new QuanCo*[33];

    quanCo[0] = new Xe(1, 1, true);
    quanCo[1] = new Xe(1, 9, true);
    quanCo[2] = new Ma(1, 2, true);
    quanCo[3] = new Ma(1, 8, true);
    quanCo[4] = new Tuong(1 ,3, true);   
    quanCo[5] = new Tuong(1 ,7, true);   
    quanCo[6] = new Si(1, 4, true);
    quanCo[7] = new Si(1, 6, true);
    quanCo[8] = new TuongKing(1, 5, true);
    quanCo[9] = new Phao(3, 2, true);
    quanCo[10] = new Phao(3, 8, true);
    int indexTotTrang = 11;
    for(int i = 1; i <= 9; i += 2)
    {
        quanCo[indexTotTrang] = new Tot(4, i, true);
        indexTotTrang++;
    }

    quanCo[16] = new Xe(10, 1, false);
    quanCo[17] = new Xe(10, 9, false);
    quanCo[18] = new Ma(10, 2, false);
    quanCo[19] = new Ma(10, 8, false);
    quanCo[20] = new Tuong(10 ,3, false);   
    quanCo[21] = new Tuong(10 ,7, false);   
    quanCo[22] = new Si(10, 4, false);
    quanCo[23] = new Si(10, 6, false);
    quanCo[24] = new TuongKing(10, 5, false);
    quanCo[25] = new Phao(8, 2, false);
    quanCo[26] = new Phao(8, 8, false);
    int indexTotDen = 27;
    for(int i = 1; i <= 9; i += 2)
    {
        quanCo[indexTotDen] = new Tot(7, i, false);
        indexTotDen++;
    }
}

BanCo::~BanCo()
{
    for(int i = 0; i < 32; i++)
    {
        delete quanCo[i];
    }
    delete quanCo;
}

void BanCo::CachDiCuaQuanCoTuongUng(const QuanCo *quanCo)
{
    if(quanCo == nullptr) return;
    for(int i = 0; i < 32; i++)
    {
        if( quanCo->getLoai() == this->quanCo[i]->getLoai() &&
            quanCo->getX() == this->quanCo[i]->getX() &&
            quanCo->getY() == this->quanCo[i]->getY())
        {
            this->quanCo[i]->CachDiCuaQuanCo();
            return;
        }
    }
    cout << "Quan co khong hop le\n";
}

int main()
{
    BanCo *banCo = new BanCo();
   
    cout << "Nhap mot quan co:\n";
    cout << "1. Xe, 2. Ma, 3. Tuong, 4. Si, 5. Tuongs, 6. Phao, 7. Tot\n";
    int choose; cin >> choose;

    bool type_ = true;

    QuanCo *quanCo = nullptr;

    switch(choose)
    {
    case 1: quanCo = new Xe(1, 1, type_); break;
    case 2: quanCo = new Ma(1, 2, type_); break;
    case 3: quanCo = new Tuong(1, 3, type_); break;
    case 4: quanCo = new Si(1, 4, type_); break;
    case 5: quanCo = new TuongKing(1, 5, type_); break;
    case 6: quanCo = new Phao(3, 2, type_); break;
    case 7: quanCo = new Tot(4, 1, type_); break;
    }

    cout << "Cach di chuyen cua quan co:\n";
    banCo->CachDiCuaQuanCoTuongUng(quanCo);

    if(quanCo != nullptr)
        delete quanCo;
    delete banCo;

    return 0;
}