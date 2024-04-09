#ifndef Player_h
#define Player_h

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;


class Player{
    private:
        string name;
        int point;
    public:
        void getPdata(int=0);//input name
        void show_point();//for leaderboard
        void addPoint(int=0);//gain point
};


#endif