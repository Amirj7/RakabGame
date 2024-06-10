#include <iostream>
#include <algorithm>
#include "player.hpp"
#include "deck.hpp"

class Game : public Player, protected Deck
{
public:
    Game()
    {
        initPlayers();
        Player_Info();
    }

    int getNumOfPlayers()
    {
        return playerNum;
    }

    void initPlayers()
    {
        std::cout << "Welcome to the game!" << std::endl;
        std::cout << "Please enter the number of players : ";

        std::cin >> playerNum;
        if (check_Player_Num(playerNum) == false)
        {
            std::cout << "Invalid number of players. Please enter a number between 3 and 6 : ";
            std::cin >> playerNum;
        }
    }

    bool compareByAge(Player &a, Player &b)
    {
        return a.get_Age() < b.get_Age();
    }
    void sortPlayer(std::vector<Player> &sortPlayerAge)
    {
        std::sort(sortPlayerAge.begin(), sortPlayerAge.end(), compareByAge);
    }

    void Player_Info()
    {
        std::vector<Player> players(playerNum);

        Deck mainDeck;
        mainDeck.shuffleCards();
        auto gameDeck = mainDeck.getCards();

        for (int i{}; i < playerNum; i++)
        {
            std::cout << "please enter player" << i + 1 << "' name : ";
            std::string name;
            std::cin >> name;
            players[i].set_Name(name);

            std::cout << "please enter player" << i + 1 << "' age : ";
            int age;
            std::cin >> age;
            players[i].set_Age(age);
            Players_Age.push_back(age);

            std::cout << "please enter player" << i + 1 << "' color : ";
            std::string color;
            std::cin >> color;
            players[i].set_Color(color);

            for (int j = 0; j < 10 + players[i].numOfCapturedCities(); j++)
            {
                if (!gameDeck.empty())
                { // Check if there are cards left in the deck
                    std::string card = gameDeck.back();
                    gameDeck.pop_back();
                    players[i].set_Cards_In_Hand(card);
                }
                else
                {
                    std::cout << "gameDeck is empty!!";
                    break;
                }
            }
        }
        sortPlayer(players);
    }

private:
    int playerNum;
    std::vector<int> Players_Age;
};