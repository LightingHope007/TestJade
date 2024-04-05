#ifndef LL_h
#define LL_h

#include <iostream>

#include "Day.h"

//using node LL(link list) as days.
class LL{
     Day *hol;//head of link list pointer 
     int size;
public:
     LL();//Constructor
     ~LL();//Destructor

     void add_node(Day *&);
     int show_size();//using this for loop in main.c
     Day* get_node(int i);//for getting information of node.

     void run();//run the game
};

#endif
