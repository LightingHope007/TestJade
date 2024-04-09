#include <iostream>

#include "LL.h"
#include "NODE.h"
#include "Player.h"
using namespace std;

LL::LL(){
     phol = nullptr;
     size = 0;//size need to be 7 (7 days)
}

LL::~LL(){
     int i;
     
     for(i = 0; i < size; i++){
          NODE *t = phol;
          phol = phol->move_next();
          delete t;
     }
     size = 0;
}

//add node: first input is head
void LL::add_node(NODE *&A){
     NODE* t=phol;
     if(phol==nullptr){
          phol = A;
          size++;
          return;
     }
     for(int i = 0; i < size; i++){
          if(t->move_next()==NULL) break;
          t=t->move_next();
     }
     t->insert(A);

     
     size++;
}

int LL::show_size(){
     return size;
}

//this is for checking NODE loop
NODE *LL::get_node(int index){
     if(index < 0 || index >= size) 
          return nullptr;// out of bounds

     NODE *t = phol;
     int i;
     for (i = 0; i < index; i++){ 
          if (t == nullptr) return nullptr; // Should not happen, but handle it defensively
          t = t->move_next();
     }
     return t;
}

//show players' score
void LL::showscore(){
     int i;
     NODE *t = phol;

     cout<<"----------------------------------"<<endl
     <<"Leaderboard"<<endl
     <<"----------------------------------"<<endl;
     for(i = 0; i < size; i++){
          t->show_point();
          t=t->move_next();
     }
}
