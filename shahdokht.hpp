#pragma once
#include <iostream>
#include "card.hpp"

class Shahdokht : public Cards
{
    public:
    int getNumOfCard() const override
    {
        return 3;
    }

     int getPoint() const override
    {
        return 10;
    }
};