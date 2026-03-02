#include <iostream>
#include <vector>
#include <cstdio>

struct Payoff {
    int player1;
    int player2;
};

struct Strategy{
    std::vector<bool> actionHistory;
    std::vector<int> pointHistory = {0};
    bool (*run)(std::vector<bool> actionHistory);
    void display(){
        std::cout << "Current points: " << pointHistory.back() << std::endl;
        std::cout << "Displaying actionHistory (C for Cooperate and D for Defect):" << std::endl;
        for (bool action:actionHistory){
            char A;
            switch(action){
                case 1: A = 'C'; break;
                case 0: A = 'D'; break;
            }
            std::cout << A << " ";
        }
        std::cout << "\n" << std::endl;
    }
} s1, s2;

bool S1Behaviour(std::vector<bool> actionHistory){
    //Modify strategy here, by default on tit for tat
    if (actionHistory.empty()) return 1;
    else return actionHistory.back();
}

bool S2Behaviour(std::vector<bool> actionHistory){
    //By default cooperates every round
    return 1;
}

void run(Strategy& s1, Strategy& s2, int noRounds, Payoff matrix[2][2]){
    for (int round = 1; round <= noRounds; round++){
        bool s1_value = s1.run(s2.actionHistory), s2_value = s2.run(s1.actionHistory);
        s1.pointHistory.push_back(s1.pointHistory.back() + matrix[s1_value][s2_value].player1);
        s2.pointHistory.push_back(s2.pointHistory.back() + matrix[s1_value][s2_value].player2);
        s1.actionHistory.push_back(s1_value); s2.actionHistory.push_back(s2_value);
    }

    std::cout << "Strategy 1 Stats:" << std::endl;
    s1.display();
    std::cout << "Strategy 2 Stats:" << std::endl;
    s2.display();

    FILE* pipe = _popen("python plot.py", "w");
    for (int i = 1; i<= noRounds; i++){
        fprintf(pipe, "%d %d\n", s1.pointHistory[i], s2.pointHistory[i]);
    }
    _pclose(pipe);
}

int main(){
    s1.run = S1Behaviour, s2.run = S2Behaviour;
    int noRounds;
    std::cout << "Enter number of rounds: "; std::cin >> noRounds;

    Payoff matrix[2][2];
    std::cout << "Enter payoff matrix values:\n(Format player1 player2 for each cell)\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << "Player1 " << (i == 1 ? "Cooperate" : "Defect") << ", Player2 " << (j == 1 ? "Cooperate" : "Defect") << " :";
            std::cin >> matrix[i][j].player1 >> matrix[i][j].player2;
        }
    }

    run(s1,s2,noRounds, matrix);
}