#pragma once
#include <iostream>
#include "card.hpp"

class Yellow6 : public Cards
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