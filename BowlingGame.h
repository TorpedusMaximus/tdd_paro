#pragma once

using namespace std;

struct Round {
    int throw1;
    int throw2;
    int bonus = 0;
    int total = 0;
};

class BowlingGame {
public:
    void roll(int pins) {
        if (flag) {
            flag = false;
            round.throw1 = pins;
            round.total += pins;
            if (pins == 10) {
                round.bonus = 2;
                roll(0);
            }
        } else {
            flag = true;
            round.throw2 = pins;
            round.total += pins;
            if (round.throw1 + round.throw2 == 10 && round.bonus == 0) {
                round.bonus = 1;
            }

            if (roundNumber > 0) {
                if (roundScores[roundNumber - 1].bonus == 2) {
                    roundScores[roundNumber - 1].total += round.throw1 + round.throw2;
                    if (round.bonus == 2) {
                        roundScores[roundNumber - 1].bonus = 1;
                    } else {
                        roundScores[roundNumber - 1].bonus = 0;
                    }
                }
                if (roundScores[roundNumber - 1].bonus == 1) {
                    roundScores[roundNumber - 1].total += round.throw1;
                    roundScores[roundNumber - 1].bonus = 0;
                }
            }

            if (roundNumber > 1) {
                if (roundScores[roundNumber - 2].bonus == 1) {
                    roundScores[roundNumber - 2].total += round.throw1;
                }
            }

            roundNumber += 1;
            roundScores.push_back(round);
            round.total = 0;
            round.bonus = 0;
        }
    }

    int getScore() {
        int score = 0;
        int i = 0;
        for (auto item: roundScores) {
            i++;
            if (i > 10) {
                break;
            }
            score += item.total;
        }
        return score;
    }

private:
    bool flag = true;
    vector<Round> roundScores;
    int roundNumber = 0;
    Round round;
};

