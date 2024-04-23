//this is for placing all of the minigame.
#ifndef Minigame_h
#define Minigame_h

#include <iostream>
using namespace std;

#include "NODE.h"

class miniG: public NODE{
    friend class Player;

    private:
        int num;
    public:
        miniG(int=0);
        ~miniG();
        void selectgame(int =0);//for startup
        int run(int =0);//run the game
        int show_num();//call for num value
        int Check_ans(string ="none");
        
};

//might not need to be class, can be only structure for collecting achievement only.

#endif
