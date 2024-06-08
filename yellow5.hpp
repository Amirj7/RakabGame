#include <iostream>

class Yellow5
{
    public:
        int get_Point(){
            return point;
        }

        int get_num_Of_Card(){
            return num_Of_Card;
        }
    private:
        const int point = 5;
        const int num_Of_Card = 8;
};