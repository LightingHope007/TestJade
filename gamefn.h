//this is for placing all of the minigame.

#include <iostream>
using namespace std;

class day{
    private:
        int energy, time;//each day has it's own energy.(can change it to player)
        day *next;
    public:
        day(int = 1);
        ~day();

        day* move_next();//for LL.
        void insert(day*&);//for LL.
};

//might not need to be class, can be only structure for collecting achievement only.
class player{
    private:
        int goal1, goal2;
    public:
        player();
        ~player();

};
