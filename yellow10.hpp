#pragma once
#include <iostream>
#include "card.hpp"

class Yellow10 : public Cards
{
    public:
        int getPoint() const override
    {
        return 10;
    }
    int getNumOfCard() const override
    {
        return 8;
    }
   
};