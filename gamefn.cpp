//
#include <iostream>

#include"gamefn.h"
using namespace std;

day::day(int x, int y){
    energy = x;
    time = y;
    next = NULL;
    cout << "Adding " << x <<" to energy."<< endl;
}

day:: ~day(){
      cout << "day is being deleted" << endl;
}

day* day::move_next(){
      return next;
}

void day::insert(day*& x){
      x -> next = this;
}
