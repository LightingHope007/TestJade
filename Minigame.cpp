//
#include <iostream>
#include <iomanip>

using namespace std;
#include "Minigame.h"

miniG::miniG(int x){
    num=x;
    cout<<"Minigame created"<<endl;
}

miniG:: ~miniG(){
      cout << "Minigame deleted" << endl;
}

void miniG::selectgame(int a){
      cout<<"Game "<<a<< " : ";
      cin>>num;
      cin.clear();
      cin.ignore(10000,'\n');
}

void miniG::run(int x){
      switch(x){
            case 1:
                  cout<<"game1"<<endl;
                  break;
            case 2:
                  cout<<"game2"<<endl;
                  break;
            case 3:
                  cout<<"game3"<<endl;
                  break;
                  defualt: break;
      }
}






