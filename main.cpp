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

void welcomescreen();

int main(){
    LL LP,LG,test;
    NODE* t;
    
    int n,i;

    welcomescreen();
    
    cin.ignore(10000,'\n');
    cin.clear();
    //cin.get();
    
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

void welcomescreen(){
    cout << "  _    _        _         __      __ _  _  _                      " << endl;
    cout << " | |  | |      | |        \\ \\    / /(_)| || |                     " << endl;
    cout << " | |__| |  ___ | | _ __    \\ \\  / /  _ | || |  __ _   __ _   ___  " << endl;
    cout << " |  __  | / _ \\| || '_ \\    \\ \\/ /  | || || | / _` | / _` | / _ \\ " << endl;
    cout << " | |  | ||  __/| || |_) |    \\  /   | || || || (_| || (_| ||  __/ " << endl;
    cout << " |_|  |_| \\___||_|| .__/      \\/    |_||_||_| \\__,_| \\__, | \\___| " << endl;
    cout << "  _               | |     _                           __/ |        " << endl;
    cout << " | |              |_|    | |                         |___/         " << endl;
    cout << " | |__    ___   __ _   __| | _ __ ___    __ _  _ __                " << endl;
    cout << " | '_ \\  / _ \\ / _` | / _` || '_ ` _ \\  / _` || '_ \\               " << endl;
    cout << " | | | ||  __/| (_| || (_| || | | | | || (_| || | | |              " << endl;
    cout << " |_| |_| \\___| \\__,_| \\__,_||_| |_| |_| \\__,_||_| |_|              " << endl;
    cout << "   _____                        _              _                  " << endl;
    cout << "  / ____|                      | |            | |                 " << endl;
    cout << " | (___    ___   _ __ ___    __| |  ___   ___ | |__               " << endl;
    cout << "  \\___ \\  / _ \\ | '_ ` _ \\  / _` | / _ \\ / __|| '_ \\              " << endl;
    cout << "  ____) || (_) || | | | | || (_| ||  __/| (__ | | | |             " << endl;
    cout << " |_____/  \\___/ |_| |_| |_| \\__,_| \\___| \\___||_| |_|             " << endl;
    cout << "                      _                                            " << endl;
    cout << "                     | |                                           " << endl;
    cout << "  _ __    __ _  _ __ | |_  _   _                                   " << endl;
    cout << " | '_ \\  / _` || '__|| __|| | | |                                  " << endl;
    cout << " | |_) || (_| || |   | |_ | |_| |                                  " << endl;
    cout << " | .__/  \\__,_||_|    \\__| \\__, |                                  " << endl;
    cout << " | |                        __/ |                                  " << endl;
    cout << " |_|                       |___/                                   " << endl;
    cout << "\nPress Enter to continue...                                        " << endl;

}