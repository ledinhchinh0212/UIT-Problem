#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Gate {
protected:
    string nameGate;
    string Guard;
public:
    virtual void PrintInfomationGate() = 0;

    string getNameGate() {
        return nameGate;
    }

    virtual long long getMoney() {
        return 0;
    }

    virtual int getCommodity() {
        return 0;
    }

    virtual int getWisdom() {
        return 0;
    }

    
    virtual int getStrength() {
        return 0;
    }

};

class BusinessGate : public Gate {
private:
    long long money;
    int commodity;
public:
    BusinessGate(long long money, int commodity) {
        this->commodity = commodity;
        this->money = money;
        this->nameGate = "BusinessGate";
        this->Guard = "Ten lai buon";
    }

    void PrintInfomationGate() override {
        cout << "Name gate: " << nameGate << "\n";
        cout << "Name guard: " << Guard << "\n";
        cout << "Money: " << money << "\n";
        cout << "Commodity: " << commodity << "\n";
    }

    long long getMoney() {
        return money;
    }

    int getCommodity() {
        return commodity;
    }
};

class AcademicGate : public Gate {
private:
    int wisdom;
public:
    AcademicGate(int wisdom) {
        this->wisdom = wisdom;
        this->Guard = "Nha hien triet";
        this->nameGate = "AcademiGate";
    }
    
    void PrintInfomationGate() override{
        cout << "Name gate: " << nameGate << "\n";
        cout << "Name guard: " << Guard << "\n";
        cout << "Wisdom: " << wisdom << "\n";
    }

    int getWisdom() {
        return wisdom;
    }
};

class PowerGate : public Gate {
private:
    int strength;
public:
    PowerGate(int strength) {
        this->strength = strength;
        this->nameGate = "PowerGate";
        this->Guard = "Dung sy";
    }

    void PrintInfomationGate() override {
        cout << "Name gate: " << nameGate << "\n";
        cout << "Name guard: " << Guard << "\n";
        cout << "Strength: " << strength << "\n";
    }

    int getStrength() {
        return strength;
    }
};

class Prince {
private:
    long long money;
    int wisdomIndex;
    int strength;
public:
    Prince(){}

    Prince(long long money, int wisdomIndex, int strength) {
        this->money = money;
        this->wisdomIndex = wisdomIndex;
        this->strength = strength;
    }    

    long long getMoney() {
        return money;
    }

    void setMoney(int money) {
        this->money = money;
    }

    int getWisdomIndex() {
        return wisdomIndex;
    }

    int getStrength() {
        return strength;
    }

    void setStrength(int strength) {
        this->strength = strength;
    }

    void PrintInformationPrince() {
        cout << "Money: " << money << "\n";
        cout << "Wisdom Index: " << wisdomIndex << "\n";
        cout << "Power: " << strength << "\n";
    }

    static bool CheckPrinceCompleteSecurePrincess(vector<Gate*> &gate, Prince &prince) {
        for(int i = 0; i < gate.size(); i++) {
            if(gate[i]->getNameGate() == "BusinessGate") {
                if(prince.getMoney() < gate[i]->getMoney() * gate[i]->getCommodity()) {
                    return false;
                }
                else {
                    prince.setMoney(prince.getMoney() - (gate[i]->getMoney() * gate[i]->getCommodity()));
                }
            }
            else if(gate[i]->getNameGate() == "AcademicGate") {
                if(prince.getWisdomIndex() < gate[i]->getWisdom()) {
                    return false;
                }
            }
            else if(gate[i]->getNameGate() == "PowerGate") {
                if(prince.getStrength() < gate[i]->getStrength()) {
                    return false;
                }
                else {
                    prince.setStrength(prince.getStrength() - gate[i]->getStrength());
                }
            }
        }

        return true;
    }

};

int main() {

    int N;
    cin >> N;

    vector<Gate*> gate;

    for(int i = 0; i < N; i++) {
        cout << "1: Business Gate, 2: Academic Gate, 3: Power Gate\n";
        int type; cin >> type;
        if(type == 1) {
            cout << "Enter the merchant's amount: "; long long money;
            cin >> money;
            cout << "Enter the commodity: "; int commodity;
            cin >> commodity;
            gate.push_back(new BusinessGate(money, commodity));
        }
        else if(type == 2){
            cout << "Enter the wisdom of the sage: "; int wisdom;
            cin >> wisdom;
            gate.push_back(new AcademicGate(wisdom));
        }
        else if(type == 3) {
            cout << "Enter the power of the knight: "; int strength;
            cin >> strength;
            gate.push_back(new PowerGate(strength));
        }
    }

    cout << "\n##########\n";
    for(int i = 0; i < N; i++) {
        gate[i]->PrintInfomationGate();
        cout << "\n";
    }

    //
    cout << "Enter the prince's money: "; long long moneyP;
    cin >> moneyP;
    cout << "Enter the prince's wisdom index: "; int wisdomIP;
    cin >> wisdomIP;
    cout << "Enter the prince's power: "; int powerP;
    cin >> powerP;

    Prince prince(moneyP, wisdomIP, powerP);

    if(Prince::CheckPrinceCompleteSecurePrincess(gate, prince)) {
        cout << "Secure complete\n";
        prince.PrintInformationPrince();
    } else {
        cout << "Not secure complete\n";
    }


    // free data
    for(int i = 0; i < N; i++) {
        delete gate[i];
    }

    return 0;
}