#pragma once
#include <iostream>
#include "cart.hpp" 

class Spring : public Card
{
    public:
       int getNumOfCard() const override
    {
        return 3;
    }

     int getPoint() const override
    {
        return 0;
    }
};