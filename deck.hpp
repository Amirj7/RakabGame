#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "yellow1.hpp"
#include "yellow2.hpp"
#include "yellow3.hpp"
#include "yellow4.hpp"
#include "yellow5.hpp"
#include "yellow6.hpp"
#include "yellow10.hpp"
#include "shahdokht.hpp"
#include "spring.hpp"
#include "winter.hpp"
#include "tablzan.hpp"
#include "matarsak.hpp"

class Deck
{
    public:
        Deck(){
            fillDeck();
        }

        void fillDeck(){
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

            Matarsak M;
            for (int i{}; i < M.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("matarsak");
            }

            Shahdokht Sd;
            for (int i{}; i < Sd.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("shahdokht");
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

            Tablzan T;
            for(int i{}; i < T.getNumOfCard(); i++)
            {
                cardsInDeck.push_back("tablzan");
            }

            shuffleDeck();
        }
    
        void shuffleDeck(){
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(cardsInDeck.begin(), cardsInDeck.end(), g);
        }
    
        std::vector<std::string> pakhsh(){
            std::vector<std::string> p;
            for(int i{} ; i < 10 ; i++){
                std::string temp = cardsInDeck.back();
                cardsInDeck.pop_back();
                p.push_back(temp);
            }
            return p;
        }
    private:
        std::vector<std::string>cardsInDeck;
};