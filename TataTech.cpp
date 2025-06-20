#include <iostream>
#include <vector>
using namespace std;

class BowlingGame {
private:
    vector<int> rolls;

public:
    // Record each roll
    void roll(int pins) {
        rolls.push_back(pins);
    }

    // Calculate the final score
    int score() {
        int totalScore = 0;
        int rollIndex = 0;
        int frame = 0;

        while (frame < 10) {
            // Case: Strike
            if (rolls[rollIndex] == 10) {
                if (frame == 9) {
                    // 10th frame: just add 3 rolls (no bonus)
                    totalScore += rolls[rollIndex] + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                    break;
                } else {
                    totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                    rollIndex += 1;
                }
            }
            // Case: Spare
            else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) {
                if (frame == 9) {
                    // 10th frame: just add 3 rolls (no bonus)
                    totalScore += rolls[rollIndex] + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                    break;
                } else {
                    totalScore += 10 + rolls[rollIndex + 2];
                    rollIndex += 2;
                }
            }
            // Case: Open frame
            else {
                totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
                rollIndex += 2;
            }

            frame++;
        }

        return totalScore;
    }
};

int main() {
    BowlingGame game;

    // 🎯 Input from the image example, which should result in 133
    vector<int> inputRolls = {5, 4, 4, 5, 6, 4, 10, 9, 0, 9, 1, 10, 10, 2, 4, 6,2};
  //For frame 10, do not apply bonus logic — just sum the 2 or 3 rolls.
  
    vector<int> inputRollsFinal = {5, 4, 4, 5, 6, 4, 10, 9, 0, 9, 1, 10, 10, 2, 4, 2,1};

    // Feed all the rolls to the game
    for (int pins : inputRollsFinal) {
        game.roll(pins);
    }

    // Output the final score
    cout << "Final Score : " << game.score() << endl;
     for (int pins : inputRolls) {
        game.roll(pins);
    }

    // Output the final score
    cout << "Final Score for with extra bonus(6,2) : " << game.score() << endl;

    return 0;
}
