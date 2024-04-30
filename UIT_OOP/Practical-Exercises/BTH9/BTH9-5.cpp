#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0);
    Point operator=(const Point &point);
    friend istream &operator>>(istream &in, Point &point);
    friend ostream &operator<<(ostream &out, const Point &point);
    int getX() const;
    int getY() const;
};

Point::Point(int x, int y) : x(x), y(y) {}

Point Point::operator=(const Point &point) {
    this->x = point.x;
    this->y = point.y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;   
}

istream &operator>>(istream &in, Point &point) {
    in >> point.x >> point.y;
    return in;
}

ostream &operator<<(ostream &out, const Point &point) {
    out << point.x << " " << point.y;
    return out;
}

class Hinh {
protected:
    vector<Point> points;
public:
    vector<Point> getPoints();
};

vector<Point> Hinh::getPoints() {
    return points;
}

class HinhChuNhat : public Hinh {
public:
    HinhChuNhat(Point point, int chieuDai, int chieuRong);
};

HinhChuNhat::HinhChuNhat(Point point, int chieuDai, int chieuRong) {
    this->points.resize(4);
    this->points[0] = point;
    this->points[1] = Point(point.getX() + chieuDai, point.getY());
    this->points[2] = Point(point.getX(), point.getY() - chieuRong);
    this->points[3] = Point(point.getX() + chieuDai, point.getY() - chieuRong);
}

class HinhTron : public Hinh {
public:
    HinhTron(Point point, int banKinh);
};

HinhTron::HinhTron(Point point, int banKinh) {
    this->points.resize(4);
    this->points[0] = point;
    this->points[1] = Point(point.getX() - banKinh, point.getY());
    this->points[2] = Point(point.getX(), point.getY() - banKinh);
    this->points[3] = Point(point.getX() + banKinh, point.getY());
    this->points[4] = Point(point.getX(), point.getY() + banKinh);
} 

class HinhTamGiac : public Hinh {
public:
    HinhTamGiac(Point x, Point y, Point z);
};

HinhTamGiac::HinhTamGiac(Point x, Point y, Point z) {
    this->points.resize(3);
    this->points[0] = x;
    this->points[1] = y;
    this->points[2] = z;
}

int main() {

    const char *linkReadFile = "C:\\Users\\ADMIN\\Desktop\\INPUT.DAT";
    const char *linkWriteFile = "C:\\Users\\ADMIN\\Desktop\\OUTPUT.DAT";

    ifstream readFile;
    readFile.open(linkReadFile);
    if(readFile.fail()) {
        cout << "Mo file de doc khong hop le\n";
        return -1;
    }

    int n; readFile >> n;
    Hinh **hinh = new Hinh*[n];
    if(hinh == nullptr) {
        cout << "nullptr\n";
        return -1;
    }
    for(int i = 0; i < n; i++) {
        char ch; readFile >> ch;
        Point x;
        readFile >> x;
        if(ch == 'C') {
            int chieuDai, chieuRong;
            readFile >> chieuDai >> chieuRong;
            hinh[i] = new HinhChuNhat(x, chieuDai, chieuRong);
        }
        else if(ch == 'T') {
            int banKinh;
            readFile >> banKinh;
            hinh[i] = new HinhTron(x, banKinh);
        }
        else if(ch == 'G') {
            Point point1, point2;
            readFile >> point1 >> point2;
            hinh[i] = new HinhTamGiac(x, point1, point2);
        }
    }

    readFile.close();

    Point point1(INT_MAX), point2, point3, point4(INT_MAX);

    for(int i = 0; i < n; i++) {
        vector<Point> points = hinh[i]->getPoints();
        for(const Point &point : points) {
            // tim x nho nhat
            if(point.getX() < point1.getX()) {
                point1 = point;
            }
            // tim y cao nhat
            if(point.getY() > point2.getY()) {
                point2 = point; 
            }
            // tim x lon nhat
            if(point.getX() > point3.getX()) {
                point3 = point;
            }
            // tim y thap nhat;
            if(point.getY() < point4.getY()) {
                point4 = point;
            }
        }
    }
    Point topLeft;
    if(point2.getY() > point1.getY()) { 
        topLeft = Point(point1.getX(), point2.getY());
    }
    else topLeft = point1;
    int chieuDai = abs(topLeft.getX() - point3.getX());
    int chieuRong = abs(topLeft.getY() - point4.getY());

    ofstream writeFile;
    writeFile.open(linkWriteFile);
    if(writeFile.fail()) {
        cout << "Khong mo duoc file de ghi\n";
        return -1;
    }

    writeFile << topLeft << " " << chieuDai << " " << chieuRong;

    writeFile.close();

    for(int i = 0; i < n; i++) {
        delete hinh[i];
    }

    delete []hinh;

    return 0;
}