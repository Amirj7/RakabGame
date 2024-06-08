#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Player
{
public:
    Player(int age, string name)
    {
        
        playerAge = age;
        playerName = name;
        playerScore = 0; // Initialize player score to 0
        playerCount++;
    }

    bool check_Player_Num (int num)
    {
        if (playerCount > maxPlayers || playerCount < minPlayers)
        {
            return false;
        }
        else {
            return true;
        }
    }
    void setCardsInHand(vector<int> cards)
    {
        cardsInHand = cards;
    }

    void captureCity(string city)
    {
        capturedCities.push_back(city);
    }

    int getScore() const
    {
        return playerScore;
    }

    void setScore(int score)
    {
        playerScore = score;
    }

    static int getPlayerCount()
    {
        return playerCount;
    }

private:
    int playerAge;
    string playerName;
    vector<vector<int>> cardsPlayed;
    vector<int> cardsInHand;
    vector<string> capturedCities;
    int playerScore; 
    static int playerCount; 
    static const int maxPlayers = 6; 
    string color;
    int minPlayers = 3;
};

int Player::playerCount = 0;