#include <iostream>
//using node LL(link list) as days.
class LL{
     Day *hol;//head of link list pointer 
     int size;
public:
     LL();//start link iist
     ~LL();//to remove all link list 

     void add_node(Day *&);
     int show_size();//using this for loop in main.c
     Day* get_node(int i);//for getting information of node.
};
