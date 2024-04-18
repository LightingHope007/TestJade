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
        int Tquestion();
};

void PTTquiz::Tgetdata(string snew){
    word = snew;
    switch(snew.length()/5){
        case 0:
            Diff=1;
            point=1;
            break;
        case 1:
            Diff=2;
            point=2;
            break;
        case 2:
            Diff=3;
            point=3;
            break;
        default:
            Diff=4;
            point=(snew.length()/5);
            break;
    }
}

int PTTquiz::Tquestion(){
    string answer;
    while(1){
        cout<<word<<endl;
        cin>>answer;
        cin.clear();
        cin.ignore(10000,'\n');
        system("clear");
        if(answer!=word){
            cout<<"wrong!"<<endl;        
            continue;
        }
    }
    cout<<"correct!"<<endl;
    return point;
}


#endif