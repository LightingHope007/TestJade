#include <iostream>
#include <cstdlib>//for random
#include <time.h>//for random
#include <cstring>
#include <exception>

#include "NODE.h"
#include "Player.h"
#include "LL.h"



using namespace std;

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
    LL LP,LG;
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
            if(cin.fail())
            {
                system("clear");
                checkstr();
            }  
            else{
            cout<<"-------------------"<<endl;  
            break;
            }  
               
        }
        catch(exception &e )
                {
                    cerr<<e.what()<<endl; 
                    
                }
    }
      
    
    for(i=1;i<=n;i++){
        t= new NODE();
        t->getPdata(i);
        LP.add_node(t);
    }
    //select minigame
    system("clear");
    cout<<"How many games? "<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        t= new NODE();
        t->selectgame(i);
        LG.add_node(t);
    }
    
    //run the game
    LG.run(LP.head());


    //สรุปคะแนน
    system("clear");
    LP.showscore();
    
    
    return 0;
}
