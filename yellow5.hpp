#include <iostream>

class Yellow5
{
    public:
        int getPoint(){
            return point;
        }

        int getNumOfCard(){
            return numOfCard;
        }
    private:
        const int point = 5;
        const int numOfCard = 8;
};