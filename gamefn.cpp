//
#include <iostream>

using namespace std;
#include "gamefn.h"

Day::Day(int x, int y){
    energy = x;
    time = y;
    next = NULL;
    cout << "Adding " << x <<" to energy."<< endl;
}

Day:: ~Day(){
      cout << "Day is being deleted" << endl;
}

Day* Day::move_next(){
      return next;
}

void Day::insert(Day*& x){
      x -> next = this;
}