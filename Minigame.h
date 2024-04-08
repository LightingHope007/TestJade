//this is for placing all of the minigame.
#ifndef Minigame_h
#define Minigame_h

#include <iostream>
using namespace std;

class miniG{
    private:
        int  point;
    public:
        miniG(int = 0);
        ~miniG();
        void addPoint(int=0);//gain point
};

//might not need to be class, can be only structure for collecting achievement only.

#endif
