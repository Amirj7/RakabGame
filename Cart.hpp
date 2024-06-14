#pragma once
#include <iostream>

class Card
{
public:
    virtual int getPoint() const = 0;
    virtual int getNumOfCard() const = 0;
    virtual ~Card() = default; 
};
