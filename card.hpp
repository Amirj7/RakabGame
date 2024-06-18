#pragma once
#include <iostream>

class Cards
{
    public:
        virtual int getPoint() const = 0;
        virtual int getNumOfCard() const = 0;
        virtual ~Cards() = default; 
    private:
        int point;
        int numOfCard;
};