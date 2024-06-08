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
        if (playerCount >= maxPlayers)
        {
            throw ("Cannot create more than 6 players.");
        }
        playerAge = age;
        playerName = name;
        playerScore = 0; // Initialize player score to 0
        playerCount++;
    }

    ~Player()
    {
        playerCount--;
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
};

int Player::playerCount = 0;