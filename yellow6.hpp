#pragma once
#include <iostream>
#include "cart.hpp"

class Yellow6 : public Card
{
    public:
        int getPoint() const override
    {
        return 6;
    }
    int getNumOfCard() const override
    {
        return 8;
    }
};