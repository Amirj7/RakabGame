#pragma once
#include <iostream>
#include "card.hpp"

class Yellow4 : public Cards
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