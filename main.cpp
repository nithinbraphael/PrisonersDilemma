#include <iostream>
#include <vector>

struct Payoff {
    int player1;
    int player2;
};

struct Strategy{
    int points = 0;
    std::vector<int> history;
    bool (*run)(std::vector<int> history);

    void display(){
        std::cout << "Current points: " << points << std::endl;
        std::cout << "Displaying history (C for Cooperate and D for Defect):" << std::endl;
        for (int action:history){
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

bool S1Behaviour(std::vector<int> history){
    //Modify strategy here, by default on tit for tat
    if (history.empty()) return 1;
    else return history.back();
}

bool S2Behaviour(std::vector<int> history){
    //By default cooperates every round
    return 1;
}

void run(Strategy s1, Strategy s2, int noRounds, Payoff matrix[2][2]){
    for (int round = 0; round < noRounds; round++){
        bool s1_value = s1.run(s2.history), s2_value = s2.run(s1.history);
        s1.points += matrix[s1_value][s2_value].player1; s2.points += matrix[s1_value][s2_value].player2;
        s1.history.push_back(s1_value); s2.history.push_back(s2_value);
    }

    std::cout << "Strategy 1 Stats:" << std::endl;
    s1.display();
    std::cout << "Strategy 2 Stats:" << std::endl;
    s2.display();
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