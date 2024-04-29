#include <iostream>

using namespace std;

class ToaDo {
private:
    float x, y;
public:
    friend istream &operator>>(istream &in, ToaDo &toaDo);
    friend ostream &operator<<(ostream &out, const ToaDo &toaDo);
};

istream &operator>>(istream &in, ToaDo &toaDo) {
    in >> toaDo.x >> toaDo.y;
    return in;
}

ostream &operator<<(ostream &out, const ToaDo &toaDo) {
    out << "(" << toaDo.x << ", " << toaDo.y << ")";
    return out;
}

class Hinh {
protected:
    ToaDo toaDoTam;
public:
    virtual void Nhap();
    virtual void Draw() const = 0;
};

void Hinh::Nhap() {
    cin >> toaDoTam;
}


class HinhTron : public Hinh{
private:
    float banKinh;
public:
    void Nhap() override;
    void Draw() const override;
};

void HinhTron::Nhap() {
    Hinh::Nhap();
    cin >> banKinh;
}

void HinhTron::Draw() const {
    cout << "Ve hinh tron\n";
}

class Ellipse : public Hinh {
private:
    float a, b, c;
    float f1, f2;
public:
    void Nhap() override;
    void Draw() const override;
};

void Ellipse::Nhap() {
    Hinh::Nhap();
    cin >> a >> b >> c >> f1 >> f2;
}

void Ellipse::Draw() const {
    cout << "Ve hinh ellipse\n";
}

int main() {

    Hinh *hinh = new HinhTron();

    hinh->Nhap();
    hinh->Draw();

    delete hinh;
    return 0;
}