#pragma once
#include <iostream>
#include "card.hpp"

class Yellow3 : public Cards
{
    public:
        int getPoint() const override
    {
        return 3;
    }
    int getNumOfCard() const override
    {
        return 8;
    }
};