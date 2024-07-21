#include <iostream>
#include "card.hpp"

class Shirzan : public Cards
{
    public:
        int getNumOfCard() const override
    {
        return 12;
    }
    int getPoint() const override
    {
        return 0;
    }

};