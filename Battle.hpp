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
        for(int i{} ; i < p.getSizeOfYellowCardsOnTable() ; i++)
        {
            std::string temp = p.getYellowCardsOnTable(i);
            if(temp == "yellow1")
            {
                Yellow1 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if(temp == "yellow2")
            {
                Yellow2 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint()); 
            }
            else if(temp == "yellow3")
            {
                Yellow3 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if(temp == "yellow4")
            {
                Yellow4 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if(temp == "yellow5")
            {
                Yellow5 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if(temp == "yellow6")
            {
                Yellow6 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
            else if(temp == "yellow10")
            {
                Yellow10 y;
                p.setYellowCardsScoreInYellowCardsScore(y.getPoint());
            }
        }
    }

    void calculateWinterAndSpringCards(std::vector<Player> p)
    {
        if(season)//true=spring
        {
            //be bozorg tarin carde bazi 3 ta ezaf kone
        }
        else
        {
            for(int i{} ; i < sizeof(p) / sizeof(p[0]) ; i++)
            {
                p[i].winterOnYellowCardsScore();
            }
        }
    }

    void calculatePurpleCardsScore(Player p)
    {
        for(int i{} ; i < p.getSizeOfPurpleCardsOnTable() ; i++)
        {
            std::string temp = p.getPurpleCardsOnTable(i);
            if(temp == "tablzan")
            {
                //**
            }
            else if(temp == "shirdokht")
            {
                p.setPurpleCardsScoreInPuepleCardsScore(10);
            }
        }
    }

    void startBattle(std::vector<Player> p)
    {
        while (numOfPlayersThatPass(p) != (sizeof(p) / sizeof(p[0])))
        {
            for (int i{} ; i < sizeof(p) / sizeof(p[0]) ; i++)
            {
                if (p[i].getPass() == false)
                {
                    std::string choice;
                    std::cout << p[i].getName() << " please choose a card to play or pass: ";
                    p[i].getCardsInHand();
                    std::cin >> choice;

                    if (choice == "pass")
                    {
                        p[i].setPass(true);
                    }
                    else
                    {
                        if (p[i].checkThatPlayerHaveTheCardOrNot(choice))
                        {
                            if (p[i].isYellowCard(choice))
                            {
                                p[i].setYellowCardsOnTable(choice);
                            }
                            else
                            {
                                if(choice == "spring")
                                {
                                    season = true;
                                }
                                else if(choice == "winter")
                                {
                                    season = false;
                                }
                                else if(choice == "matarsag")
                                {
                                    std::string cardThatPlayerWantToPeakUp;
                                    std::cout << "please enter the card you want to peak up: ";
                                    std::cin >> cardThatPlayerWantToPeakUp;
                                    p[i].setCardsInHand(cardThatPlayerWantToPeakUp);
                                    p[i].popBackCardsOnTable(cardThatPlayerWantToPeakUp);
                                }
                                else
                                {
                                    p[i].setPurpleCardsOnTable(choice);
                                }
                            }
                        }
                        else
                        {
                            std::cout << "you don't have this  card!!" << std::endl
                                      << "please choose a card that exist in your hand: ";
                            std::cin >> choice;
                            if (p[i].isYellowCard(choice))
                            {
                                p[i].setYellowCardsOnTable(choice);
                            }
                            else
                            {
                                p[i].setPurpleCardsOnTable(choice);
                            }
                        }
                    }
                }

                if(i == ((sizeof(p) / sizeof(p[0])) - 1))
                {
                    i = 0;
                }
            }
        }
    }

private:
    std::string neshanJang;
    bool season;//spring=true -- winter=false
};