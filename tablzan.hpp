#pragma once
#include <iostream>
#include "cart.hpp"

class Tablzan : public Card
{
    public:
       int getNumOfCard() const override
    {
        return 6;
    }

     int getPoint() const override
    {
        return 0;
    }
};