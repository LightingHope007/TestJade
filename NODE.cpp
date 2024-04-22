#include <iostream>
#include <iomanip>
using namespace std;

#include "NODE.h"
#include "Player.h"

NODE::NODE(){
    next=nullptr;
    //cout<<"Node created"<<endl;
}

NODE::~NODE(){
    //cout<<"NOde gone"<<endl;
}

NODE* NODE::move_next(){
      return next;
}

void NODE::insert(NODE*& x){
      next = x;
}

void NODE::getPdata(int){cout<<"blank"<<endl; return;}
void NODE::show_point(){cout<<"blank"<<endl; return;}
void NODE::addPoint(int){cout<<"blank"<<endl; return;}
int NODE::getPoint(){cout<<"blank"<<endl; return 0;}
string NODE::getname(){cout<<"blank"<<endl; return "blank";}

void NODE::selectgame(int){cout<<"blank"<<endl; return;}
int NODE::run(int){cout<<"blank"<<endl; return 0;}
int NODE::show_num(){cout<<"blank"<<endl; return 0;}

void NODE::Tgetdata(string){cout<<"blank"<<endl; return;}
int NODE::Tquestion(double*){cout<<"blank"<<endl; return 0;}


