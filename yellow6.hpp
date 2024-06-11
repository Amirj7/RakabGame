#include <iostream>

class Yellow6
{
    public:
        int getPoint(){
            return point;
        }

        int getNumOfCard(){
            return numOfCard;
        }
    private:
        const int point = 6;
        const int numOfCard = 8;
};