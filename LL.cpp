#include <iostream>

#include "LL.h"
#include "Day.h"
using namespace std;

LL::LL(){
     hol = nullptr;
     size = 0;//size need to be 7 (7 days)
}

LL::~LL(){
     int i;
     for(i = 0; i < size; i++){
          Day *t = hol;
          hol = hol->move_next();
          delete t;
     }
     size = 0;
}

void LL::add_node(Day *&A){
     hol -> insert(A);
     hol = A;
     size++;
}

int LL::show_size(){
     return size;
}

//this is for checking days and Day loop
Day *LL::get_node(int index){
     if(index < 0 || index >= size) 
          return nullptr;// out of bounds

     Day *t = hol;
     int i;
     for (i = 0; i < index; i++){ 
          if (t == nullptr) return nullptr; // Should not happen, but handle it defensively
          t = t->move_next();
     }
     return t;
}

//run the game
void LL::run(){
     int i;
     for(i = 0; i < size; i++){
          Day *t = hol;
          hol = hol->move_next();
          t->Drun(i+1);
     }
     size = 0;
}
