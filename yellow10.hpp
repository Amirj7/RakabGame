#include <iostream>

class Yellow10
{
    public:
        int getPoint(){
            return point;
        }

        int getNumOfCard(){
            return numOfCard;
        }
    private:
        const int point = 10;
        const int numOfCard = 8;
};