#include <iostream>
#include "player.h"

using namespace std;

class card : public player 
{
public:
    void calculateScore()
    {
        switch (yellowCard)
        {
            case Soldier:
                score += 1;
                break;
            case Private:
                score += 2;
                break;
            case Corporal:
                score += 3;
                break;
            case Lance_Corporal:
                score += 4;
                break;
            case Sergeant:
                score += 5;
                break;
            case Staff_Sergeant:
                score += 6;
                break;
            case Captain:
                score += 10;
                break;
            default:
                break;
        }
    }

private:
    enum YellowCard {
        Soldier = 1,
        Private = 2,
        Corporal = 3,
        Lance_Corporal = 4,
        Sergeant = 5,
        Staff_Sergeant = 6,
        Captain = 10
    };
    YellowCard yellowCard;
};
