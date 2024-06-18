#pragma once
#include <iostream>
#include "card.hpp"

class Tablzan : public Cards
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