#include <iostream>
#include <cstdlib>//for random
#include <time.h>//for random
#include <chrono>
#include <thread>
#include <cstring>

#include "LL.h"
#include "NODE.h"
#include "Player.h"
using namespace std;
using namespace chrono;
using namespace this_thread;

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
//run the game
void LL::run(NODE* x){
     int i,j;
     string line;
     NODE *t = hol,*v;
     for(i = 0; i < size; i++){
          v = x;
          for(j = 0; 1; j++){
               system("clear");
               cout<<"Game "<<i+1<<" Player "<<j+1<<endl;
               cout << "Press Enter to Continue"<<endl;
               cin.clear();
               cin.ignore(10000,'\n');
               
               
               v->addPoint(t->run(t->show_num()));
               if(v->move_next()==NULL) break;
               v=v->move_next();
          }
          t=t->move_next();
     }
     cout<<"DONE!"<<endl;
}
//sort high to low then show Leaderboard
void LL::SortnShow(NODE* x){
     LL newL;
     NODE *t=x,*v;
     int i,j,prevMax=0,CurrMax=0,temp;
     string CurrName;
     for(i=0;i<size;i++){
          t=x;
          CurrMax=0;
          for(j=0;j<size;j++){
               if(t->getPoint()>=CurrMax){
                    if(prevMax==0){
                         CurrMax=t->getPoint();
                         CurrName=t->getname();
                    }
                    else if(t->getPoint()<prevMax&&prevMax!=0){
                         CurrMax=t->getPoint();
                         CurrName=t->getname();
                    }
               }
               t=t->move_next();
          }
          prevMax=CurrMax;
          v=new Player(CurrMax,CurrName);
          newL.add_node(v);
     }
     newL.showscore();
}
//This is for PTTgame
void LL::PTTrun(int *a, double* b){
     int i;
     NODE *t;
     double sub;
     srand(time(NULL));
     while((*b)>0){
          t=get_node(rand()%size);
          (*a)+=t->Tquestion(&sub);
          (*b)+=sub;
          
     }
}