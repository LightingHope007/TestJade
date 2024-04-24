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
#include "ft_toi.h"

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

void welcomescreen();

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
    string ch;
    int n,i;

    welcomescreen();
    
    cout << "Press Enter to Continue..."<<endl;
    cin.ignore(10000,'\n');
    cin.clear();
    //cin.get();
    
    //input player
    do{ system("clear");
        //Display
        cout<<"+=================+"<<endl;
        cout<<" How many players? "<<endl;
        cout<<"+=================+"<<endl;
        cout<<"Ans : ";
        //input
        getline(cin, ch);
        //check spacebar
        char t;
        int i;
        for(i = 0;i<ch.length();i++){
        if(ch[i] == ' ') break;
        }
        if (ch[i] != ' ' && ch != "") { // ตรวจสอบว่า ch ไม่เป็น Spacebar
            try{
                n = stoi(ch);
            } // ใช้ std::stoi() เพื่อแปลง string เป็น int
            catch(const std::exception&){
                n=-1;
            }
        }
    }while(ch == " " || n <= 0);
    
    for(i=1;i<=round(n);i++){
        t= new Player();
        t->getPdata(i,&LP);
        LP.add_node(t);
    }
    
    //select minigame
    
    do
    {   system("clear");
        cout<<"+=================+"<<endl;
        cout<<"How many games? "<<endl;
        cout<<"+=================+"<<endl;
        cout<<"Ans : ";
        getline(cin, ch);
        //check spacebar
        char t;
        int i;
        for(i = 0;i<ch.length();i++){
        if(ch[i] == ' ') break;
        }
        if (ch[i] != ' ' && ch != "") { // ตรวจสอบว่า ch ไม่เป็น Spacebar
            try{n = stoi(ch);} // ใช้ std::stoi() เพื่อแปลง string เป็น int
            catch(const std::exception&){
                n=-1;
            }
        }
    }while(ch == " " || n <= 0);
    
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
    cout<< "  _    _        _            " << endl
    << " | |  | |      | |           " << endl
    << " | |__| |  ___ | | _ __      " << endl
    << " |  __  | / _ \\| || '_ \\     " << endl
    << " | |  | ||  __/| || |_) |     " << endl
    << " |_|  |_| \\___||_|| .__/       " << endl
    << "   __    __       | |"<<endl
    << "  /  \\  /  \\      |_|"<<endl
    << " | || || || |  __ _  _    _   ___   _ __"<<endl
    << " | || || || | / _` || |  | | / _ \\ | '__|"<<endl
    << " | || || || || (_| || |__| || (_) || |"<<endl
    << " |_| \\__/ |_| \\__,_| \\__,  | \\___/ |_|"<<endl
    << "   _____               __/ |    _              _ "<<endl
    << "  / ____|             |___/    | |            | |                 " << endl
    << " | (___    ___   _ __ ___    __| |  ___   ___ | |__               " << endl
    << "  \\___ \\  / _ \\ | '_ ` _ \\  / _` | / _ \\ / __|| '_ \\              " << endl
    << "  ____) || (_) || | | | | || (_| ||  __/| (__ | | | |             " << endl
    << " |_____/  \\___/ |_| |_| |_| \\__,_| \\___| \\___||_| |_|             " << endl
    << "  _ ___               _                _                           " << endl
    << " | '_  \\             | |              | |                          " << endl
    << " | |_)  | __ _  _ __ | |_  _   _      | |                          " << endl
    << " | .___/ / _` || '__|| __|| | | |     | |                          " << endl
    << " | |    | (_| || |   | |_ | |_| |     | |                            " << endl
    << " |_|     \\__,_||_|    \\__| \\__, |     |_|                            " << endl
    << "                            __/ |      _                            " << endl
    << "                           |___/      |_|                           " << endl;
    
}
