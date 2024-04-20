#ifndef PTT_class_h
#define PTT_class_h

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;


class PTTquiz{
    private:
        int Diff,point;
        string word;
    public:
        void Tgetdata(string);
        int Tquestion(double*);
};




#endif