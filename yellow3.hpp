#include <iostream>

class Yellow3
{
    public:
        int getPoint(){
            return point;
        }

        int getNumOfCard(){
            return numOfCard;
        }
    private:
        const int point = 3;
        const int numOfCard = 8;
};