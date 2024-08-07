#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include "battle.hpp"
#include "player.hpp"
#include "deck.hpp"
#include <fstream>

class Game
{
public:
    Game()
    {
        // check if the player want to continue last game or not
        char choice;
        std::cout << "Do you want to load the previous game ? (y/n)";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            if (loadGame())
            {
                std::cout << "Let's continue our war!!" << std::endl;
                continueGame();
            }
            else
            {
                std::cout << "Failed to load the game. Starting a new war..." << std::endl;
                startGame();
            }
        }
        else
        {
            startGame();
        }
    }

    void startGame()
    {
        welcomeAndGetNumberOfPlayers();
        setPlayersInVector();
        continueGame();
    }
    // check if the player want to save the game and exit or ot
    void continueGame()
    {
        while (true)
        {
            playRound();
            if (battle.checkTheGameEndsOrNot(players, GameMap))
            {
                break;
            }
            char saveChoice;
            std::cout << "Do you want to save the game and exit? (y/n): ";
            std::cin >> saveChoice;
            if (saveChoice == 'y' || saveChoice == 'Y')
            {
                saveGame();
                exit(0); // Exit the program
            }
        }
    }

    // start the round
    void playRound()
    {
        specifyTheRound();
        showPlayersCard();
        battle.startBattle(players);
        battle.setPlayersNameForSpring(players); // before calculating the score, spring should be checked
        battle.calculatePlayersScore(players);
        std::cout << battle.checkWinnerOfTheRound(players, city) << std::endl;

        for (int i{}; i < players.size(); i++) // just for debug
        {
            std::cout << players[i].getName() << " : " << players[i].getTotalScore() << std::endl;
        }
        battle.setProvinceChoice(players);
        char ch = getch();
    }

    // just a beautiful start screen
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

    // this is for specify the players and get their informations
    void setPlayersInVector()
    {
        for (int i{}; i < numOfPlayers; i++)
        {
            std::string name;
            std::cout << "Player" << i + 1 << " please enter your name: ";
            std::cin >> name;

            int age;
            std::cout << "Player" << i + 1 << " please enter your age: ";
            std::cin >> age;
            while (age <= 0) // check that age is bigger than 0 or not
            {
                std::cout << "invalid age!please enter your age correctly: ";
                std::cin >> age;
            }

            std::string color;
            std::cout << "Player" << i + 1 << " please enter your color: ";
            std::cin >> color;

            std::vector<std::string> cardsInHand = deck.pakhsh();

            Player p(name, age, color, cardsInHand);
            players.push_back(p);
        }
    }

    // this function shows the player cards
    void showPlayersCard()
    {
        for (int i{}; i < players.size(); i++)
        {
            char ch = getch();
            std::vector<std::string> temp = players[i].getCardsInHand();
            std::cout << players[i].getName() << " 's cards: ";
            for (int j{}; j < temp.size(); j++)
            {
                std::cout << temp[j] << " ";
            }
            std::cout << std::endl;
            ch = getch();
            system("CLS");
        }
    }

    int getRound()
    {
        return round;
    }
    // this function checks if it is the first round of the game or not
    void specifyTheRound()
    {
        if (round == 1)
        {
            Player temp = players[0];
            for (int i{}; i < players.size(); i++)
            {
                if (temp.getAge() > players[i].getAge())
                {
                    temp = players[i];
                }
            }
            std::string province;
            while (true)
            {
                std::cout << temp.getName() << " please choose province for battle: ";
                std::cin >> province;
                city = province;
                if (GameMap.isValidCity(province))
                {
                    break;
                }
                else
                {
                    std::cout << "Invalid city name. Please enter a valid city name: ";
                }
            }
            temp.setNeshanJang(province);

            int goodLuck;
            std::cout << temp.getName() << " please choose a goodluck number: ";
            std::cin >> goodLuck;
            while (goodLuck < 10 || goodLuck >= 100)
            {
                std::cout << "your number should be between 10 and 99!" << std::endl
                          << "please choose another number: ";
                std::cin >> goodLuck;
            }
            battle.setGoodLuckNum(goodLuck);

            int badLuck;
            std::cout << temp.getName() << " please choose a badluck number: ";
            std::cin >> badLuck;
            while (badLuck < 10 || badLuck >= 100)
            {
                std::cout << "your number should be between 10 and 99!" << std::endl
                          << "please choose another number: ";
                std::cin >> badLuck;
            }
            battle.setBadLuckNum(badLuck);

            round++;
        }
        else
        {
            for (int i{}; i < players.size(); i++)
            {
                players[i].setPass(false);
            }

            for (int i{}; i < players.size(); i++)
            {
                if (players[i + 1].getShirzanCount() > players[i].getShirzanCount())
                {
                    Player *playerWithMaxShirzan = nullptr;
                    playerWithMaxShirzan = &players[i + 1];

                    std::string firstIfProvince;
                    while (true)
                    {
                        std::cout << playerWithMaxShirzan->getName() << " please choose province for battle: ";
                        std::cin >> firstIfProvince;
                        if (GameMap.isValidCity(firstIfProvince) && (firstIfProvince != battle.getProvinceChoice()))
                        {
                            break;
                        }
                        else
                        {
                            std::cout << "OOps! Invalid city name  or you can't choose this city cause of neshane solh. Please enter a valid city name or another city... " << std::endl;
                        }
                    }
                    playerWithMaxShirzan->setNeshanJang(firstIfProvince);
                    city = firstIfProvince;

                    int goodluck;
                    std::cout << playerWithMaxShirzan->getName() << " please choose a goodluck number: ";
                    std::cin >> goodluck;
                    while (goodluck < 10 || goodluck >= 100)
                    {
                        std::cout << "your number should be between 10 and 99!" << std::endl
                                  << "please choose another number: ";
                        std::cin >> goodluck;
                    }
                    battle.setGoodLuckNum(goodluck);

                    int badLuck;
                    std::cout << playerWithMaxShirzan->getName() << " please choose a badluck number: ";
                    std::cin >> badLuck;
                    while (badLuck < 10 || badLuck >= 100)
                    {
                        std::cout << "your number should be between 10 and 99!" << std::endl
                                  << "please choose another number: ";
                        std::cin >> badLuck;
                    }
                    battle.setBadLuckNum(badLuck);

                    round++;
                    break;
                }
                else if (players[i].getWinnerForNeshanJang())
                {
                    std::string SecondIfprovince;
                    while (true)
                    {
                        std::cout << players[i].getName() << " please choose province for battle: ";
                        std::cin >> SecondIfprovince;
                        if (GameMap.isValidCity(SecondIfprovince) && (SecondIfprovince != battle.getProvinceChoice()))
                        {
                            break;
                        }
                        else
                        {
                            std::cout << "OOps! Invalid city name  or you can't choose this city cause of neshane solh. Please enter a valid city name or another city... " << std::endl;
                        }
                    }
                    players[i].setNeshanJang(SecondIfprovince);
                    city = SecondIfprovince;

                    int goodluck;
                    std::cout << players[i].getName() << " please choose a goodluck number: ";
                    std::cin >> goodluck;
                    while (goodluck < 10 || goodluck >= 100)
                    {
                        std::cout << "your number should be between 10 and 99!" << std::endl
                                  << "please choose another number: ";
                        std::cin >> goodluck;
                    }
                    battle.setGoodLuckNum(goodluck);

                    int badLuck;
                    std::cout << players[i].getName() << " please choose a badluck number: ";
                    std::cin >> badLuck;
                    while (badLuck < 10 || badLuck >= 100)
                    {
                        std::cout << "your number should be between 10 and 99!" << std::endl
                                  << "please choose another number: ";
                        std::cin >> badLuck;
                    }
                    battle.setBadLuckNum(badLuck);

                    round++;
                    break;
                }
            }
        }
    }

    // function to save the game
    void saveGame()
    {
        std::ofstream file("game_save.txt");
        if (file.is_open())
        {
            file << round << '\n';
            file << numOfPlayers << '\n';
            file << city << '\n';
            for (const auto &player : players)
            {
                file << player.getName() << ' ' << player.getAge() << ' ' << player.getColor() << '\n';
                for (const auto &card : player.getCardsInHand())
                {
                    file << card << ' ';
                }
                file << "|\n";
                for (const auto &yellowCard : player.getYellowCardsOnTable())
                {
                    file << yellowCard << ' ';
                }
                file << "|\n";
                for (const auto &purpleCard : player.getPurpleCardsOnTable())
                {
                    file << purpleCard << ' ';
                }
                file << "|\n";
                for (const auto &city : player.getCapturedCities())
                {
                    file << city << ' ';
                }
                file << "|\n";
                file << player.getTotalScore() << '\n';
            }
            file.close();
        }
        else
        {
            std::cerr << "Unable to open file for saving!" << std::endl;
        }
    }

    // function to load the game
    bool loadGame()
    {
        std::ifstream file("game_save.txt");
        if (file.is_open())
        {
            file >> round;
            file >> numOfPlayers;
            file >> city;
            players.clear();
            for (int i = 0; i < numOfPlayers; i++)
            {
                std::string name, color;
                int age, score;
                file >> name >> age >> color;
                Player player(name, age, color);

                std::vector<std::string> cardsInHand;
                std::string card;
                while (file >> card && card != "|")
                {
                    cardsInHand.push_back(card);
                }
                player.setCardsInHand(cardsInHand);

                while (file >> card && card != "|")
                {
                    player.setYellowCardsOnTable(card);
                }

                while (file >> card && card != "|")
                {
                    player.setPurpleCardsOnTable(card);
                }

                while (file >> card && card != "|")
                {
                    player.setCapturedCities(card);
                }

                file >> score;
                player.setTotalScore(score);
                players.push_back(player);
            }
            file.close();
            return true;
        }
        else
        {
            std::cerr << "Unable to open file for loading!" << std::endl;
            return false;
        }
    }

private:
    std::string city;
    CityMap GameMap;
    int numOfPlayers;
    std::vector<Player> players;
    Deck deck;
    Battle battle;
    int round = 1;
};