#include <iostream>
#include <vector>
#include <map>

using namespace std;

class HolometabolousInsect {
protected:
    string nameInsect;
    int numberStages;
    vector<pair<int,int>> progressiveTimes;
    vector<int> stages;
public:
    string getNameInsect() {
        return nameInsect;
    }

    HolometabolousInsect(vector<int> stages) {
        this->stages = stages;
    }

    int getNumberStages() {
        return numberStages;
    }

    vector<pair<int,int>> getprogressiveTimes() {
        return progressiveTimes;
    };

    vector<int> getStages() {
        return stages;
    }

    void InfomationHoloInsect() {
        for(int i = 0; i < numberStages; i++) {
            cout << stages[i];
            if(i != numberStages - 1) {
                cout << "-";
            }
        }
    }

    static void CheckCompliesNormalRulesInsect(vector<HolometabolousInsect*> &insect) {
        for(int i = 0; i < insect.size(); i++) {
            cout << insect[i]->nameInsect << "\n";
            for(int j = 0; j < insect[i]->getNumberStages(); i++) {
                if(insect[i]->getprogressiveTimes()[j].first < insect[i]->stages[j] ||insect[i]->stages[j] > insect[i]->getprogressiveTimes()[j].second) {
                    insect[i]->InfomationHoloInsect();
                }
            }
        }
    }

    static bool CheckEcologicallyDiverseArea(vector<HolometabolousInsect*> &insect) {
        map<string, int> countInsect;
        for(int i = 0; i < insect.size(); i++) {
            string nameInsect = insect[i]->getNameInsect();
            countInsect[nameInsect]++;
        }
        if(countInsect.size() == 3) {
            return true;
        }
        return false;
    }
};

class Mosquito : public HolometabolousInsect {
public:
    Mosquito(vector<int> stages) : HolometabolousInsect(stages){
        this->stages = stages;
        this->nameInsect = "Mosquito";
        this->numberStages = 4;
        progressiveTimes.push_back({1, 3});
        progressiveTimes.push_back({4, 10});
        progressiveTimes.push_back({2, 3});
        progressiveTimes.push_back({5, 8});
    }
};

class Frog : public HolometabolousInsect{
public:
    Frog(vector<int> stages) : HolometabolousInsect(stages){
        this->stages = stages;
        this->nameInsect = "Frog";
        this->numberStages = 5;
        progressiveTimes.push_back({1, 3});
        progressiveTimes.push_back({4, 4});
        progressiveTimes.push_back({6, 9});
        progressiveTimes.push_back({1, 4});
        progressiveTimes.push_back({2, 4});
    }
};

class Butterfly : public HolometabolousInsect {
public:
    Butterfly(vector<int> stages) : HolometabolousInsect(stages) {
        this->stages = stages;
        this->nameInsect = "Buterfly";
        this->numberStages = 4;
        progressiveTimes.push_back({3, 8});
        progressiveTimes.push_back({15, 16});
        progressiveTimes.push_back({10, 10});
        progressiveTimes.push_back({2, 3});
    }
};


int main() {

    int N;
    cin >> N;
    vector<HolometabolousInsect*> HInsect;
    vector<int> stagesMosquito(4);
    vector<int> stagesFrog(5);
    vector<int> stagesButterfly(4);

    for(int i = 0; i < N; i++) {
        cout << "1: Mosquito, 2: Frog, 3: Butterfly\n";
        int type; cin >> type;
        if(type == 1) {
            cout << "The process of eggs developing into larvae: "; // by day
            cin >> stagesMosquito[0];
            cout << "The process of the larva developing into a pupa: ";
            cin >> stagesMosquito[1];
            cout << "The process of pupa becoming an adult mosquito: "; 
            cin >> stagesMosquito[2];
            cout << "The process by which mosquitoes begin to lay eggs: ";
            cin >> stagesMosquito[3];
            HInsect.push_back(new Mosquito(stagesMosquito));
        }
        else if(type == 2) {
            cout << "The process of eggs developing into tadpoles: "; // by week
            cin >> stagesFrog[0];
            cout << "The process of tadpoles developing legs ";        
            cin >> stagesFrog[1];
            cout << "The process of tadpoles developing legs become a frog: ";
            cin >> stagesFrog[2];
            cout << "The process from a baby frog to an adult frog: ";
            cin >> stagesFrog[3];
            cout << "The process by which frogs begin to lay eggs: ";
            cin >> stagesFrog[4];
            HInsect.push_back(new Frog(stagesFrog));
        }
        else if(type == 3) {
            cout << "The process of eggs hatching into caterpillars: ";
            cin >> stagesButterfly[0];
            cout << "The process of a caterpillar becoming a pupa: ";
            cin >> stagesButterfly[1];
            cout << "Process from pupa to caterpillar: ";
            cin >> stagesButterfly[2];
            cout << "The process of butterflies laying eggs: ";
            cin >> stagesButterfly[3];
            HInsect.push_back(new Butterfly(stagesButterfly));
        }
    }

    for(int i = 0; i < N; i++) {
        HInsect[i]->InfomationHoloInsect();
    }
    cout << "\n#################\n";
    
    HolometabolousInsect::CheckCompliesNormalRulesInsect(HInsect);

    cout << "\n#################\n";

    if(HolometabolousInsect::CheckEcologicallyDiverseArea(HInsect)) {
        cout << "The ecologically diverse area\n";
    }
    else cout << "Rhe ecologically not diverse area\n";

    for(int i = 0; i < N; i++) {
        delete HInsect[i];
    }

    return 0;
}