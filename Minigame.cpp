//
#include <iostream>
#include <iomanip>

using namespace std;
#include "Minigame.h"
#include "Math.h"
#include "PS.h"
#include "PTT.h"
#include "clickygame.h"
#include "quicktime.h"
#include "TEXT.h"


miniG::miniG(int x){
    num=x;
    //cout<<"Minigame created"<<endl;
}

miniG:: ~miniG(){
      //cout << "Minigame deleted" << endl;
}

void miniG::selectgame(int a){
      string ans;
      int s;
      ran=0;
      do
     {
            cout << "Choose minigame" << a << " : "<< endl;
            cout << "1.Math"<<endl
             << "2.Plant the seed"<<endl
             << "3.Plant the Tree"<<endl
             << "4.Pick up the trash"<<endl
             << "5.Build a school"<<endl
             << "6.Random\n" << endl
             << "Enter the number! :";

        getline(std::cin, ans);
        
        s = Check_ans(ans);
        
    } while (ans == " "  || s == 1);
    if(ans[0]=='6') ran = rand()% 5 + 1;
    num=stoi(ans);
}

int miniG::run(int x){
      srand(time(NULL));
      int p = 0; 
      if(x == 6) x=ran;
      switch(x){
            case 1:
                  mathintro();
                  p = Math_G();
                  break;
            case 2:
                  cout << "game2" << endl;
                  p = PS();
                  break;
            case 3:
                  cout << "game3" << endl;
                  p = PTT();
                  break;
            case 4:
                  cout << "game4" << endl;
                  p = clickygame();
                  break;
            case 5:
                  cout << "game 5" << endl;
                  p = quicktime();
                  break;
            defualt: break;
      }
      return p;
}

int miniG::show_num(){
      return num;
}

int miniG::Check_ans(string Ans)
{
    int n;
    string a = "s";
    string b;
    if(Ans.length() > a.length()) return 1;

    if(Ans.length() == a.length())
    {
        
      if(Ans[0] == '1') return 0;
      else if(Ans[0] == '2') return 0;
      else if(Ans[0] == '3') return 0;
      else if(Ans[0] == '4') return 0;
      else if(Ans[0] == '5') return 0;
      else if(Ans[0] == '6') return 0;
      else
      {
        return 1;
      }
    }

    for (int n = 0; n < Ans.length() ; n++)
    {
        if (' ' == Ans[n] )
        {
            return 1;
        }
    }
    return 0; 
}
