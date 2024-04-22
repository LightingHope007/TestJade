#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Player.h"

Player::Player(int x,string y){
    point=x;
    name=y;
}

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

void Player::addPoint(int x){
    point+=x;
    
}

int Player::getPoint(){
    return point;
}

string Player::getname(){
    return name;
}
