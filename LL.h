//using node LL(link list) as days.
class LL{
     day *hol;//head of link list pointer 
     int size;
public:
     LL();//start link iist
     ~LL();//to remove all link list 

     void add_node(day *&);
     int show_size();//using this for loop in main.c
     day* get_node(int i);//for getting information of node.
};
