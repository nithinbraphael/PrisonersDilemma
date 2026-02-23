#include <iostream>
#include <vector>
using namespace std;

class Strategy{
    public:
    int points = 0;
    vector<int> history;
    void (*run)();
} s1, s2;

void S1Behaviour(){}
void S2Behaviour(){}

int main(){
    s1.run = S1Behaviour, s2.run = S2Behaviour;
    int noRounds;
    cout << "Enter number of rounds: "; cin >> noRounds;

}