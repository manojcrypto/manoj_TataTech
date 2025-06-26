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
            // Strike
            if (rolls[rollIndex] == 10) {
                totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                rollIndex += 1;
            }
            // Spare
            else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) {
                totalScore += 10 + rolls[rollIndex + 2];
                rollIndex += 2;
            }
            // Open frame
            else {
                totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
                rollIndex += 2;
            }
        }

        return totalScore;
    }
};

int main() {
    BowlingGame game;

    // Correct input from image example (total score: 133)
    vector<int> inputRolls = {4,5, 4,5, 6,4, 10, 9,0, 9,1, 10, 10, 2,4, 2,1};

    for (int pins : inputRolls) {
        game.roll(pins);
    }

    cout << "Final Score: " << game.score() << endl;

    return 0;
}
