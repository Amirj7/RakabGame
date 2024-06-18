#pragma once
#include <iostream>
#include "card.hpp"

class Yellow1 : public Cards
{
public:
    int getPoint() const override
    {
        return 1;
    }
    int getNumOfCard() const override
    {
        return 10;
    }
};