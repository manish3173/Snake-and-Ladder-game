#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SnakeLadderGame {
private:
    int player1, player2;
    bool player1Turn;

    int rollDice() {
        return (rand() % 6) + 1;
    }

    int movePlayer(int position) {
        switch (position) {
            // Snakes
            case 99: return 80;
            case 95: return 75;
            case 92: return 88;
            case 89: return 68;
            case 74: return 53;
            case 62: return 19;
            case 49: return 11;
            case 46: return 25;
            case 16: return 6;

            // Ladders
            case 2: return 38;
            case 7: return 14;
            case 8: return 31;
            case 15: return 26;
            case 21: return 42;
            case 28: return 84;
            case 36: return 44;
            case 51: return 67;
            case 71: return 91;
            case 78: return 98;
            case 87: return 94;

            default: return position;
        }
    }

public:
    SnakeLadderGame() {
        player1 = 0;
        player2 = 0;
        player1Turn = true;
        srand(time(0));
    }

    void play() {
        while (player1 < 100 && player2 < 100) {
            int roll = rollDice();
            if (player1Turn) {
                player1 += roll;
                if (player1 > 100) player1 = 100;
                player1 = movePlayer(player1);
                cout << "Player 1 rolls a " << roll << " and moves to " << player1 << endl;
                if (player1 >= 100) {
                    cout << "Player 1 wins!" << endl;
                    break;
                }
            } else {
                player2 += roll;
                if (player2 > 100) player2 = 100;
                player2 = movePlayer(player2);
                cout << "Player 2 rolls a " << roll << " and moves to " << player2 << endl;
                if (player2 >= 100) {
                    cout << "Player 2 wins!" << endl;
                    break;
                }
            }
            player1Turn = !player1Turn;
        }
    }
};

int main() {
    SnakeLadderGame game;
    game.play();
    return 0;
}
