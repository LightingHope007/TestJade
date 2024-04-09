#include <iostream>
#include <cstdlib>//for random
#include <time.h>//for random
#include <cstring>

#include "NODE.h"
#include "Player.h"
#include "LL.h"



using namespace std;

int main(){
    LL LP,LG;
    NODE* t;
    
    int n,i;

    //input player
    cout<<"How many players? "<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        t= new NODE();
        t->getPdata(i);
        LP.add_node(t);
    }
    //select minigame
    cout<<"How many games? "<<endl;
    cin>>n;
    for(i=1;i<=n;i++){
        t= new NODE();
        t->selectgame(i);
        LG.add_node(t);
    }
    
    //run the game

    //สรุปคะแนน
    LP.showscore();
    
    
    return 0;
}
