#ifndef LL_h
#define LL_h

#include <iostream>

#include "NODE.h"
#include "Player.h"

//using node LL(link list) as days.
class LL{
     NODE *phol;//head of link list pointer 
     int size;
public:
     LL();//Constructor
     ~LL();//Destructor

     void add_node(NODE*&);
     int show_size();//using this for loop in main.c
     NODE* get_node(int i);//for getting information of node.

     void showscore();//run the game
};

#endif
