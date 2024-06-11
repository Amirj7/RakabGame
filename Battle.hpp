#include <iostream>
#include "Player.hpp"
#include <iostream>

class Battle
{
public:
    void setNeshanJang(std::string nj)
    {
        neshanJang = nj;
    }

    std::string getNeshanJang()
    {
        return neshanJang;
    }


private:
    std::string neshanJang;
};