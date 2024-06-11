#include <iostream>
#include <vector>
#include <conio.h>   // For getch()
#include <windows.h> // For system("CLS")
#include "Battle.hpp"
#include "Player.hpp"
#include "Deck.hpp"
#include "Yellow1.hpp"
#include "Yellow2.hpp"
#include "Yellow3.hpp"
#include "Yellow4.hpp"
#include "Yellow5.hpp"
#include "Yellow6.hpp"
#include "Yellow10.hpp"
#include "Shirdokht.hpp"
#include "Spring.hpp"
#include "Winter.hpp"
#include "Tablzan.hpp"
#include "Matarsag.hpp"

class Game
{
public:
    Game()
    {
        startGame();
    };

    void startGame()
    {
        NumberOfPlayers();
        setPlayers();
        setPlayersInformation();
        specifyTheRound(round);
        showPlayerCards(players);
    }

    void NumberOfPlayers()
    {
        std::cout << "Game is starting!" << std::endl
                  << "please enter the number of players: ";
        std::cin >> numOfPlayers;
        while (numOfPlayers < 3 || numOfPlayers > 6)
        {
            std::cout << "Invalid number of players. Please enter a number between 3 and 6 : ";
            std::cin >> numOfPlayers;
        }
    }

    void setPlayers()
    {
        for (int i{}; i < numOfPlayers; i++)
        {
            players.push_back(Player());
        }
    }

    void setPlayersInformation()
    {
        for (int i{}; i < numOfPlayers; i++)
        {
            std::cout << "Player" << i + 1 << " please enter your name: ";
            std::string name;
            std::cin >> name;
            players[i].setName(name);

            std::cout << "Player" << i + 1 << " please enter your age: ";
            int age;
            std::cin >> age;
            players[i].setAge(age);

            std::cout << "Player" << i + 1 << " please choose your color: ";
            std::string color;
            std::cin >> color;
            players[i].setColor(color);

            for (int j{}; j < 10 + players[i].numOfPlayerCities(); j++)
            {
                std::string temp = deck.getTheLastElementOfCardsInDeck();
                players[i].setCardsInHand(temp);
            }
        }
    }

    Player findTheSmallestPlayer(std::vector<Player> p)
    {
        Player temp = p[0];
        for (int i{}; i < (sizeof(p) / sizeof(p[0])); i++)
        {
            if (temp.getAge() < p[i].getAge())
            {
                temp = p[i];
            }
        }
        return temp;
    }

    void specifyTheRound(int R)
    {
        if (R = 1)
        {
            neshanJangRoundOne();
        }
        else
        {
            neshanJangRestOfTheRounds(players);
        }
    }

    void neshanJangRoundOne()
    {
        std::cout << findTheSmallestPlayer(players).getName() << " please choose province for battle: ";
        std::string province;
        std::cin >> province;
        battle.setNeshanJang(province);
        round++;
    }

    void neshanJangRestOfTheRounds(std::vector<Player> Pl)
    {
        for(int i{} ; i < sizeof(Pl) / sizeof(Pl[0]) ; i++)
        {
            if(Pl[i].getWinner())
            {
                std::cout << Pl[i].getName() << " please choose province for battle: ";
                std::string province;
                std::cin >> province;
                battle.setNeshanJang(province);
                bool x = false;
                Pl[i].setWinner(x);
            }
        }
    }

    void showPlayerCards(std::vector<Player> p)
    {
        for (int i{}; i < sizeof(p) / sizeof(p[0]); i++)
        {
            std::cout << "i want to show " << p[i].getName() << "'s cards!." << std::endl;
            std::cout << "please give the system to " << p[i].getName() << std::endl;

            bool showCards = false;
            int counter{2};
            while (counter != 0)
            {
                int key = _getch();
                if (key == 13)
                { // 13 is the ASCII code for Enter key
                    if (showCards)
                    {
                        // Clear the console
                        system("CLS");
                        showCards = false;
                        counter--;
                    }
                    else
                    {
                        // Display the message
                        p[i].getCardsInHand();
                        showCards = true;
                        counter--;
                    }
                }
            }
        }
    }

private:
    int numOfPlayers;
    std::vector<Player> players;
    Deck deck;
    Battle battle;
    int round{1};
};