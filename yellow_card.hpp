#include <iostream>
#include "player.hpp"

using namespace std;

class card : public Player 
{
public:
    void calculateScore()
    {
        switch (yellowCard)
        {
            case yellow1:
                score += 1;
                break;
            case yellow2:
                score += 2;
                break;
            case yellow3:
                score += 3;
                break;
            case yellow4:
                score += 4;
                break;
            case yellow5:
                score += 5;
                break;
            case yellow6:
                score += 6;
                break;
            case yellow10:
                score += 10;
                break;
            default:
                break;
        }
    }

private:
    enum YellowCard {
        yellow1 = 1,
        yellow2 = 2,
        yellow3 = 3,
        yellow4 = 4,
        yellow5 = 5,
        yellow6 = 6,
        yellow10 = 10
    };
    YellowCard yellowCard;
};
