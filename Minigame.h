//this is for placing all of the minigame.
#ifndef Minigame_h
#define Minigame_h

#include <iostream>
using namespace std;


class miniG{
    friend class Player;

    private:
        int num;
    public:
        miniG(int=0);
        ~miniG();
        void selectgame(int =0);
        int run(int =0);
        int show_num();
        
};

//might not need to be class, can be only structure for collecting achievement only.

#endif
