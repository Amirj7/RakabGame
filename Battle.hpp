#include <iostream>
#include "Player.hpp"
#include <string>
#include "Yellow1.hpp"
#include "Yellow2.hpp"
#include "Yellow3.hpp"
#include "Yellow4.hpp"
#include "Yellow5.hpp"
#include "Yellow6.hpp"
#include "Yellow10.hpp"
#include "deck.hpp"

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

    int numOfPlayersThatPass(std::vector<Player> p)
    {
        int counter;
        for (int i{}; i < sizeof(p) / sizeof(p[0]); i++)
        {
            if (p[i].getPass() == true)
            {
                counter++;
            }
        }
        return counter;
    }

    void calculateYellowCardsScore(Player p)
    {
        for (int i{}; i < p.getSizeOfYellowCardsOnTable(); i++)
        {
            std::string temp = p.getYellowCardsOnTable(i);
            if (temp == "yellow1")
            {
                Yellow1 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow2")
            {
                Yellow2 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow3")
            {
                Yellow3 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow4")
            {
                Yellow4 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow5")
            {
                Yellow5 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow6")
            {
                Yellow6 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if (temp == "yellow10")
            {
                Yellow10 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
        }
    }

    void calculateWinterAndSpringCards(std::vector<Player> p)
    {
        if (season) // true=spring
        {
            for (auto& player : p)
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
            for (int i{}; i < sizeof(p) / sizeof(p[0]); i++)
            {
                p[i].winterOnYellowCardsScore();
            }
        }
    }

    void calculatePurpleCardsScore(Player p)
    {
        for (int i{}; i < p.getSizeOfPurpleCardsOnTable(); i++)
        {
            std::string temp = p.getPurpleCardsOnTable(i);
            if (temp == "tablzan")
            {
                p.setPurpleCardsScoreInPuepleCardsScore(p.getYellowCardsScore()*2);    
            }
            else if (temp == "shirdokht")
            {
                p.setPurpleCardsScoreInPuepleCardsScore(10);
            }
        }
    }

   void startBattle(std::vector<Player>& players, Deck& D)
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

                player.setCardsInHand(D.getTheLastElementOfCardsInDeck());

                
                player.showPlayerCards();

                std::cout << "Choose a card to play or pass ('pass' to skip): ";
                std::cin >> choice;

                if (choice == "pass")
                {
                    std::cout << "player passed this time" << std::endl ;
                    player.setPass(true);
                }
                else
                {
                    if (player.checkThatPlayerHaveTheCardOrNot(choice))
                    {
                        if (player.isYellowCard(choice))
                        {
                            player.setYellowCardsOnTable(choice);
                        }
                        else
                        {
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
                            else
                            {
                                player.setPurpleCardsOnTable(choice);
                            }
                        }
                    }
                    else
                    {
                        std::cout << "You don't have this card!!" << std::endl
                                  << "Please choose a card that exists in your hand: ";
                        std::cin >> choice;
                        if (player.isYellowCard(choice))
                        {
                            player.setYellowCardsOnTable(choice);
                        }
                        else
                        {
                            player.setPurpleCardsOnTable(choice);
                        }
                    }
                }
            }
        }
    }
    std::cout << "Battle ended.\n";
}


    // void startBattle(std::vector<Player> p)
    // {
    //     while (numOfPlayersThatPass(p) != (sizeof(p) / sizeof(p[0])))
    //     {
    //         for (int i{}; i < sizeof(p) / sizeof(p[0]); i++)
    //         {
    //             if (p[i].getPass() == false) // fix it
    //             {
    //                 std::string choice;
    //                 std::cout << p[i].getName() << " please choose a card to play or pass: ";
    //                 p[i].getCardsInHand();
    //                 std::cin >> choice;

    //                 if (choice == "pass")
    //                 {
    //                     p[i].setPass(true);
    //                 }
    //                 else
    //                 {
    //                     if (p[i].checkThatPlayerHaveTheCardOrNot(choice))
    //                     {
    //                         if (p[i].isYellowCard(choice))
    //                         {
    //                             p[i].setYellowCardsOnTable(choice);
    //                         }
    //                         else
    //                         {
    //                             if (choice == "spring")
    //                             {
    //                                 season = true;
    //                             }
    //                             else if (choice == "winter")
    //                             {
    //                                 season = false;
    //                             }
    //                             else if (choice == "matarsag")
    //                             {
    //                                 std::string cardThatPlayerWantToPeakUp;
    //                                 std::cout << "please enter the card you want to peak up: "; // show hards on table
    //                                 std::cin >> cardThatPlayerWantToPeakUp;
    //                                 p[i].setCardsInHand(cardThatPlayerWantToPeakUp);
    //                                 p[i].popBackCardsOnTable(cardThatPlayerWantToPeakUp);
    //                             }
    //                             else
    //                             {
    //                                 p[i].setPurpleCardsOnTable(choice);
    //                             }
    //                         }
    //                     }
    //                     else
    //                     {
    //                         std::cout << "you don't have this  card!!" << std::endl
    //                                   << "please choose a card that exist in your hand: ";
    //                         std::cin >> choice;
    //                         if (p[i].isYellowCard(choice))
    //                         {
    //                             p[i].setYellowCardsOnTable(choice);
    //                         }
    //                         else
    //                         {
    //                             p[i].setPurpleCardsOnTable(choice);
    //                         }
    //                     }
    //                 }
    //             }

    //             if (i == ((sizeof(p) / sizeof(p[0])) - 1))
    //             {
    //                 i = 0;
    //             }
    //         }
    //     }
    //     std::cout << "this";
    // }

private:
    Deck D;
    std::string neshanJang;
    bool season; // spring=true -- winter=false
};