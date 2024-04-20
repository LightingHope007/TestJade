#ifndef quicktime_h
#define quicktime_h

#include <iostream>
#include <ctime>//for random character
#include <cstdlib>//for random character
#include <chrono>//for timer system

using namespace std;

char randchar();
int randnum(int min, int max);
int score_quicktime(int);

int quicktime(){
    srand(time(0)); // Seed the random number generator

    cout << "Quickly! you need to push these log to build a school!!!\n";
    cout << "when a random character aprear, input a character randnom times\n";
    cout << "Press Enter to start...\n";
    while (cin.get() != '\n');

    auto start = std::chrono::steady_clock::now();//start timer
    int i;
    char rchar; // Generate a random character
    int rinput;// Generate a random number
    char pick = '\0';
    int pressed = 0;
    

    for(i = 0; i < 10; i++){
        rchar = randchar(); // Generate a random character
        rinput = randnum(10, 20); // Generate a random number between 10 - 20
        pressed = 0;
        pick = '\0';

        while(pressed < rinput){
            system("clear"); 
            cout << "Here's the character: " << rchar << endl;
            cout << "Presses: " << pressed << "/" << rinput << endl;
            cout << "Use your muscles!!(press enter see a result!!!) " << endl;

            pick = cin.get();
            if (pick == rchar){
                pressed++;
            }
        }
    }

    auto end = std::chrono::steady_clock::now();//end timer
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "time use: " << elapsed_seconds.count() << endl;

    int time = static_cast<int>(elapsed_seconds.count());
    int score = score_quicktime(time);
    cout << "Press Enter to Continue";
    cin.ignore(); //Clear input
    cin.ignore(10000,'\n');
    return score; 
}


char randchar(){
    // Generate a random character between 'a' and 'z'
    char rchar = 'a' + rand() % 26;
    return rchar;
}

int randnum(int min, int max){
    return min + rand()%(max - min + 1);
}

int score_quicktime(int x){
    if (x <= 36)
        return 10;
    else if (x >= 46)
        return 0;
    else
        return 10 - (x - 36);
}

#endif