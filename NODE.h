#ifndef NODE_h
#define NODE_h

#include <iostream>
#include <iomanip>
using namespace std;

#include "Player.h"
#include "Minigame.h"

class NODE:public Player, public miniG{
    private:
        NODE* next;
    public:
        NODE();
        ~NODE();
        NODE* move_next();//for LL.
        void insert(NODE*&);//for LL.
};



#endif 