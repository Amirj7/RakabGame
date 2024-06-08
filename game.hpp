#include <iostream>
#include "player.hpp"

class Game : public Player
{
    public:
        void run(){
            std::cout << "Welcome to the game!" << std::endl;
            std::cout << "Please enter the number of players : ";

            std::cin >> playerNum;
            if(check_Player_Num(playerNum) == false){
                std::cout << "Invalid number of players. Please enter a number between 3 and 6 : ";
                std::cin >> playerNum;
            }

            Player players[playerNum];

            while(playerNum){
                for(int i{} ; i < playerNum ; i++){
                    std::cout << "please enter player" << i << "' name : ";
                    
                }
            }
        }
    private:
        int playerNum;
};