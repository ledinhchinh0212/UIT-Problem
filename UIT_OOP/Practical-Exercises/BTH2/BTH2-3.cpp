#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int ngay, thang, nam;
public: 
    Date(int ngay = 1, int thang = 1, int nam = 1);
    friend istream &operator>>(istream &in, Date &date);
    friend ostream &operator<<(ostream &out, const Date &date);
};

Date::Date(int ngay, int thang, int nam) {
    this->ngay = ngay;
    this->thang = thang;
    this->nam = nam;
}

istream &operator>>(istream &in, Date &date) {
    in >> date.ngay >> date.thang >> date.nam;
    return in;
}

ostream &operator<<(ostream &out, const Date &date) {
    out << date.ngay << "/" << date.thang << "/" << date.nam;
    return out;
}

class Candidate {
private:
    string ma;
    string ten;
    Date birthDay;
    float diemToan;
    float diemVan;
    float diemAnh;
public:
    friend istream &operator>>(istream &in, Candidate &candidate);
    friend ostream &operator<<(ostream &out, const Candidate &candidate);
    float tongDiem();
};

istream &operator>>(istream &in, Candidate &candidate) {
    cout << "Ma thi sinh: "; in >> candidate.ma; in.ignore();
    cout << "Ten: "; getline(in, candidate.ten);
    cout << "Ngay sinh: "; in >> candidate.birthDay;
    cout << "Diem Toan: "; in >> candidate.diemToan;
    cout << "Diem Anh: "; in >> candidate.diemAnh;
    cout << "Diem Van: "; in >> candidate.diemVan;
    return in;
}

ostream &operator<<(ostream &out, const Candidate &candidate) {
    out << "Ma thi sinh: " << candidate.ma << "\n";
    out << "Ten: " << candidate.ten << "\n";
    out << "Ngay sinh: " << candidate.birthDay << "\n";
    out << "Diem Toan: " << candidate.diemToan << "\n";
    out << "Diem Anh: " << candidate.diemAnh << "\n";
    out << "Diem Van: " << candidate.diemVan;
    return out;
}

float Candidate::tongDiem() {
    return diemToan + diemAnh + diemVan;
}

class TestCandidate {
private:
    Candidate *listCandidate;
    int size;
public:
    TestCandidate(int size);
    ~TestCandidate();
    friend istream &operator>>(istream &in, TestCandidate &testCandidate);
    void ThongTinSinhVienTheoDieuKienTongDiem(int condition);
};

TestCandidate::TestCandidate(int size) {
    this->size = 0;
    if(size >= 0) {
        this->size = size;
        this->listCandidate = new Candidate[size];
    }
    else {
        this->listCandidate = nullptr;
    }
}

TestCandidate::~TestCandidate() {
    if(this->listCandidate != nullptr) {
        delete []listCandidate;
    }
}

istream &operator>>(istream &in, TestCandidate &testCandidate) {
    for(int i = 0; i < testCandidate.size; i++) {
        cout << "Nhap thi sinh " << i + 1 << ":\n";
        cin >> testCandidate.listCandidate[i];
    }
    return in;
}

void TestCandidate::ThongTinSinhVienTheoDieuKienTongDiem(int condition) {
    if(this->listCandidate == nullptr) {
        return;
    }
    for(int i = 0; i < size; i++) {
        if(this->listCandidate[i].tongDiem() > condition) {
            cout << this->listCandidate[i] << "\n";
            cout << "Tong diem: " << this->listCandidate[i].tongDiem() << "\n";
        }
    }
}

int main() {
    cout << "Nhap so luong thi sinh: ";
    int n; cin >> n;
    TestCandidate TestCandidate(n);
    cin >> TestCandidate;
    cout << "Thong tin thi sinh co tong diem lon hon 15:\n";
    TestCandidate.ThongTinSinhVienTheoDieuKienTongDiem(15);

    return 0;
}