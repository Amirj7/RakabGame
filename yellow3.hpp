#pragma once
#include <iostream>
#include "cart.hpp"

class Yellow3 : public Card
{
    public:
        int getPoint() const override
    {
        return 1;
    }
    int getNumOfCard() const override
    {
        return 8;
    }
};