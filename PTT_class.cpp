#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace this_thread;

#include "PTT_class.h"

void PTTquiz::Tgetdata(string snew){
    word = snew;
    switch(snew.length()/5){
        case 0:
            Diff=1;
            point=1;
            break;
        case 1:
            Diff=2;
            point=2;
            break;
        case 2:
            Diff=3;
            point=3;
            break;
        default:
            Diff=4;
            point=(snew.length()/5);
            break;
    }
}

int PTTquiz::Tquestion(double* x){
    string answer;
        cout<<word<<endl;

        //take input
        auto start = steady_clock::now();//start timer

        cout<<"Enter the answer :";
        cin>>answer;
        cin.clear();
        cin.ignore(10000,'\n');

        auto end = steady_clock::now();//end timer
        duration<double> elapsed_seconds = end - start;//time difference
        (*x)-=elapsed_seconds.count();

        system("clear");
        if(answer!=word){
            cout<<"wrong!"<<endl
            <<"You type: "<<answer<<endl;    
            sleep_for(seconds(2));
            (*x)-=3; 
        }
        else cout<<"correct!"<<endl;
    return point;
}

void PTTquiz::Treetete(int* a){
    int i,j,point=(*a);
    srand(time(NULL));
    for(i=0;i<point;i++){
        switch(j=rand()%2){
            case 0: std:: cout << R"(
                               :----:.             
                         .:---------------:        
                       .--------------------       
                      :=====================:      
                    :--=======================:    
                   .==========================:    
       .=--+*+:    .++++++++++++++=+++++++++++:    
     .=+********=   ::=++++++++++=.-++++++++-.     
     :**********=      .-==-==-+++::++:=+++=.      
    =***********=:             +++++               
    =*************:            -+++-               
    =**=-++++=-==:             =+++-               
          -=                   +++++               
          :=                  :+++++.              
          -+                 .=+++++=              
__________=*________________.-:..-::--.____________
)" << endl;
break;
            case 1: std::cout<<R"(
            :----:.             
      .:---------------:     
    .--------------------    
   :=====================:   
 :--=======================: 
 :==========================: 
 .++++++++++++++=+++++++++++:      .=--+*+:
  ::=++++++++++=.-++++++++-.     .=+********=
   .-==-==-+++::++:=+++=.        =**********=   
            +++++               =***********=: 
            -+++-               =*************:  
            =+++-               =**=-++++=-==:        
            +++++                     -=            
           :+++++.                    :=        
          .=+++++=                    -+            
________.-:..-::--.___________________=*________
)" << endl;
break;
}
}}