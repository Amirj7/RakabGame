#include <iostream>
#include <vector>
#include "yellow1.hpp"
#include "yellow2.hpp"
#include "yellow3.hpp"
#include "yellow4.hpp"
#include "yellow5.hpp"
#include "yellow6.hpp"
#include "yellow10.hpp"
#include "matarsag.hpp"
#include "parchamdar.hpp"
#include "shirdokht.hpp"
#include "shirzan.hpp"
#include "spring.hpp"
#include "winter.hpp"

class Deck : public Yellow1 , public Yellow2 , public Yellow3 , public Yellow4 , public Yellow5 , public Yellow6 ,public Yellow10 ,public Matarsag , public parcahmdar , public shirdokht , public shirzan , public spring , public winter
{
    public:
        void cardsInDeck()
        {
            Yellow1 y1;
            for(int i{} ; i < y1.get_num_Of_Card() ; i++){
                cards.push_back("yellow1");
            }

            Yellow2 y2;
            for(int i{} ; i < y2.get_num_Of_Card() ; i++){
                cards.push_back("yellow2");
            }

            Yellow3 y3;
            for(int i{} ; i < y3.get_num_Of_Card() ; i++){
                cards.push_back("yellow3");
            }

            Yellow4 y4;
            for(int i{} ; i < y4.get_num_Of_Card() ; i++){
                cards.push_back("yellow4");
            }

            Yellow5 y5;
            for(int i{} ; i < y5.get_num_Of_Card() ; i++){
                cards.push_back("yellow5");
            }

            Yellow6 y6;
            for(int i{} ; i < y6.get_num_Of_Card() ; i++){
                cards.push_back("yellow6");
            }

            Yellow10 y10;
            for(int i{} ; i < y10.get_num_Of_Card() ; i++){
                cards.push_back("yellow10");
            }

            Matarsag M1;
            for(int i{} ; i < M1.get_num_Of_Card() ; i++){
                cards.push_back("Matarsag");
            }

            parcahmdar P1;
            for(int i{} ; i < P1.get_num_Of_Card() ; i++){
                cards.push_back("parchamdar");
            }

            shirdokht Sd1;
            for(int i{} ; i < Sd1.get_num_Of_Card() ; i++){
                cards.push_back("shirdokht");
            }

            shirzan Sz1;
            for(int i{} ; i < Sz1.get_num_Of_Card() ; i++){
                cards.push_back("shirzan");
            }

            spring S1;
            for(int i{} ; i < S1.get_num_Of_Card() ; i++){
                cards.push_back("spring");
            }

            winter W1;
            for(int i{} ; i < W1.get_num_Of_Card() ; i++){
                cards.push_back("winter");
            }

        }

    protected:
        std::vector <std::string> cards;
};
