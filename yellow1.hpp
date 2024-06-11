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

        bool isYellowcard1(const std::string& card)// just for test
        {
            return card.find("yellow1") != std::string::npos;
        }
    private:
        const int point = 1;
        const int numOfCard = 10;
};