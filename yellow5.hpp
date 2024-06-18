#pragma once
#include <iostream>
#include "card.hpp"

class Yellow5 : public Cards
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