#ifndef Player_h
#define Player_h

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "NODE.h"

class Player:public NODE{
    private:
        string name;
        int point;
    public:
        Player(int=0,string="none");//constructer
        void getPdata(int=0);//input name
        void show_point();//for leaderboard
        void addPoint(int=0);//gain point
        int getPoint();//call for point
        string getname();//call for name
};


#endif