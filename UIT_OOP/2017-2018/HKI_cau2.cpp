#include <iostream>

using namespace std;

class cNgay {
private:
    int ngay, thang, nam; // yyyy mm dd
public:
    cNgay() {
        ngay = thang = nam = 1;
    }

    cNgay(int nam, int thang, int ngay = 1) {
        this->nam = nam;
        this->thang = thang;
        this->ngay = ngay;
    }

    friend istream &operator>>(istream &in, cNgay &cngay) {
        in >> cngay.nam;
        in >> cngay.thang;
        in >> cngay.ngay;
        return in;
    }

    friend ostream &operator<<(ostream &out, const cNgay &cngay) {
        out << "Ngay " << cngay.ngay << " ";
        out << "thang " << cngay.thang << " ";
        out << "nam " << cngay.nam << "\n";
        return out;
    }

    bool operator<(const cNgay &cngay) const {
        if(this->nam < cngay.nam) {
            return true;
        }
        else if(this->thang < cngay.thang) {
            return true;
        }
        return this->ngay < cngay.ngay;
    }
};

int main() {
    cNgay ng1;                  // ng1 sẽ có giá trị là ngày 1 tháng 1 năm 1
    cNgay ng2(2017, 1);         // ng2 sẽ có giá trị là ngày 1 tháng 1 năm 2017
    cNgay ng3(2017, 1, 7);      // ng3 sẽ có giá trị là ngày 7 tháng 1 năm 2017
    cin >> ng1;
    cout << ng1;
    if(ng1 < ng2) {
        cout << "Ngay 1 truoc ngay 2" << endl;
    }
    else cout << "Ngay 1 khong truoc ngay 2" << endl;

    return 0;
}