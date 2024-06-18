#pragma once
#include <iostream>
#include "card.hpp" 

class Spring : public Cards
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