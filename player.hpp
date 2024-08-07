#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Player
{
public:
    Player(std::string n, int a, std::string c, std::vector<std::string> h={})
    {
        setName(n);
        setAge(a);
        setColor(c);
        setCardsInHand(h);
        yellowCardsScore = 0;
        totalScore = 0;
    }

    void setName(std::string n)
    {
        name = n;
    }
    std::string getName() const
    {
        return name;
    }

    void setAge(int a)
    {
        age = a;
    }
    int getAge() const
    {
        return age;
    }

    void setColor(std::string c)
    {
        color = c;
    }
    std::string getColor() const
    {
        return color;
    }

    void setCardsInHand(std::vector<std::string> c)
    {
        cardsInHand = c;
    }
    std::vector<std::string> getCardsInHand() const
    {
        return cardsInHand;
    }
    void setCardsInHand(std::string c)
    {
        cardsInHand.push_back(c);
    }

    void setWinnerForNeshanJang(const bool w)
    {
        winner = w;
    }
    bool getWinnerForNeshanJang() const
    {
        return winner;
    }

    void setPass(bool p)
    {
        pass = p;
    }
    bool getPass() const
    {
        return pass;
    }

    void setYellowCardsOnTable(std::string y)
    {
        yellowCardsOnTable.push_back(y);
    }
    std::vector<std::string> getYellowCardsOnTable() const
    {
        return yellowCardsOnTable;
    }

    void setPurpleCardsOnTable(std::string p)
    {
        purpleCardsOnTable.push_back(p);
    }
    std::vector<std::string> getPurpleCardsOnTable() const
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

    int getTotalScore() const
    {
        return totalScore;
    }

    void setYellowScore(int a)
    {
        yellowCardsScore = yellowCardsScore + a;
    }

    int getYellowScore() const
    {
        return yellowCardsScore;
    }

    void setCapturedCities(std::string c)
    {
        capturedCities.push_back(c);
    }

    std::vector<std::string> getCapturedCities() const
    {
        return capturedCities;
    }

    void setBiggestYellowCard(int b)
    {
        biggestYellowCard = b;
    }

    int getBiggestYellowCard() const
    {
        return biggestYellowCard;
    }

    void decreaseScore(int amount)
    {
        totalScore -= amount;
    }

    void setPlayerPlayedRishsefidOrNot(bool f)
    {
        rishSefidPlayed = f;
    }

    bool getPlayerPlayedRishsefidOrNot() const
    {
        return rishSefidPlayed;
    }

    void setNeshaneSolh(int Neshan) 
    {
        neshaneSolh += Neshan;
    }

    int getNeshaneSolh() const
    {
        return neshaneSolh;
    }

    void setShirzanCount(int shirzanCount)
    {
        shirzanNum += shirzanCount;
    }

    int getShirzanCount()
    {
        return shirzanNum;
    }

    void setNeshanJang(std::string nj)
    {
        neshanJang = nj;
    }
    std::string getNeshanJang() const
    {
        return neshanJang;
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
    int totalScore;
    int yellowCardsScore;
    std::vector<std::string> capturedCities;
    int biggestYellowCard = 0;
    bool rishSefidPlayed = false;
    int initialScore;
    int finalScore;
    int neshaneSolh = 0;
    int shirzanNum = 0;
    std::vector<int> yellowCardScores;
    std::string restrictedProvince;
    std::string neshanJang;

};