#pragma once
#include <iostream>
#include <vector>
#include "Cart.hpp"
#include "deck.hpp"

class Player
{

public:
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

    void setCardsInHand(std::string h)
    {
        cardsInHand.push_back(h);
    }

    void getCardsInHand()
    {
        for (int i{}; i < sizeof(cardsInHand) / sizeof(cardsInHand[0]); i++)
        {
            std::cout << cardsInHand[i] << "  ";
        }
    }

    void setYellowCardsOnTable(std::string y)
    {
        yellowCardsOnTable.push_back(y);
    }

    void setPurpleCardsOnTable(std::string p)
    {
        purpleCardsOnTable.push_back(p);
    }

    int numOfPlayerCities()
    {
        return (sizeof(capturedCities) / sizeof(capturedCities[0]));
    }

    void setWinner(bool x)
    {
        winner = x;
    }

    bool getWinner()
    {
        return winner;
    }

    void setPass(bool temp)
    {
        pass = temp;
    }

    bool getPass()
    {
        return pass;
    }

    // bool checkThatPlayerHaveTheCardOrNot(std::string n)
    // {
    //     bool x = false;
    //     for (int i{}; i < sizeof(cardsInHand) / sizeof(cardsInHand[0]); i++)
    //     {
    //         if (cardsInHand[i] == n)
    //         {
    //             x = true;
    //         }
    //     }
    //     return x;
    // }
    bool checkThatPlayerHaveTheCardOrNot(std::string cardName)
    {
        bool exist = false ;
        for (auto &card : cardsInHand){
            if (card == cardName){
                exist = true ;
            }
        }
        return exist ;
    }


    bool isYellowCard(std::string s)
    {
        bool x = false;
        if (s.find("yellow"))
        {
            x = true;
        }
        return x;
    }

    std::string getYellowCardsOnTable(int m)
    {
        return yellowCardsOnTable[m];
    }

    int getSizeOfYellowCardsOnTable()
    {
        return (sizeof(yellowCardsOnTable) / sizeof(yellowCardsOnTable[0]));
    }

    std::string getPurpleCardsOnTable(int m)
    {
        return purpleCardsOnTable[m];
    }

    int getSizeOfPurpleCardsOnTable()
    {
        return (sizeof(purpleCardsOnTable) / sizeof(purpleCardsOnTable[0]));
    }

    void setYellowCardsScoreInYellowCardsScore(int x)
    {
        yellowCardsScore += x;
    }

    void setPurpleCardsScoreInPuepleCardsScore(int x)
    {
        purpleCardsScore += x;
    }

    int getYellowCardsScore()
    {
        return yellowCardsScore;
    }

    void popBackCardsOnTable(std::string s)
    {
        if (isYellowCard(s))
        {
            for (int i{}; i < sizeof(yellowCardsOnTable) / sizeof(yellowCardsOnTable[0]); i++)
            {
                if (yellowCardsOnTable[i] == s)
                {
                    yellowCardsOnTable[i].pop_back();
                }
            }
        }
        else
        {
            for (int i{}; i < sizeof(purpleCardsOnTable) / sizeof(purpleCardsOnTable[0]); i++)
            {
                if (purpleCardsOnTable[i] == s)
                {
                    purpleCardsOnTable[i].pop_back();
                }
            }
        }
    }

    int getCardValueInHand(int index) const
    {
        if (index >= 0 && index < cardsInHand.size())
        {
            return 1;
        }
        return -1;
    }

    void winterOnYellowCardsScore()
    {
        yellowCardsScore = 1;
    }

    void springScore(int m)
    {
        springCardsScore = m;
    }

    void setTotalScore()
    {
        totalScore = purpleCardsScore + yellowCardsScore + springCardsScore;
    }

    // void showPlayerCards(std::vector<Player> p)
    // {
    //     for (int i{}; i < sizeof(p) / sizeof(p[0]); i++)
    //     {
    //         std::cout << "i want to show " << p[i].getName() << "'s cards!." << std::endl;
    //         std::cout << "please give the system to " << p[i].getName() << std::endl;

    //         bool showCards = false;
    //         int counter{2};
    //         while (counter != 0)
    //         {
    //             int key = _getch();
    //             if (key == 13)
    //             { // 13 is the ASCII code for Enter key
    //                 if (showCards)
    //                 {
    //                     // Clear the console
    //                     system("CLS");
    //                     showCards = false;
    //                     counter--;
    //                 }
    //                 else
    //                 {
    //                     // Display the message
    //                     p[i].getCardsInHand();
    //                     showCards = true;
    //                     counter--;
    //                 }
    //             }
    //         }
    //     }
    // }
void showPlayerCards()
{
for (auto &card : cardsInHand){
    std::cout << card << "  ";
}
}



private:
    std::string name;
    int age;
    std::string color;
    std::vector<std::string> cardsInHand;
    std::vector<std::string> purpleCardsOnTable;
    std::vector<std::string> yellowCardsOnTable;
    std::vector<std::string> capturedCities;
    bool winner = false;
    bool pass = false;
    int totalScore;
    int springCardsScore;
    int yellowCardsScore;
    int purpleCardsScore;
};