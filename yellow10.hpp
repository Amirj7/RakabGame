#pragma once
#include <iostream>
#include "cart.hpp"

class Yellow10 : public Card
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