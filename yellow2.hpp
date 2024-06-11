#include <iostream>

class Yellow2
{
    public:
        int getPoint(){
            return point;
        }

        int getNumOfCard(){
            return numOfCard;
        }
    private:
        const int point = 2;
        const int numOfCard = 8;
};