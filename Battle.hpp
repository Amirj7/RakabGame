#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Player.hpp"
#include "Yellow1.hpp"
#include "Yellow2.hpp"
#include "Yellow3.hpp"
#include "Yellow4.hpp"
#include "Yellow5.hpp"
#include "Yellow6.hpp"
#include "Yellow10.hpp"
#include "Deck.hpp"

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

    int numOfPlayersThatPass(const std::vector<Player>& players) const
    {
        int counter = 0;
        for (const auto& player : players)
        {
            if (player.getPass())
            {
                counter++;
            }
        }
        return counter;
    }

    void calculateYellowCardsScore(Player& player)
    {
        player.resetYellowCardsScore();
        for (int i = 0; i < player.getSizeOfYellowCardsOnTable(); i++)
        {
            std::string temp = player.getYellowCardsOnTable(i);
            if (temp == "yellow1")
            {
                Yellow1 y;
                player.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow2")
            {
                Yellow2 y;
                player.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow3")
            {
                Yellow3 y;
                player.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow4")
            {
                Yellow4 y;
                player.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow5")
            {
                Yellow5 y;
                player.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow6")
            {
                Yellow6 y;
                player.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow10")
            {
                Yellow10 y;
                player.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
        }
    }

    void calculateWinterAndSpringCards(std::vector<Player>& players)
    {
        if (season) // true=spring
        {
            for (auto& player : players)
            {
                int maxCardValue = -1;
                for (int i = 0; i < player.getSizeOfYellowCardsOnTable(); i++)
                {
                    int cardValue = player.getCardValueInHand(i);
                    if (cardValue > maxCardValue)
                    {
                        maxCardValue = cardValue + 3;
                    }
                }
                player.springScore(maxCardValue);
            }
        }
        else
        {
            for (auto& player : players)
            {
                player.winterOnYellowCardsScore();
            }
        }
    }

    void calculatePurpleCardsScore(Player& player)
    {
        player.resetPurpleCardsScore();
        for (int i = 0; i < player.getSizeOfPurpleCardsOnTable(); i++)
        {
            std::string temp = player.getPurpleCardsOnTable(i);
            if (temp == "tablzan")
            {
                player.setPurpleCardsScoreInPurpleCardsScore(player.getYellowCardsScore() * 2);
            }
            else if (temp == "shirdokht")
            {
                player.setPurpleCardsScoreInPurpleCardsScore(10);
            }
        }
    }

    void showPlayerScore(Player& player)
    {
        player.setTotalScore();
        std::cout << player.getName() << "'s current score: " << std::endl;
        std::cout << "Yellow Cards Score: " << player.getYellowCardsScore() << std::endl;
        std::cout << "Purple Cards Score: " << player.getPurpleCardsScore() << std::endl;
        std::cout << "Total Score: " << player.getTotalScore() << std::endl;
    }

    void startBattle(std::vector<Player>& players, Deck& deck)
    {
        while (numOfPlayersThatPass(players) != players.size())
        {
            for (auto& player : players)
            {
                if (!player.getPass())
                {
                    std::string choice;
                    std::cout << "-------------------------------------------------" << std::endl;
                    std::cout << player.getName() << "'s turn:" << std::endl;

                    player.setCardsInHand(deck.getTheLastElementOfCardsInDeck());
                    player.showPlayerCards();

                    std::cout << "Choose a card to play or pass ('pass' to skip): ";
                    std::cin >> choice;

                    if (choice == "pass")
                    {
                        std::cout << "Player passed this time." << std::endl;
                        player.setPass(true);
                    }
                    else
                    {
                        if (player.checkThatPlayerHaveTheCardOrNot(choice))
                        {
                            player.playCard(choice);
                            if (choice == "spring")
                            {
                                season = true;
                            }
                            else if (choice == "winter")
                            {
                                season = false;
                            }
                            else if (choice == "matarsag")
                            {
                                std::string cardThatPlayerWantToPickUp;
                                std::cout << "Please enter the card you want to pick up: ";
                                std::cin >> cardThatPlayerWantToPickUp;
                                player.setCardsInHand(cardThatPlayerWantToPickUp);
                                player.popBackCardsOnTable(cardThatPlayerWantToPickUp);
                            }
                            calculateYellowCardsScore(player);
                            calculatePurpleCardsScore(player);
                            showPlayerScore(player);
                        }
                        else
                        {
                            std::cout << "You don't have this card!!" << std::endl
                                      << "Please choose a card that exists in your hand: ";
                            std::cin >> choice;
                            player.playCard(choice);
                            calculateYellowCardsScore(player);
                            calculatePurpleCardsScore(player);
                            showPlayerScore(player);
                        }
                    }
                }
            }
        }
        std::cout << "Battle ended.\n";
    }

private:
    Deck deck;
    std::string neshanJang;
    bool season; // spring=true -- winter=false
};
