#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Player.h"
#include "LL.h"

Player::Player(int x,string y){
    point=x;
    name=y;
}

void Player::getPdata(int a,LL* b){
    string inName;

    do{
        system("clear");
        cout<<"Player "<<a<< " name: ";
        cin>>inName;
        cin.clear();
        cin.ignore(10000,'\n');
    }while(b->checkname(inName,b->head())==0);
    name=inName;
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
