#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class DaThuc {
private:
    vector<pair<double, double>> daThuc;
    int size;
public:
    friend istream &operator>>(istream &in, DaThuc &dathuc) {
        in >> dathuc.size;
        for(int i = 0; i < dathuc.size; i++) {
            double heso, somu;
            cin >> heso >> somu;
            dathuc.daThuc.push_back({heso, somu});
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, const DaThuc &dathuc) {
        for(int i = 0; i < dathuc.size; i++) {
            double heso = dathuc.daThuc[i].first;
            double somu = dathuc.daThuc[i].second;
            if(heso < 0) {
                out << heso << "x^" << somu << " ";
            }
            else if(heso > 0 && i != 0){ 
                out << "+ " << heso << "x^" << somu << " ";
            }
            else if(heso == 0) {
                
            }
            else if(somu == 0) {
                out << 1 << " ";
            }
        }
        return out;
    }

    DaThuc operator+(const DaThuc &dathuc) {
       DaThuc kq;
        int i = 0, j = 0;
        while (i < size && j < dathuc.size) {
            if (daThuc[i].second == dathuc.daThuc[j].second) {
                kq.daThuc.push_back({daThuc[i].first + dathuc.daThuc[j].first, daThuc[i].second});
                ++i;
                ++j;
            } else if (daThuc[i].second > dathuc.daThuc[j].second) {
                kq.daThuc.push_back(daThuc[i++]);
            } else {
                kq.daThuc.push_back(dathuc.daThuc[j++]);
            }
        }
        while (i < size) {
            kq.daThuc.push_back(daThuc[i++]);
        }
        while (j < dathuc.size) {
            kq.daThuc.push_back(dathuc.daThuc[j++]);
        }
        kq.size = kq.daThuc.size();
        return kq;
    }
};

int main() {

    DaThuc dathuc;
    cin >> dathuc;
    cout << dathuc << "\n";

    DaThuc dathuc2;
    cin >> dathuc2;
    cout << dathuc2 << "\n";

    cout << dathuc + dathuc2 << "\n";

    return 0;
}