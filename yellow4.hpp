#pragma once
#include <iostream>
#include "cart.hpp"

class Yellow4 : public Card
{
    public:
        int getPoint() const override
    {
        return 4;
    }
    int getNumOfCard() const override
    {
        return 8;
    }
};