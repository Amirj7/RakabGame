#include <iostream>

class Yellow6
{
    public:
        int get_Point(){
            return point;
        }

        int get_num_Of_Card(){
            return num_Of_Card;
        }
    private:
        const int point = 6;
        const int num_Of_Card = 8;
};