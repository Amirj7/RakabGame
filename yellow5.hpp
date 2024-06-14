#pragma once
#include <iostream>
#include "cart.hpp"

class Yellow5 : public Card
{
    public:
        int getPoint() const override
    {
        return 5;
    }
    int getNumOfCard() const override
    {
        return 8;
    }
};