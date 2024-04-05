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

int Day::showTime(){
      return time;
}

void Day::DayPass(int x){
      time+=x;
}

//This is where each day run until the end of the day.
void Day::Drun(int n){
      while(1){
            int i,x=showTime();
            system("clear");
            cout<<"Prototype. Time: "<<
            setfill('0') <<setw(2) << x/60 
            <<":"<<  setfill('0') << setw(2) << x%60 <<" Day "<<n<< endl
            <<"1.Wait."<<endl
            <<"2.Skip day."<<endl;
            cin>>i;
            switch(i){
                  case 1:
                        DayPass(30);
                        break;
                  case 2:
                        return;
                  default:
                        break;
            }

            if(showTime()>=1440) break;
      }
}