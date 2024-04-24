#ifndef TEXT_h
#define TEXT_h

#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>
#include <cmath>

using namespace std;



void mathintro(){
    cout
    <<"Kids in the village lacked basic education!"<<endl
    <<"Therefore, Mr. Somdech wanted to improve students' basic math."<<endl
    <<"Help them by demonstrate your math skill! (basic calculation)"<<endl
    <<"--------------------------------------------------------------"<<endl;
    cout << "Press Enter to Continue..."<<endl;
    cin.ignore(10000,'\n');
    cin.clear();
}

void Plantseedintro(){
    cout
    <<"The village are having poverty trouble for a long time!"<<endl
    <<"Mr. Somdech asked you to teach them argriculture with demonstration."<<endl
    <<"You must teach them to plant the seed with precision and accurate spacing or the plant will die!"<<endl
    <<"------------------------------------------------------------------------------------------------"<<endl;
    cout << "Press Enter to Continue..."<<endl;
    cin.ignore(10000,'\n');
    cin.clear();
}

void Planttreeintro(){
    cout<<"The village frequently encountered with flood due to the lack of tree to hold the soil and slow down the water current"<<endl;
    cout<<"we really have no idea how to deal with it pleas help us!!"<<endl;
}

void Picktrashintro(){
    
}

void Buildschoolintro(){
    cout 
    <<"Mr. Somdech"
    << "Quickly! you need to push these log to build a school!!!"<<endl
    << "When a random character aprear, input a character random times"<<endl;
}


#endif