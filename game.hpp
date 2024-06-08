#include <iostream>
#include "player.hpp"

class Game : public Player
{
    public:
        Game(){
            initPlayers();
        }

        void initPlayers(){
            std::cout << "Welcome to the game!" << std::endl;
            std::cout << "Please enter the number of players : ";

            std::cin >> playerNum;
            if(check_Player_Num(playerNum) == false){
                std::cout << "Invalid number of players. Please enter a number between 3 and 6 : ";
                std::cin >> playerNum;
            }

            Player players[playerNum];

            for(int i{} ; i < playerNum ; i++){
                std::cout << "please enter player" << i+1 << "' name : ";
                std::string name;
                std::cin >> name;
                players[i].set_Name(name);

                std::cout << "please enter player" << i+1 << "' age : ";
                int age;
                std::cin >> age;
                players[i].set_Age(age);

                std::cout << "please enter player" << i+1 << "' color : ";
                std::string color;
                std::cin >> color;
                players[i].set_Color(color);
                }
            
        }
    private:
        int playerNum;
};