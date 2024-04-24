#ifndef PTT_class_h
#define PTT_class_h

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "NODE.h"

class PTTquiz: public NODE{
    private:
        int Diff,point;
        string word;
    public:
        void Tgetdata(string);//setup difficulty and points
        int Tquestion(double*);//run the stage
        void Treetete(int*);
};




#endif