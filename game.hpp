#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include "battle.hpp"
#include "player.hpp"
#include "deck.hpp"

class Game
{
    public:
        Game()
        {
            startGame();
        }

        void startGame(){
            welcomeAndGetNumberOfPlayers();
            setPlayersInVector();
            specifyTheRound();
            showPlayersCard();
            battle.startBattle(players);
            battle.calculatePlayersScore(players);
            std::cout << battle.checkWinner(players) << std::endl;
            
            for(int i{} ; i < players.size() ; i++)
            {
                std::cout << players[i].getName() << " : " << players[i].getYellowScore() << std::endl;
            }
            char ch = getch();
        }

        void display()
        {
            for(int i{} ; i < players.size() ; i++){
                std::cout << players[i].getName() << " : ";
                std::vector<std::string> temp1 = players[i].getYellowCardsOnTable();
                std::vector<std::string> temp2 = players[i].getPurpleCardsOnTable();
                for(int j{} ; j < players[i].getYellowCardsOnTable().size() ; j++)
                {
                    std::cout << temp1[j] << "  ";
                }
                for(int k{} ; k < players[i].getPurpleCardsOnTable().size() ; k++)
                {
                    std::cout << temp2[k] << "  ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl << "-----------------------------------------------------------------------------------------" << std::endl;
            for(int i{} ; i < players.size() ; i++)
            {
                std::cout << players[i].getName() << " : ";
                std::vector<std::string> temp = players[i].getCapturedCities();
                for(int j{} ; j < players[i].getCapturedCities().size() ; j++)
                {
                    std::cout << temp[j] << "  ";
                }
                std::cout << std::endl;
                std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
            }
        }

        void welcomeAndGetNumberOfPlayers()
        {
            std::cout << "***********************************************" << std::endl;
            std::cout << "*                                             *" << std::endl;
            std::cout << "*               Welcome to RAKAB              *" << std::endl;
            std::cout << "*                                             *" << std::endl;
            std::cout << "*  An adventure awaits in the world of cards! *" << std::endl;
            std::cout << "* Test your strategy and wit in this exciting *" << std::endl;
            std::cout << "*       game of skill and cunning. Enjoy!     *" << std::endl;
            std::cout << "*                                             *" << std::endl;
            std::cout << "***********************************************" << std::endl;
            std::cout << "please enter the number of players: ";
            std::cin >> numOfPlayers;
            while (numOfPlayers < 3 || numOfPlayers > 6)
            {
                std::cout << "Invalid number of players. Please enter a number between 3 and 6 : ";
                std::cin >> numOfPlayers;
            }
        }
        
        void setPlayersInVector()
        {
            for (int i{}; i < numOfPlayers; i++)
            {
                std::string name;
                std::cout << "Player" << i+1 << " please entre your name: ";
                std::cin >> name;

                int age;
                std::cout << "Player" << i+1 << " please enter your age: ";
                std::cin >> age;

                std::string color;
                std::cout << "Player" << i+1 << " please enter your color: ";
                std::cin >> color;

                std::vector<std::string> cardsInHand = deck.pakhsh();

                Player p(name , age , color , cardsInHand);
                players.push_back(p); 
            }
        }
    
        void showPlayersCard(){
            for(int i{} ; i < players.size() ; i++){
                char ch = getch();
                std::vector<std::string> temp = players[i].getCardsInHand();
                std::cout << players[i].getName() << " 's cards: ";
                for(int j{} ; j < temp.size() ; j++){
                    std::cout << temp[j] << " ";
                }
                std::cout << std::endl;
                ch = getch();
                system("CLS");
            }
        }
        
        void specifyTheRound()
        {
            if (round = 1)
            {
                Player temp = players[0];
                for(int i{} ; i < players.size() ; i++){
                    if(temp.getAge() > players[i].getAge()){
                        temp = players[i];
                    }
                }
                std::cout << temp.getName() << " please choose province for battle: ";
                std::string province;
                std::cin >> province;
                battle.setNeshanJang(province);
                round++;
            }
            else
            {
                for (int i{}; i < players.size(); i++)
                {
                    if (players[i].getWinnerForNeshanJang())
                    {
                        std::cout << players[i].getName() << " please choose province for battle: ";
                        std::string province;
                        std::cin >> province;
                        battle.setNeshanJang(province);
                        bool x = false;
                        players[i].setWinnerForNeshanJang(x);
                    }
                }
            }
        }
    private:
        int numOfPlayers;
        std::vector<Player> players;
        Deck deck;
        Battle battle;
        int round = 1;
};