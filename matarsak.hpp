#pragma once
#include <iostream>
#include "card.hpp"

class Matarsak : public Cards
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