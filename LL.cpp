#include <iostream>
#include <cstdlib>//for random
#include <time.h>//for random

#include "LL.h"
#include "NODE.h"
#include "Player.h"
using namespace std;

LL::LL(){
     hol = NULL;
     size = 0;//size need to be 7 (7 days)
}

LL::~LL(){
     int i;
     
     for(i = 0; i < size; i++){
          NODE *t = hol;
          hol = hol->move_next();
          delete t;
     }
     size = 0;
}

//add node: first input is head
void LL::add_node(NODE *&A){
     NODE* t=hol;
     if(hol==NULL){
          hol = A;
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
          return NULL;// out of bounds

     NODE *t = hol;
     int i;
     for (i = 0; i < index; i++){ 
          if (t == NULL) return NULL; // Should not happen, but handle it defensively
          t = t->move_next();
     }
     return t;
}

NODE *LL::head(){
     return hol;
}

//show players' score
void LL::showscore(){
     int i;
     NODE *t = hol;

     cout<<"----------------------------------"<<endl
     <<"Leaderboard"<<endl
     <<"----------------------------------"<<endl;
     for(i = 0; i < size; i++){
          t->show_point();
          t=t->move_next();
     }
}

void LL::run(NODE* x){
     int i,j;
     NODE *t = hol,*v;
     for(i = 0; i < size; i++){
          v = x;
          for(j = 0; 1; j++){
               system("clear");
               cout<<"Game "<<i+1<<" Player "<<j+1<<endl;
               cout << "Press Enter to Continue";
               cin.ignore();
               
               v->addPoint(t->run(t->show_num()));
               if(v->move_next()==NULL) break;
               v=v->move_next();
          }
          t=t->move_next();
     }
     cout<<"DONE!"<<endl;
}

void LL::PTTrun(int *a, int b){
     int i;
     NODE *t;
     srand(time(NULL));
     for(i=0;i<b;i++){
          t=get_node(rand()%size);
          *a=t->Tquestion();
     }
}