#include <iostream>
#include <cmath>

using namespace std;

class DaThucBacHai {
private:
    double a, b, c;
    double x;
public:
    DaThucBacHai() {
        this->a = this->b = this->c =  0;
    }

    DaThucBacHai(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double SolveFX(double x) {
        this->x = x;
        return (a * pow(this->x, 2)) + (b * this->x) + c;
    }

    DaThucBacHai operator+(const DaThucBacHai &dt) {
        DaThucBacHai kq;
        kq.a = this->a + dt.a;
        kq.b = this->b + dt.b;
        kq.c = this->c + dt.c;
        return kq;
    }

    friend ostream &operator<<(ostream &out, const DaThucBacHai &dathucbachai) {
        out << dathucbachai.a << "x^2 + " << dathucbachai.b << "x + " << dathucbachai.c;

        return out;
    }
};

int main() {

    DaThucBacHai daThucBacHai(1, -2, 1);
    cout << daThucBacHai.SolveFX(-1) << "\n";
    DaThucBacHai daThucBacHai2(3, 4, 5);
    cout << daThucBacHai2 + daThucBacHai << "\n";

    return 0;
}