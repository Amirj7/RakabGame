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
    Game() // This is the class constructor that call the startGame function for start the game :o
    {
        startGame();
    };

    void startGame() // this function call other functions that we need in game :o fix it!!!!
    {
        NumberOfPlayers();
        setPlayers();
        setPlayersInformation();
        specifyTheRound(round);
        showPlayerCards(players);
        startBattel(players);
    }

    void NumberOfPlayers() // this function get the number of players
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

    void setPlayers() // this function set the players and make an object of the player class and put them in vector
    {
        for (int i{}; i < numOfPlayers; i++)
        {
            players.push_back(Player());
        }
    }

    void setPlayersInformation() // this fnction get the player informations such as name,age,...
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

    Player findTheSmallestPlayer(std::vector<Player> p) // this function find the smallest person between players for the first turn of the game
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

    void specifyTheRound(int R) // this function specify the round to let players change the neshanejang
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

    void neshanJangRoundOne() // in round one the smallest player should start the battel
    {
        std::cout << findTheSmallestPlayer(players).getName() << " please choose province for battle: ";
        std::string province;
        std::cin >> province;
        battle.setNeshanJang(province);
        round++;
    }

    void neshanJangRestOfTheRounds(std::vector<Player> Pl) // in other rounds something changes
    {
        for (int i{}; i < sizeof(Pl) / sizeof(Pl[0]); i++)
        {
            if (Pl[i].getNumOfShirdokhtCard()) //fix
            {

            }
            else if (Pl[i].getWinner())
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

    void showPlayerCards(std::vector<Player> p) // this fnction should show the player cards
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

    void startBattel(std::vector<Player> x) // this function should start the game
    {
        std::cout << "the battel is starting!" << std::endl;
        for (int i{}; i < sizeof(x) / sizeof(x[0]); i++)
        {
            while (true)
            {
                std::string choice;
                std::cout << players[i].getName() << ", do you want to pass or play a card (pass/play) ? : " << std::endl;
                std::cin >> choice;
                if (choice == "pass")
                {
                    std::cout << players[i].getName() << " has chosen to pass this turn" << std::endl;
                    break;
                }
                else if (choice == "play")
                {
                    std::cout << players[i].getName() << " Please choose a card : " << std::endl;
                    std::string cards;
                    std::cin >> cards;

                    if (players[i].isYellowcard(cards))
                    {
                        players[i].setYellowCardsOnTable(cards);
                    }
                    else
                    {
                        players[i].setPurpleCardsOnTable(cards);
                    }
                    break;
                }
                else
                {
                    std::cout << "invalid choose please try again! " << std::endl;
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