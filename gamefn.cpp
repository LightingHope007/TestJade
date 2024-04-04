//
#include <iostream>
#include <iomanip>

using namespace std;
#include "gamefn.h"

Day::Day(int x){
    
    time = x;
    next = NULL;
    cout << "Day start at " << setfill('0') <<setw(2) << x/60 
    <<":"<<  setfill('0') << setw(2) << x%60 << endl;
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

void Day::showTime(){
      return time;
}

int Day::DayPass(int x){
      time+=x;
}