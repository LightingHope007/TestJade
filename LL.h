#ifndef LL_h
#define LL_h

#include <iostream>

#include "NODE.h"
#include "Player.h"

//using node LL(link list) as days.
class LL{
     NODE *hol;//head of link list pointer 
     int size;
public:
     LL();//Constructor
     ~LL();//Destructor

     void add_node(NODE*&);
     int show_size();//using this for loop in main.c
     NODE* get_node(int i);//for getting information of node.
     NODE* head();

     void showscore();
     void run(NODE*);//run the game\

     void PTTrun(int*,int=1);
};

#endif
