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
                std::cout << cardsInHand[i] << " ";
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

        void setNumOfShirdokhtCard(std::vector<std::string> Sh)
        {
            int counter;
            for(int i{} ; i < sizeof(Sh) / sizeof(Sh[0]) ; i++)
            {
                if(Sh[i] == "shirdokht")
                {
                    counter++;
                }
            }
            numOfShirdokhtCard = counter;
        }

        int getNumOfShirdokhtCard()
        {
            return numOfShirdokhtCard;
        }
    
        void setWinner(bool x)
        {
            winner = x;
        }

        bool getWinner()
        {
            return winner;
        }
    private:
        std::string name;
        int age;
        std::string color;
        std::vector <std::string> cardsInHand;
        std::vector <std::string> purpleCardsOnTable;
        std::vector <std::string> yellowCardsOnTable;
        std::vector <std::string> capturedCities;
        int numOfShirdokhtCard;
        bool winner = false;
};