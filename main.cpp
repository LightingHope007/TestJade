#include <iostream>
#include <cstdlib>//for random
#include <time.h>//for random
#include <cstring>
#include <exception>
#include <chrono>
#include <thread>
#include <cmath>

#include "Player.h"
#include "Minigame.h"
#include "LL.h"



using namespace std;
using namespace this_thread; // sleep_for, sleep_until
using namespace chrono; // nanoseconds, system_clock, seconds

class myexception: public exception
{
	public:
	const char* what() const throw()
	{
		return "Try Again";
	}
};

void checkstr()
{
	cin.clear();
	cin.ignore(10000,'\n');
	myexception myex;
	throw myex;
}

int main(){
    LL LP,LG,test;
    NODE* t;
    
    int n,i;

    //input player
    system("clear");
    while(1)
    {
        try{
            cout<<"+=================+"<<endl;
            cout<<" How many players? "<<endl;
            cout<<"+=================+"<<endl;
            cout<<"Ans : ";
            cin>>n;
            n=round(n);
            if(cin.fail()||n<1)
            {
                checkstr();
            }  
            cout<<"-------------------"<<endl;   
            break; 
        }
        catch(exception &e )
                {
                    cerr<<e.what()<<endl; 
                    
                }
    }
      
    
    for(i=1;i<=round(n);i++){
        t= new Player();
        t->getPdata(i);
        LP.add_node(t);
    }
    
    //select minigame
    system("clear");
    while(1)
    {
        try{
            cout<<"+=================+"<<endl;
            cout<<"How many games? "<<endl;
            cout<<"+=================+"<<endl;
            cout<<"Ans : ";
            cin>>n;
            if(cin.fail()||n<1)
            {
                checkstr();
            }
            cout<<"-------------------"<<endl; 
            break;   
               
        }
        catch(exception &e )
                {
                    cerr<<e.what()<<endl; 
                    
                }
    }

    for(i=1;i<=n;i++){
        t= new miniG();
        t->selectgame(i);
        LG.add_node(t);
    }
    
    //run the game
    LG.run(LP.head());
    

    //สรุปคะแนน
    system("clear");
    LP.SortnShow(LP.head());
    
    
    return 0;
}