#include <iostream>

class Yellow1
{
    public:
        int getPoint(){
            return point;
        }

        int getNumOfCard(){
            return numOfCard;
        }
    private:
        const int point = 1;
        const int numOfCard = 10;
};