#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "Yellow1.hpp"
#include "Yellow2.hpp"
#include "Yellow3.hpp"
#include "Yellow4.hpp"
#include "Yellow5.hpp"
#include "Yellow6.hpp"
#include "Yellow10.hpp"
#include "Shirdokht.hpp"
#include "Spring.hpp"
#include "Winter.hpp"
#include "Tablzan.hpp"
#include "Matarsag.hpp"

class Deck
{
    public:
        Deck()
        {
            fillDeck();
            shuffleDeck(cardsInDeck);
        }

        void fillDeck()
        {
            Yellow1 y1;
            for (int i{}; i < y1.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("yellow1");
            }

            Yellow2 y2;
            for (int i{}; i < y2.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("yellow2");
            }

            Yellow3 y3;
            for (int i{}; i < y3.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("yellow3");
            }

            Yellow4 y4;
            for (int i{}; i < y4.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("yellow4");
            }

            Yellow5 y5;
            for (int i{}; i < y5.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("yellow5");
            }

            Yellow6 y6;
            for (int i{}; i < y6.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("yellow6");
            }

            Yellow10 y10;
            for (int i{}; i < y10.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("yellow10");
            }

            Matarsag M;
            for (int i{}; i < M.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("matarsag");
            }

            Shirdokht Sd;
            for (int i{}; i < Sd.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("shirdokht");
            }

            Spring S;
            for (int i{}; i < S.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("spring");
            }

            Winter W;
            for (int i{}; i < W.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("winter");
            }
        }

        void shuffleDeck(std::vector <std::string> cards)
        {
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(cards.begin() , cards.end() , g);
        }

        std::string getTheLastElementOfCardsInDeck()
        {
            std::string temp = cardsInDeck.back();
            cardsInDeck.pop_back();
            return temp;
        }
    protected:
        std::vector<std::string> cardsInDeck;
};