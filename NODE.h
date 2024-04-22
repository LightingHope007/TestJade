#ifndef NODE_h
#define NODE_h

#include <iostream>
#include <iomanip>
using namespace std;



class NODE{
    private:
        NODE* next;
    public:
        NODE();
        virtual ~NODE();
        NODE* move_next();//for LL.
        void insert(NODE*&);//for LL.

        //for polymorph
        //Player
        virtual void getPdata(int);
        virtual void show_point();
        virtual void addPoint(int);
        virtual int getPoint();
        virtual string getname();
        //miniG
        virtual void selectgame(int);
        virtual int run(int);
        virtual int show_num();
        //PTT_class
        virtual void Tgetdata(string);
        virtual int Tquestion(double*);
};



#endif 