#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Player
{
public:
    Player(std::string n, int a, std::string c, std::vector<std::string> h)
    {
        setName(n);
        setAge(a);
        setColor(c);
        setCardsInHand(h);
        yellowCardsScore = 0 ;
        totalScore = 0;
    }

    void setName(std::string n)
    {
        name = n;
    }
    std::string getName()
    {
        return name;
    }

    void setAge(int a)
    {
        age = a;
    }
    int getAge()
    {
        return age;
    }

    void setColor(std::string c)
    {
        color = c;
    }
    std::string getColor()
    {
        return color;
    }

    void setCardsInHand(std::vector<std::string> c)
    {
        cardsInHand = c;
    }
    std::vector<std::string> getCardsInHand()
    {
        return cardsInHand;
    }
    void setCardsInHand(std::string c)
    {
        cardsInHand.push_back(c);
    }

    void setWinnerForNeshanJang(bool w)
    {
        winner = w;
    }
    bool getWinnerForNeshanJang()
    {
        return winner;
    }

    void setPass(bool p)
    {
        pass = p;
    }
    bool getPass()
    {
        return pass;
    }

    void setYellowCardsOnTable(std::string y)
    {
        yellowCardsOnTable.push_back(y);
    }
    std::vector<std::string> getYellowCardsOnTable()
    {
        return yellowCardsOnTable;
    }

    void setPurpleCardsOnTable(std::string p)
    {
        purpleCardsOnTable.push_back(p);
    }
    std::vector<std::string> getPurpleCardsOnTable()
    {
        return purpleCardsOnTable;
    }

    void popBackCardsInhand(std::string s)
    {
        auto it = std::find(cardsInHand.begin(), cardsInHand.end(), s);
        if (it != cardsInHand.end())
        {
            cardsInHand.erase(it);
        }
    }
    void popBackCardsYellowCardsOnTable(std::string s)
    {
        auto it = std::find(yellowCardsOnTable.begin(), yellowCardsOnTable.end(), s);
        if (it != yellowCardsOnTable.end())
        {
            yellowCardsOnTable.erase(it);
        }
    }
    void popBackCardsPurpleCardsOnTable(std::string s)
    {
        auto it = std::find(purpleCardsOnTable.begin(), purpleCardsOnTable.end(), s);
        if (it != purpleCardsOnTable.end())
        {
            purpleCardsOnTable.erase(it);
        }
    }

    void setTotalScore(int tScore)
    {
        totalScore += tScore;
    }
    int getTotalScore()
    {
        return totalScore;
    }
    void setYellowScore(int a)
    {
        // if (choice == "yellow1")
        // {
        //     yellowCardsScore.push_back(1);
        // }
        // else if (choice == "yellow2")
        // {
        //     yellowCardsScore.push_back(2);
        // }
        // else if (choice == "yellow3")
        // {
        //     yellowCardsScore.push_back(3);
        // }
        // else if (choice == "yellow4")
        // {
        //     yellowCardsScore.push_back(4);
        // }
        // else if (choice == "yellow5")
        // {
        //     yellowCardsScore.push_back(5);
        // }
        // else if (choice == "yellow6")
        // {
        //     yellowCardsScore.push_back(6);
        // }
        // else if (choice == "yellow10")
        // {
        //     yellowCardsScore.push_back(10);
        // }
        yellowCardsScore = yellowCardsScore + a;
        // std::sort(yellowCardsScore.begin() , yellowCardsScore.end());
    }
    int getYellowScore()
    {
        return yellowCardsScore;
    }


    void setCapturedCities(std::string c)
    {
        capturedCities.push_back(c);
    }
    std::vector<std::string> getCapturedCities()
    {
        return capturedCities;
    }


    void setBiggestYellowCard(int b)
    {
        biggestYellowCard = b;
    }
    int getBiggestYellowCard()
    {
        return biggestYellowCard;
    }
private:
    std::string name;
    int age;
    std::string color;
    std::vector<std::string> cardsInHand;
    bool winner = false;
    bool pass = false;
    std::vector<std::string> yellowCardsOnTable;
    std::vector<std::string> purpleCardsOnTable;
    int totalScore ;
    int yellowCardsScore ;
    std::vector<std::string> capturedCities;
    int biggestYellowCard;
};