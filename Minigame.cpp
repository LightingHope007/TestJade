//
#include <iostream>
#include <iomanip>

using namespace std;
#include "Minigame.h"
#include "Math.h"
#include "PS.h"

miniG::miniG(int x){
    num=x;
    //cout<<"Minigame created"<<endl;
}

miniG:: ~miniG(){
      //cout << "Minigame deleted" << endl;
}

void miniG::selectgame(int a){
      cout<<"Choose minigame"<<a<< " : "<<endl
      <<"1.Math"<<endl<<"2.Plant the seed"<<endl<<"3.WIP"<<endl<<"4.Random"<<endl;
      cin>>num;
      cin.clear();
      cin.ignore(10000,'\n');
      cout<<num<<endl;
}

int miniG::run(int x){
      srand(time(NULL));
      int p=0,g=x;
      if(g==4) g=rand()%3+1;
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
                  break;
            defualt: break;
      }

      return p;
}

int miniG::show_num(){
      return num;
}






