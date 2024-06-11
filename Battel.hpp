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

    void startBattle(std::vector<Player> p)
    {
        
    }

private:
    std::string neshanJang;
};