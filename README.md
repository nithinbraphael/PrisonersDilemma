A program that simulates the classic Prisoner’s Dilemma from game theory. It involves two players using strategies S1 and S2. In each round, both players independently choose either to cooperate or defect. The current default payoff matrix is:

- +10, +10 if both players cooperate

- +20, -10 if one defects while the other cooperates

- 0, 0 if both players defect

Support for custom payoff matrices will be added in future updates. Player strategy logic can be modified within the S1Behaviour(vector<int> history) and S2Behaviour(vector<int> history) function block.
