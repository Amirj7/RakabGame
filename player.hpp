#include <iostream>
#include <string>
#include <vector>

class Player
{
public:
    bool check_Player_Num(int num)
    {
        if (num > maxPlayers || num < minPlayers)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void set_Name(std ::string name)
    {
        playerName = name;
    }

    void set_Age(int age)
    {
        playerAge = age;
    }

    void set_Color(std ::string color)
    {
        PlayerColor = color;
    }

    int get_Age()
    {
        return playerAge;
    }

    std::string get_Name()
    {
        return playerName;
    }
    
    std::string get_color()
    {
        return PlayerColor;
    }

    void set_Cards_In_Hand(std::string card)
    {
        cardsInHand.push_back(card);
    }

    void capture_City(std ::string city)
    {
        capturedCities.push_back(city);
    }

    int numOfCapturedCities(){
        return (sizeof(capturedCities)  / sizeof(capturedCities[0]));
    }

    int get_Score() const
    {
        return playerScore;
    }

    void set_Score(int score)
    {
        playerScore = score;
    }



private:
    int playerAge;
    std ::string playerName;
    std ::vector<std::vector<int>> cardsPlayed;
    std ::vector<std::string> cardsInHand;
    std ::vector<std ::string> capturedCities;
    int playerScore;
    const int maxPlayers = 6;
    std ::string PlayerColor;
    const int minPlayers = 3;
};

