#pragma once
#include <iostream>
#include "cart.hpp"

class Yellow2 : public Card
{
    public:
    int getPoint() const override
    {
        return 2;
    }
    int getNumOfCard() const override
    {
        return 8;
    }
};