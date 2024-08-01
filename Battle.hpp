#pragma once
#include <iostream>
#include <map>
#include "map.hpp"
#include "player.hpp"

class Battle
{
public:
    void setNeshanJang(std::string nj)
    {
        neshanJang = nj;
    }
    std::string getNeshanJang() const
    {
        return neshanJang;
    }

    bool checkPass(const std::vector<Player> &p)
    {
        int counter = 0;
        for (const Player &player : p)
        {
            if (player.getPass())
            {
                counter++;
            }
        }
        return counter == p.size();
    }

    bool isYellow(std::string c)
    {
        int isthere = c.find("yellow");
        if (isthere == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void startBattle(std::vector<Player> &p)
    {
        while (checkPass(p) == false)
        {
            for (int i{}; i < p.size(); i++)
            {
                if (p[i].getPass() != true)
                {
                    std::string choice;
                    bool validChoice = false;

                    while (!validChoice)
                    {
                        std::cout << p[i].getName() << " please play a card or pass( HELP for more info)" << std::endl;
                        std::cout << "your cards: ";
                        std::vector<std::string> temp = p[i].getCardsInHand();
                        for (int j = 0; j < temp.size(); j++)
                        {
                            std::cout << temp[j] << "  ";
                        }
                        std::cout << std::endl;
                        std::cin >> choice;

                        if (std::find(temp.begin(), temp.end(), choice) != temp.end())
                        {
                            validChoice = true;
                        }
                        else if (choice == "pass" || choice == "HELP")
                        {
                            validChoice = true;
                        }
                        else
                        {
                            std::cout << "Invalid choice. Please choose a card from your hand or 'pass'." << std::endl;
                        }
                    }
                    if (choice == "HELP")
                    {
                        std::cout << "Hello my friend ! if you don't know how this game work don't worry I'm here!" << std::endl;
                        std::cout << "what's wrong ? pls choose your problem : cards / how to play " << std::endl;
                        string help;
                        cin >> help;
                        if (help == "how to play")
                        {
                            std::cout << "The youngest player takes\n"
                                         "the battle marker. He or she\n"
                                         "initiates the first battle and\n"
                                         "takes the first turn of the game.\n\n"
                                         "In Condottiere, players\n"
                                         "compete in numerous battles\n"
                                         "over the different regions\n"
                                         "of the board. In each battle,\n"
                                         "players fight over a contested\n"
                                         "region, taking turns playing cards to increase\n"
                                         "their strength and trigger special effects.\n\n"
                                         "At the end of each battle, the player who has\n"
                                         "the highest strength based on the cards he or\n"
                                         "she played wins the battle and gains control\n"
                                         "of the contested region. The game ends when\n"
                                         "a single player controls either three adjacent\n"
                                         "regions or a total of five regions anywhere\n"
                                         "on the board.\n\n"
                                         "Player turns are taken in clockwise order\n"
                                         "starting with the player who initiated the\n"
                                         "battle. When you take your turn, you can\n"
                                         "choose to either play a card or pass.\n"
                                         "If you do not wish to play a card, or if you\n"
                                         "are out of cards, you pass. For the rest of this\n"
                                         "battle, you cannot play any more cards, and\n"
                                         "your turn is skipped.\n\n"
                                         "Any cards you already played during the\n"
                                         "battle stay in your row, and their values and\n"
                                         "effects still apply; regardless of when you\n"
                                         "pass, you can still have the highest strength at\n"
                                         "the end of the battle.\n\n"
                                         "If all players except you have passed, you can\n"
                                         "take as many consecutive turns as you wish,\n"
                                         "playing cards until you also pass.\n\n"
                                         "Players compare the strength of their armies,\n"
                                         "and the player with the highest strength\n"
                                         "wins the battle. The winner gains control of\n"
                                         "the contested region, placing one of his or\n"
                                         "her control markers in it. The winner also\n"
                                         "takes the battle marker (and will initiate the\n"
                                         "next battle).\n\n"
                                         "If there is a tie for highest strength, no one\n"
                                         "wins the battle, and a control marker is not\n"
                                         "placed. Randomly decide among the tied\n"
                                         "players who takes the battle marker.\n\n"
                                         "Note that the Spy special card can change\n"
                                         "who takes the battle marker."
                                      << std::endl;
                        }
                        if (help == "cards")
                        {
                            std::cout << "Drummer: When a Drummer card is played, the hand of the player who played it is doubled. Note that only yellow cards are doubled, and purple cards remain unchanged.\n\n"
                                         "Winter: When this card is played, all the scores obtained by players through yellow cards are converted to 1. For example, if you play 3 cards with different scores, you will have three scores of 1. The effect of Winter does not disappear until someone plays Spring and it remains until the end of that round.\n\n"
                                         "Spring: When Spring is played, the effect of Winter disappears, and the largest yellow card played in the entire game gains an additional 3 points, even if that card is not yours.\n\n"
                                         "Scarecrow: When you play a Scarecrow, you can pick up one of your cards from the ground. After this action, the Scarecrow card is discarded.\n\n"
                                         "Princess: This card has 10 points and is not affected by Winter, Spring, or any other special cards."
                                      << std::endl;
                        }
                    }

                    if (choice == "pass")
                    {
                        p[i].setPass(true);
                    }
                    else
                    {
                        if (isYellow(choice) == true)
                        {
                            p[i].setYellowCardsOnTable(choice);
                            p[i].popBackCardsInhand(choice);
                            if (choice == "yellow1")
                            {
                                p[i].setYellowScore(1);
                                if (p[i].getBiggestYellowCard() < 1)
                                {
                                    p[i].setBiggestYellowCard(1);
                                }
                            }
                            else if (choice == "yellow2")
                            {
                                p[i].setYellowScore(2);
                                if (p[i].getBiggestYellowCard() < 2)
                                {
                                    p[i].setBiggestYellowCard(2);
                                }
                            }
                            else if (choice == "yellow3")
                            {
                                p[i].setYellowScore(3);
                                if (p[i].getBiggestYellowCard() < 3)
                                {
                                    p[i].setBiggestYellowCard(3);
                                }
                            }
                            else if (choice == "yellow4")
                            {
                                p[i].setYellowScore(4);
                                if (p[i].getBiggestYellowCard() < 4)
                                {
                                    p[i].setBiggestYellowCard(4);
                                }
                            }
                            else if (choice == "yellow5")
                            {
                                p[i].setYellowScore(5);
                                if (p[i].getBiggestYellowCard() < 5)
                                {
                                    p[i].setBiggestYellowCard(5);
                                }
                            }
                            else if (choice == "yellow6")
                            {
                                p[i].setYellowScore(6);
                                if (p[i].getBiggestYellowCard() < 6)
                                {
                                    p[i].setBiggestYellowCard(6);
                                }
                            }
                            else if (choice == "yellow10")
                            {
                                p[i].setYellowScore(10);
                                if (p[i].getBiggestYellowCard() < 10)
                                {
                                    p[i].setBiggestYellowCard(10);
                                }
                            }
                        }
                        else
                        {
                            if (choice == "winter")
                            {
                                season = 0;
                                p[i].popBackCardsInhand(choice);
                            }
                            else if (choice == "spring")
                            {
                                season = 1;
                                p[i].popBackCardsInhand(choice);
                            }
                            else if (choice == "shirzan")
                            {
                                p[i].popBackCardsInhand(choice);
                            }
                            else if (choice == "rishsefid")
                            {
                                p[i].popBackCardsInhand(choice);
                                p[i].setPlayerPlayedRishsefidOrNot(true);
                                //std::cout << p[i].getPlayerPlayedRishsefidOrNot() << " here" << std::endl;
                            }
                            else if (choice == "parchamdar")
                            {
                                p[i].popBackCardsInhand(choice);
                                p[i].setPass(true);
                                // calculatePlayersScore(p);
                                return;
                            }
                            else if (choice == "matarsak")
                            {
                                std::string chosenCard;
                                std::vector<std::string> temp1 = p[i].getYellowCardsOnTable();
                                std::vector<std::string> temp2 = p[i].getPurpleCardsOnTable();
                                for (int i{}; i < p[i].getYellowCardsOnTable().size(); i++)
                                {
                                    std::cout << temp1[i] << "  ";
                                }
                                std::cout << std::endl
                                          << p[i].getName() << "please choose a card to peak up: ";
                                std::cin >> chosenCard;
                                if (chosenCard == "yellow1")
                                {
                                    p[i].setTotalScore(-1);
                                }
                                else if (chosenCard == "yellow2")
                                {
                                    p[i].setTotalScore(-2);
                                }
                                else if (chosenCard == "yellow3")
                                {
                                    p[i].setTotalScore(-3);
                                }
                                else if (chosenCard == "yellow4")
                                {
                                    p[i].setTotalScore(-4);
                                }
                                else if (chosenCard == "yellow5")
                                {
                                    p[i].setTotalScore(-5);
                                }
                                else if (chosenCard == "yellow6")
                                {
                                    p[i].setTotalScore(-6);
                                }
                                else if (chosenCard == "yellow10")
                                {
                                    p[i].setTotalScore(-10);
                                }
                                p[i].setCardsInHand(chosenCard);
                                p[i].popBackCardsYellowCardsOnTable(chosenCard);
                            }
                            else
                            {
                                p[i].setPurpleCardsOnTable(choice);
                                p[i].popBackCardsInhand(choice);
                            }
                        }
                    }
                }
            }
        }
    }

    void calculatePlayersScore(std::vector<Player> &p)
    {
        int biggestYellowCard = -1; // Initialize to a small value
        Player *playerWithBiggestYellowCard = nullptr;

        // Calculate the base scores and find the biggest yellow card
        for (int i = 0; i < p.size(); i++)
        {
            int tablzan = 1;
            std::vector<std::string> temp = p[i].getPurpleCardsOnTable();
            for (const auto &card : temp)
            {
                if (card == "tablzan")
                {
                    tablzan *= 1.5;
                }
                else if (card == "shahdokht")
                {
                    p[i].setTotalScore(10);
                }
            }

            if (season == 0)
            {
                p[i].setTotalScore(p[i].getYellowCardsOnTable().size() * tablzan);
                if(p[i].getTotalScore() % goodLuckNum == 0)
                {
                    p[i].setTotalScore(p[i].getTotalScore());
                }
                if(p[i].getTotalScore() % badLuckNum == 0)
                {
                    p[i].setTotalScore(p[i].getTotalScore() * -1);
                }
            }
            else if (season == 1)
            {
                p[i].setTotalScore(p[i].getYellowScore() * tablzan);
                for (const auto &playerName : playersNameForSpring)
                {
                    if (p[i].getName() == playerName)
                    {
                        p[i].setTotalScore(p[i].getTotalScore() + 3);
                    }
                }
                if(p[i].getTotalScore() % goodLuckNum == 0)
                {
                    p[i].setTotalScore(p[i].getTotalScore());
                }
                if(p[i].getTotalScore() % badLuckNum == 0)
                {
                    p[i].setTotalScore(p[i].getTotalScore() * -1);
                }
            }
            else
            {
                p[i].setTotalScore(p[i].getYellowScore() * tablzan);
                if(p[i].getTotalScore() % goodLuckNum == 0)
                {
                    p[i].setTotalScore(p[i].getTotalScore());
                }
                if(p[i].getTotalScore() % badLuckNum == 0)
                {
                    p[i].setTotalScore(p[i].getTotalScore() * -1);
                }
            }

            // Find the player with the biggest yellow card
            if (p[i].getBiggestYellowCard() > biggestYellowCard)
            {
                biggestYellowCard = p[i].getBiggestYellowCard();
                playerWithBiggestYellowCard = &p[i];
                //std::cout << playerWithBiggestYellowCard->getName() << std::endl;
            }

            // Check and apply Rish Sefid effect if the player played it
        }

        //std::clog << "--- Test begin ---" << std::endl;
        for (int i = 0; i < p.size(); i++)
        {
               // std::clog << "Name: " << p[i].getName() << std::endl;
                //std::clog<< "Bishop: " <<  p[i].getPlayerPlayedRishsefidOrNot()<<std::endl;
                if (p[i].getPlayerPlayedRishsefidOrNot() == true)
                {
                    // std::clog<< "--- Entering to first if statement! ---";
                    if (playerWithBiggestYellowCard != nullptr)
                    {
                        //std::clog<< "--- Entering to second if statement! ---";
                        playerWithBiggestYellowCard->decreaseScore(biggestYellowCard);
                        //std::clog << "Rish Sefid effect applied." << std::endl;
                        p[i].setPlayerPlayedRishsefidOrNot(false);
                    }
                }
        }
    }

    std::string checkWinnerOfTheRound(std::vector<Player> &players, std::string &neshanJang)
    {
        if (players.empty())
            return "";

        Player *temp = &players[0];

        for (Player &player : players)
        {
            if (player.getTotalScore() > temp->getTotalScore())
            {
                temp = &player;
            }
        }

        temp->setWinnerForNeshanJang(true);
        temp->setCapturedCities(neshanJang);

        return temp->getName();
    }

    void setPlayersNameForSpring(std::vector<Player> &p)
    {
        Player temp = p[0];
        int index = 0;
        for (int i{}; i < p.size(); i++)
        {
            if (temp.getBiggestYellowCard() < p[i].getBiggestYellowCard())
            {
                temp = p[i];
                index = i;
            }
        }
        playersNameForSpring.push_back(temp.getName());
        for (int i{}; i < p.size(); i++)
        {
            if (index != i)
            {
                if (temp.getBiggestYellowCard() == p[i].getBiggestYellowCard())
                {
                    playersNameForSpring.push_back(p[i].getName());
                }
            }
        }
    }

    bool checkTheGameEndsOrNot(vector<Player> &players, CityMap &map)
    {
        for (int i = 0; i < players.size(); ++i)
        {
            if (players[i].getWinnerForNeshanJang())
            {
                if (players[i].getCapturedCities().size() >= 5)
                {
                    cout << "Player " << players[i].getName() << " has captured 5 cities and wins the game!" << endl;
                    return true;
                }

                if (players[i].getCapturedCities().size() == 3)
                {
                    vector<string> temp = players[i].getCapturedCities();
                    vector<string> nearbyCities = map.getNearbyCities(temp[0]);

                    auto itIs1 = std::find(nearbyCities.begin(), nearbyCities.end(), temp[1]);
                    auto itIs2 = std::find(nearbyCities.begin(), nearbyCities.end(), temp[2]);
                    if (itIs1 != nearbyCities.end() && itIs2 != nearbyCities.end())
                    {
                        nearbyCities = map.getNearbyCities(temp[1]);
                        auto itIs = std::find(nearbyCities.begin(), nearbyCities.end(), temp[2]);
                        if (itIs != nearbyCities.end())
                        {
                            return true;
                        }
                    }
                    return false;
                }

                if (players[i].getCapturedCities().size() == 4)
                {
                    vector<string> temp = players[i].getCapturedCities();
                    vector<string> nearbyCities = map.getNearbyCities(temp[0]);

                    auto itIs1 = std::find(nearbyCities.begin(), nearbyCities.end(), temp[1]);
                    auto itIs2 = std::find(nearbyCities.begin(), nearbyCities.end(), temp[2]);
                    if (itIs1 != nearbyCities.end() && itIs2 != nearbyCities.end())
                    {
                        nearbyCities = map.getNearbyCities(temp[1]);
                        auto itIs = std::find(nearbyCities.begin(), nearbyCities.end(), temp[2]);
                        if (itIs != nearbyCities.end())
                        {
                            return true;
                        }
                    }

                    nearbyCities = map.getNearbyCities(temp[0]);
                    itIs1 = std::find(nearbyCities.begin(), nearbyCities.end(), temp[1]);
                    itIs2 = std::find(nearbyCities.begin(), nearbyCities.end(), temp[3]);
                    if (itIs1 != nearbyCities.end() && itIs2 != nearbyCities.end())
                    {
                        nearbyCities = map.getNearbyCities(temp[1]);
                        auto itIs = std::find(nearbyCities.begin(), nearbyCities.end(), temp[3]);
                        if (itIs != nearbyCities.end())
                        {
                            return true;
                        }
                    }

                    nearbyCities = map.getNearbyCities(temp[0]);
                    itIs1 = std::find(nearbyCities.begin(), nearbyCities.end(), temp[2]);
                    itIs2 = std::find(nearbyCities.begin(), nearbyCities.end(), temp[3]);
                    if (itIs1 != nearbyCities.end() && itIs2 != nearbyCities.end())
                    {
                        nearbyCities = map.getNearbyCities(temp[2]);
                        auto itIs = std::find(nearbyCities.begin(), nearbyCities.end(), temp[3]);
                        if (itIs != nearbyCities.end())
                        {
                            return true;
                        }
                    }

                    nearbyCities = map.getNearbyCities(temp[1]);
                    itIs1 = std::find(nearbyCities.begin(), nearbyCities.end(), temp[2]);
                    itIs2 = std::find(nearbyCities.begin(), nearbyCities.end(), temp[3]);
                    if (itIs1 != nearbyCities.end() && itIs2 != nearbyCities.end())
                    {
                        nearbyCities = map.getNearbyCities(temp[2]);
                        auto itIs = std::find(nearbyCities.begin(), nearbyCities.end(), temp[3]);
                        if (itIs != nearbyCities.end())
                        {
                            return true;
                        }
                    }

                    return false;
                }
            }
        }
        cout << "No player has met the winning conditions yet." << endl;
        return false;
    }


    void setGoodLuckNum(int n)
    {
        goodLuckNum = n;
    }

    void setBadLuckNum(int n)
    {
        badLuckNum = n;
    }
private:
    std::vector<std::string> playersNameForSpring;
    int season = 2;
    std::string neshanJang;
    int round = 1;
    int goodLuckNum;
    int badLuckNum;
};
