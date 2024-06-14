#include <iostream>
#include <vector>

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
            for(int i{} ; i < sizeof(cardsInHand) / sizeof(cardsInHand[0]) ; i++)
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

        bool checkThatPlayerHaveTheCardOrNot(std::string n)
    {
        bool x = false;
        for(int i{} ; i < sizeof(cardsInHand) / sizeof(cardsInHand[0]) ; i++)
        {
            if(cardsInHand[i] == n)
            {
                x = true;
            }
        }
        return x;
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
            if(isYellowCard(s))
            {
                for(int i{} ; i < sizeof(yellowCardsOnTable) / sizeof(yellowCardsOnTable[0]) ; i++)
                {
                    if(yellowCardsOnTable[i] == s)
                    {
                        yellowCardsOnTable[i].pop_back();
                    }
                }
            }
            else
            {
                for(int i{} ; i < sizeof(purpleCardsOnTable) / sizeof(purpleCardsOnTable[0]) ; i++)
                {
                    if(purpleCardsOnTable[i] == s)
                    {
                        purpleCardsOnTable[i].pop_back();
                    }     
                }
            }
        }
    
        void winterOnYellowCardsScore()
        {
            yellowCardsScore = (yellowCardsScore / yellowCardsScore);
        }
   
        void setTotalScore()
        {
            totalScore = purpleCardsScore + yellowCardsScore;
        }
    private:
        std::string name;
        int age;
        std::string color;
        std::vector <std::string> cardsInHand;
        std::vector <std::string> purpleCardsOnTable;
        std::vector <std::string> yellowCardsOnTable;
        std::vector <std::string> capturedCities;
        bool winner = false;
        bool pass = false;
        int totalScore;
        int yellowCardsScore;
        int purpleCardsScore;
};