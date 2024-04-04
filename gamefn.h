//this is for placing all of the minigame.
#ifndef gamefn_h
#define gamefn_h

#include <iostream>
using namespace std;

class Day{
    private:
        int energy, time;//each day has it's own energy.(can change it to player)
        Day *next;
    public:
        Day(int = 1, int = 1);
        ~Day();

        Day* move_next();//for LL.
        void insert(Day*&);//for LL.
};

//might not need to be class, can be only structure for collecting achievement only.
class player{
    private:
        int goal1, goal2;
    public:
        player();
        ~player();

};

#endif
