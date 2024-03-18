#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

enum PsychologicalState{
    OPENTOEXP = 1,
    COSC  = 5,
    EXTRAVER = 9,
    AGREEA = 13,
    NEUROTI = 17
};

enum PropertyPer{
    HIGH,
    MIDDLE,
    LOW
};

class Personality {
protected:
    int coscientiouness; // Tự chủ tận tâm
    int extraversion;    // Hướng ngoại
    int agreeableness;   // Hoà đồng   
    int opennessToExp;   // Sẵn sàng trải nghiệm
    int neuroticism;     // Bất ổn cảm xúc
public:
    virtual int SplitStringPersonanlity(string mentality, int index) = 0;
    
    string getOpenToExpProperty(int index) {
        if(index == HIGH) {
            return "Nguoi co diem cao o yeu to nay thuong la nguoi thich\n"
                    "nhung y tuong moi, thich hieu biet linh vuc nhung dong\n"
                    "cung thich tu do, khong thich bi rang buoc...\n";          
        }
        if(index == MIDDLE) {
            return "Khong xac dinh ro\n";
        }
        return "Nguoi co diem thap o yeu to nay thuong kha bao thu,\n"
                " kho tiep nhan nhung y tuong moi, la. Ho thich su\n"
                "on dinh, quen thuoc va thuc te.\n";
    }
    string getExtraverProperty(int index) {
        if(index == HIGH) {
            return "Nguoi co diem cao o yeu to nay thuong la nguoi nhiet\n"
            "tinh, nang dong, giao tiep tot, thich the hien ban than.\n";
        }
        if(index == MIDDLE) {
            return "Khong xac dinh ro\n";
        }
        return "Nguoi co diem thap o yeu to nay thuong ngai giao tiep,\n"
                "khong thich su noi bat, thich duoc lam viec doc lap.\n";
    }

    string getAgreeAProperty(int index) {
        if(index == HIGH) {
            return "Nguoi co diem cao o yeu to nay thuong than thien,\n"
            "coi mo, dong cam voi moi nguoi nhung nhieu khi \"thieu\n"
            "chinh kien\".\n";
        }
        if(index == MIDDLE) {
            return "Khong xac dinh ro\n";
        }
        return "Nguoi co diem thap thuong dat loi ich cua ban than\n"
                "len tren, it dong cam, chia se voi dong nghiep, co\n"
                "tinh canh tranh cao.\n";
    }

    string getCoscProperty(int index) {
        if(index == HIGH) {
            return "Nguoi co diem cao o yeu to nay thuong la nguoi\n"
                    "cham chi, co kha nang chiu ap luc tot. Ho thuong\n"
                    "la nguoi gan bo, trung thanh voi to chuc.\n";
        }
        if(index == MIDDLE) {
            return "Khong xac dinh ro\n";
        }
        return "Nguoi co diem thap o yeu to nay thuong de bo cuoc,\n"
                "kha nang chiu ap luc, tuan thu ky luat cua to chuc\n"
                "kem.\n";
    }

    string getNeurotiProperty(int index) {
        if(index == HIGH) {
            return "Nguoi co diem cao o yeu to nay thuong co cac cam xuc\n"
                    "tieu cuc nhu: lo lang, buc boi, tu ti, yeu duoi va\n"
                    "kha nang chiu ap luc kem.\n";
        }
        if(index == MIDDLE) {
            return "Khong xac dinh ro\n";
        }
        return "Nguoi co diem thap o yeu to nay thuong kiem soat duoc cam\n"
                "xuc, ung pho voi cang thang tot, it bi ben ngoai anh huong\n"
                "den tam trang cua ban than.\n";
    }
};

class Human : public Personality {
private:
    string name;
    string mentality;
public:
    Human(){}

    Human(string name, string mentality) {
        this->name = name;
        this->mentality = mentality;
        AddPersonality();
    }

    void AddPersonality() {
        this->opennessToExp = SplitStringPersonanlity(mentality, OPENTOEXP);
        this->coscientiouness = SplitStringPersonanlity(mentality, COSC);
        this->extraversion = SplitStringPersonanlity(mentality, EXTRAVER);
        this->agreeableness = SplitStringPersonanlity(mentality, AGREEA);
        this->neuroticism = SplitStringPersonanlity(mentality, NEUROTI);
    }

    string getName() {
        return name;
    }

    int SplitStringPersonanlity(string mentality, int index) override {
        return stoi(mentality.substr(index, 2));
    } 

    friend istream &operator>>(istream &in, Human &human) {
        in.ignore();
        getline(in, human.name);
        cin >> human.mentality;
        return in;
    }

    void AnalyzeAppropriateState(int status, int index) {
        if(status >= 70) {
            if(index == COSC) {
                cout << getCoscProperty(HIGH);
            }
            else if(index == EXTRAVER) {
                cout << getExtraverProperty(HIGH);
            }
            else if(index == AGREEA) {
                cout << getAgreeAProperty(HIGH);
            }
            else if(index == OPENTOEXP) {
                cout << getOpenToExpProperty(HIGH);
            }
            else if(index == NEUROTI) {
                cout << getNeurotiProperty(HIGH);
            }
        }
        else if(status <= 30) {
            if(index == COSC) {
                cout << getCoscProperty(LOW);
            }
            else if(index == EXTRAVER) {
                cout << getExtraverProperty(LOW);
            }
            else if(index == AGREEA) {
                cout << getAgreeAProperty(LOW);
            }
            else if(index == OPENTOEXP) {
                cout << getOpenToExpProperty(LOW);
            }
            else if(index == NEUROTI) {
                cout << getNeurotiProperty(LOW);
            }
        }
        else {
            if(index == COSC) {
                cout << getCoscProperty(MIDDLE);
            }
            else if(index == EXTRAVER) {
                cout << getCoscProperty(MIDDLE);
            }
            else if(index == AGREEA) {
                cout << getAgreeAProperty(MIDDLE);
            }
            else if(index == OPENTOEXP) {
                cout << getOpenToExpProperty(MIDDLE);
            }
            else if(index == NEUROTI) {
                cout << getNeurotiProperty(MIDDLE);
            }
        }
    }

    void PsychologicalAssessment() {
        cout << "San sang trai nghiem (O): " << this->opennessToExp << "\n";
        AnalyzeAppropriateState(this->opennessToExp, OPENTOEXP);
        cout << "Tu chu tan tam (C): " << this->coscientiouness << "\n";
        AnalyzeAppropriateState(this->coscientiouness, COSC);
        cout << "Huong ngoai (E): " << this->extraversion << "\n";
        AnalyzeAppropriateState(this->extraversion, EXTRAVER);
        cout << "Hoa dong de chiu (A): " << this->agreeableness << "\n";
        AnalyzeAppropriateState(this->agreeableness, AGREEA);
        cout << "Bat on cam xuc (N): " << this->neuroticism << "\n";
        AnalyzeAppropriateState(this->neuroticism, NEUROTI);

    }
};

int main() {
    
    // Nhập vào thông tin đánh giá tâm lý của một người
    Human person1;
    cin >> person1;
    // Nhập vào kết quả đánh giá tâm lý của một người trong danh sách
    cout << "----------------\n";
    int num;
    cin >> num;
    vector<Human> human(num);
    for(int i = 0; i < num; i++) {
        cin.ignore();
        string name;
        getline(cin, name);
        string mental;
        cin >> mental;
        human[i] = Human(name, mental);
    }
    // Chọn một người trong danh sách và cho biết thông tin về tính cách của người đó
    cout << "-------------------\n";
    srand(time(nullptr));
    int index = rand() % 2 + 0;
    cout << human[index].getName() << "\n";
    human[index].PsychologicalAssessment();

    return 0;
}