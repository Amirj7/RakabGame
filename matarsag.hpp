#pragma once
#include <iostream>
#include "cart.hpp"

class Matarsag : public Card
{
    public:
       int getNumOfCard() const override
    {
        return 16;
    }
    int getPoint() const override
    {
        return 0;
    }
   
};