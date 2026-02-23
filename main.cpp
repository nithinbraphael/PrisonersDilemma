#include <iostream>
#include <vector>
using namespace std;

class Strategy{
    public:
    int points = 0;
    vector<int> history;
    bool (*run)(vector<int> history);

    void display(){
        cout << "Current points: " << points << endl;
        cout << "Displaying history (C for Cooperate and D for Defect):" << endl;
        for (int action:history){
            char A;
            switch(action){
                case 1: A = 'C'; break;
                case 0: A = 'D'; break;
            }
            cout << A << " ";
        }
        cout << "\n" << endl;
    }
} s1, s2;

bool S1Behaviour(vector<int> history){
    //Modify strategy here, by default on tit for tat
    if (history.empty()) return 1;
    else return history.back();
}

bool S2Behaviour(vector<int> history){
    //By default cooperates every round
    return 1;
}

void run(Strategy s1, Strategy s2, int noRounds){
    for (int round = 0; round < noRounds; round++){
        if (s1.run(s2.history) == 1 && s2.run(s1.history) == 1){
            s1.history.push_back(1);
            s2.history.push_back(1);
            s1.points += 10;
            s2.points += 10;
        }
        else if (s1.run(s2.history) == 0 && s2.run(s1.history) == 1){
            s1.history.push_back(0);
            s2.history.push_back(1);
            s1.points += 20;
            s2.points -= 10;
        }
        else if (s1.run(s2.history) == 1 && s2.run(s1.history) == 0){
            s1.history.push_back(1);
            s2.history.push_back(0);
            s1.points -= 10;
            s2.points += 20;
        }
        else if (s1.run(s2.history) == 0 && s2.run(s1.history) == 0){
            s1.history.push_back(0);
            s2.history.push_back(0);
            s1.points += 0;
            s2.points += 0;
        }
    }

    cout << "Strategy 1 Stats:" << endl;
    s1.display();
    cout << "Strategy 2 Stats:" << endl;
    s2.display();
}

int main(){
    s1.run = S1Behaviour, s2.run = S2Behaviour;
    int noRounds;
    cout << "Enter number of rounds: "; cin >> noRounds;
    run(s1,s2,noRounds);
}