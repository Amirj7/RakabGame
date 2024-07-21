#include <iostream>
#include "card.hpp"

class rishSefid : public Cards
{
    public:
    int getNumOfCard() const override
    {
        return 6;
    }

    int getPoint() const override
    {
        return 0;
    }
};