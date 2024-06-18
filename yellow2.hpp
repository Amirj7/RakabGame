#pragma once
#include <iostream>
#include "card.hpp"

class Yellow2 : public Cards
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