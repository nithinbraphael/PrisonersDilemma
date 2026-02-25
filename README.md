# Prisoner’s Dilemma Simulator

A customizable simulation of the classic **Prisoner’s Dilemma** from game theory. This program allows two players to repeatedly choose between **Cooperate** and **Defect**, with outcomes determined by a user-defined payoff matrix. The behavior of each player is controlled by customizable strategy functions, making it easy to experiment with different decision-making approaches.

## Game Rules

Each round:
- Both players independently choose:
  - **Cooperate (C)**
  - **Defect (D)**

The following is an example for a payoff matrix:

|                 | Player 2: C | Player 2: D|
|-----------------|-------------|------------|
| **Player 1: C** | (10,10)     | (-10, 20)  |
| **Player 1: D** | (20, -10)   | (0, 0)     |

## Strategy Customization

Each player’s decision logic is defined in:

int S1Behaviour(vector<int> history);
int S2Behaviour(vector<int> history);
