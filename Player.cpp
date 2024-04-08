#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Player.h"



void Player::getPdata(int a){
    cout<<"Player "<<a<< " name: ";
    cin>>name;
    cin.clear();
    cin.ignore(10000,'\n');
    point =0;
}

void Player::show_point(){
    cout<<setw(-20)<<name<<setw(5)<<point<<endl;
}
