#include <iostream>

using namespace std;

class DaThucBacNhat
{
private:
    float a, b;
public:
    float F(int x);
    float Root();
    DaThucBacNhat operator+(const DaThucBacNhat &dt);
};

float DaThucBacNhat::F(int x)
{
    return a * x + b;
}

float DaThucBacNhat::Root()
{
    return - b / a;
}

DaThucBacNhat DaThucBacNhat::operator+(const DaThucBacNhat &dt)
{
    DaThucBacNhat result;
    result.a = this->a + dt.a;
    result.b = this->b = dt.b;
    return result;
}

int main()
{

    return 0;
}