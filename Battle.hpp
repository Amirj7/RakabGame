#pragma once
#include <iostream>
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

    bool checkPass(std::vector<Player> p)
    {
        int counter = 0;
        for (int i{}; i < p.size(); i++)
        {
            if (p[i].getPass() == true)
            {
                counter++;
            }
        }
        if (counter == p.size())
        {
            return true;
        }
        else
        {
            return false;
        }
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
                    std::cout << p[i].getName() << " please play a card or pass" << std::endl;
                    std::cout << "your cards: ";
                    std::vector<std::string> temp = p[i].getCardsInHand();
                    for (int j{}; j < p[i].getCardsInHand().size(); j++)
                    {
                        std::cout << temp[j] << "  ";
                    }
                    std::cout << std::endl;
                    std::cin >> choice;
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
                            else if (choice == "matarsak")
                            {
                                std::string chosenCard;
                                std::vector<std::string> temp1 = p[i].getYellowCardsOnTable();
                                std::vector<std::string> temp2 = p[i].getPurpleCardsOnTable();
                                for (int i{}; i < p[i].getYellowCardsOnTable().size(); i++)
                                {
                                    std::cout << temp1[i] << "  ";
                                }
                                for (int i{}; i < p[i].getPurpleCardsOnTable().size(); i++)
                                {
                                    std::cout << temp2[i] << "  ";
                                }
                                std::cout << std::endl
                                          << p[i].getName() << "please choose a card to peak up: ";
                                std::cin >> chosenCard;
                                p[i].setCardsInHand(chosenCard);
                                if (isYellow(chosenCard))
                                {
                                    p[i].popBackCardsYellowCardsOnTable(chosenCard);
                                }
                                else
                                {
                                    p[i].popBackCardsPurpleCardsOnTable(chosenCard);
                                }
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
        // calculate purplecards score
        for (int i{}; i < p.size(); i++)
        {
            int tablzan = 1;
            std::vector<std::string> temp = p[i].getPurpleCardsOnTable();
            for (int j{}; j < p[i].getPurpleCardsOnTable().size(); j++)
            {
                if (temp[j] == "tablzan")
                {
                    tablzan = tablzan * 2;
                }
            }
            for (int j{}; j < p[i].getPurpleCardsOnTable().size(); j++)
            {
                if (temp[j] == "shahdokht")
                {
                    p[i].setTotalScore(10);
                }
            }

            // calculate yellowcards score
            if (season == 0)
            {
                p[i].setTotalScore(p[i].getYellowCardsOnTable().size() * tablzan);
            }
            else if (season == 1)
            {
                p[i].setTotalScore(p[i].getYellowScore() * tablzan);
                for(int j{} ; j < p.size() ; j++)
                {
                    if(p[i].getName() == playersNameForSpring[j])
                    {
                        p[i].setTotalScore(3);
                    }
                }
            }
            else if (season == 2)
            {
                p[i].setTotalScore(p[i].getYellowScore() * tablzan);
            }
        }
    }

    std::string checkWinnerOfTheRound(std::vector<Player> &p)
    {
        Player temp = p[0];
        for (int i{}; i < p.size(); i++)
        {
            if (p[i].getTotalScore() > temp.getTotalScore())
            {
                temp = p[i];
            }
        }
        temp.setWinnerForNeshanJang(true);
        temp.setCapturedCities(neshanJang);
        return temp.getName();
    }

    void setPlayersNameForSpring(std::vector<Player> &p)
    {
        Player temp = p[0];
        int index = 0;
        for (int i{}; i < p.size(); i++)
        {
            if(temp.getBiggestYellowCard() < p[i].getBiggestYellowCard())
            {
                temp = p[i];
                index = i;
            }
        }
        playersNameForSpring.push_back(temp.getName());
        for(int i{}; i < p.size(); i++)
        {
            if(index != i)
            {
                if(temp.getBiggestYellowCard() == p[i].getBiggestYellowCard())
                {
                    playersNameForSpring.push_back(p[i].getName());
                }
            }
        }
    }
private:
    std::vector<std::string> playersNameForSpring;
    int season = 2; // spring = 1 / winter = 0
    std::string neshanJang;
    int round = 1;
};