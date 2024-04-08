//
#include <iostream>
#include <iomanip>

using namespace std;
#include "Minigame.h"

miniG::miniG(int x){
    
    cout<<"Minigame ccreated"<<endl;
}

miniG:: ~miniG(){
      cout << "Minigame deleted" << endl;
}



void miniG::addPoint(int x){
      time+=x;
}

