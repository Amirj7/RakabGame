#pragma once
#include <iostream>
#include "cart.hpp"

class Yellow1 : public Card
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

    bool isYellowcard1(const std::string &card) // just for test
    {
        return card.find("yellow1") != std::string::npos;
    }
};