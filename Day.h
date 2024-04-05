//this is for placing all of the minigame.
#ifndef Day_h
#define Day_h

#include <iostream>
using namespace std;

class Day{
    private:
        int  time;//each day has it's own energy.(can change it to player)
        Day *next;
    public:
        Day(int = 360);
        ~Day();

        Day* move_next();//for LL.
        void insert(Day*&);//for LL.

        int showTime();//request time value
        void DayPass(int=0);//progress time

        void Drun(int=1);//start the day
};

//might not need to be class, can be only structure for collecting achievement only.
class player{
    private:
        int goal1, goal2;
        int energy;
    public:
        player();
        ~player();

};

#endif
