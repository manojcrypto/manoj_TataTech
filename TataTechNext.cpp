#include <iostream>
#include <vector>
using namespace std;

class BowlingGame {
private:
    vector<int> rolls;

public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int rollIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (rolls[rollIndex] == 10) { // Strike
                totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                rollIndex += 1;
            } else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) { // Spare
                totalScore += 10 + rolls[rollIndex + 2];
                rollIndex += 2;
            } else { // Open frame
                totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
                rollIndex += 2;
            }
        }

        return totalScore;
    }
};

int main() {
    BowlingGame game;
    int try1, try2;

    for (int frame = 1; frame <= 10; ++frame) {
        cout << "Frame " << frame << ":\n";

        while (true) {
            cout << "  Enter try1: ";
            if (!(cin >> try1) || try1 < 0 || try1 > 10) {
                cout << "  ❌ Invalid input. Enter a number between 0 and 10.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (try1 == 10 && frame < 10) { // Strike (skip try2)
                game.roll(10);
                break;
            }

            cout << "  Enter try2: ";
            if (!(cin >> try2) || try2 < 0 || try2 > 10) {
                cout << "  ❌ Invalid input. Enter a number between 0 and 10.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (try1 + try2 > 10 && frame < 10) {
                cout << "  ❌ Total of try1 + try2 cannot exceed 10 in normal frames.\n";
                continue;
            }

            game.roll(try1);
            game.roll(try2);
            break;
        }

        // Handle bonus rolls in 10th frame
        if (frame == 10 && (try1 == 10 || try1 + try2 == 10)) {
            int bonus1;
            cout << "  Bonus roll 1: ";
            while (!(cin >> bonus1) || bonus1 < 0 || bonus1 > 10) {
                cout << "  ❌ Invalid input. Enter a number between 0 and 10.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            game.roll(bonus1);

            if (try1 == 10 || bonus1 == 10 || try1 + try2 == 10) {
                int bonus2;
                cout << "  Bonus roll 2: ";
                while (!(cin >> bonus2) || bonus2 < 0 || bonus2 > 10) {
                    cout << "  ❌ Invalid input. Enter a number between 0 and 10.\n";
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
                game.roll(bonus2);
            }
        }
    }

    cout << "\n🎳 Final Score: " << game.score() << endl;

    return 0;
}
