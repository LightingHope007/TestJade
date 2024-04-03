#include <iostream>

#include"gamefn.h"
#include"LL.h"
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

void LL::add_node(day *&A){
     hol -> insert(A);
     hol = A;
     size++;
}

int LL::show_size(){
     return size;
}

//this is for checking days and day loop
NODE *LL::get_node(int index){
     if(index < 0 || index >= size) 
            return nullptr;// out of bounds

     NODE *t = hol;
     int c;
     for (c = 0; c < index; c++){ 
            if (t == nullptr) return nullptr; // Should not happen, but handle it defensively
            t = t->move_next();
     }
     return t;
}
