#include <iostream>

class Yellow4
{
    public:
        int getPoint(){
            return point;
        }

        int getNumOfCard(){
            return numOfCard;
        }
    private:
        const int point = 4;
        const int numOfCard = 8;
};