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


