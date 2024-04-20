//
#include <iostream>
#include <iomanip>

using namespace std;
#include "Minigame.h"
#include "Math.h"
#include "PS.h"
#include "PTT.h"
#include "clickygame.h"

miniG::miniG(int x){
    num=x;
    //cout<<"Minigame created"<<endl;
}

miniG:: ~miniG(){
      //cout << "Minigame deleted" << endl;
}

void miniG::selectgame(int a){
      cout<<"Choose minigame"<<a<< " : "<<endl
      <<"1.Math\n" << "2.Plant the seed\n" << "3.Plant the Tree\n" << "4.Pick up the trash\n" << "5.Random"<< endl;
      cin>>num;
      cin.clear();
      cin.ignore(10000,'\n');
      cout<<num<<endl;
}

int miniG::run(int x){
      srand(time(NULL));
      int p=0,g=x;
      if(g==5) g=rand()%4+1;
      switch(g){
            case 1:
                  cout<<"game1"<<endl;
                  p=Math_G();
                  break;
            case 2:
                  cout<<"game2"<<endl;
                  p=PS();
                  break;
            case 3:
                  cout<<"game3"<<endl;
                  p=PTT();
                  break;
            case 4:
                  cout << "game4" << endl;
                  p = clickygame();
                  break;
            defualt: break;
      }

      return p;
}

int miniG::show_num(){
      return num;
}
