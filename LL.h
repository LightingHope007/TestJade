#ifndef LL_h
#define LL_h

#include <iostream>

#include "NODE.h"

class NODE;

//using node LL(link list) as days.
class LL{
     NODE *hol;//head of link list pointer 
     int size;
public:
     LL();//Constructor
     ~LL();//Destructor

     void add_node(NODE*&);
     int show_size();//using this for loop in main.c
     NODE* get_node(int i);//for getting information of specific node.
     NODE* head();//call for head of node

     int checkname(string,NODE*);
     void showscore();//showleaderboard
     void run(NODE*);//run the game
     void SortnShow(NODE*);//Sort the List and show after

     void PTTrun(int*,double*);//For running Plant the Tree game
};

#endif
