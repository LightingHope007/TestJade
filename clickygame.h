#ifndef clickygame_h
#define clickygame_h

#include <iostream>
#include <chrono>//for timer system
#include <string>

using namespace std;
using namespace chrono;

void displayTrashCan(int);
int score_system(int);

int clickygame(){
    const int targetPresses = 200;//target to press. default 200
    
    cout << "Press a and d " << targetPresses << " to pick up a trash!!!\n";
    cout << "Press Enter to start...\n";
    //cin.ignore(); // Wait for user to press Enter
    //cin.ignore(10000,'\n');
    while (cin.get() != '\n'); // Wait for the user to press Enter

    auto start = steady_clock::now();//start timer 
    int pressed = 0;
    char pick = '\0';
    char prevpick = '\0';

    while(pressed < targetPresses){
        displayTrashCan(pressed/2);
        cout << "Presses: " << pressed << "/" << targetPresses << endl;
        cout << "Use your muscles!!(press enter to dump the trash...) " << endl;
        //cin >> pick;
        pick = cin.get();
        if ((pick == 'a' && prevpick != 'a') || (pick == 'd' && prevpick != 'd')){
            prevpick = pick;
            pressed++;
            
        }
        system("clear");      
    }
    //Clear input
    cin.ignore(10000,'\n');
    
    auto end = steady_clock::now();//end timer
    duration<double> elapsed_seconds = end - start;
    cout << "time use: " << elapsed_seconds.count() << endl;
    
    int time = static_cast<int>(elapsed_seconds.count());
    int score = score_system(time);

    cout<<"     +---------+"<<endl;
    cout<<"     |Point : "<<score<<"|"<<endl;
    cout<<"     +---------+"<<endl;
    cout << "Press Enter to Continue";
    //cin.clear();
    cin.ignore(10000,'\n');
    cin.clear();
    return score;  
}

void displayTrashCan(int x){//input is 1 to 100
    int i;
    int fillrow = x / 20;
    int fillother = x % 20;
    // ASCII art for trash can
    cout << "  __________________" << endl;
    cout << " /                  \\" << endl;

    //Display empty row first
    for(i = 0; i < 5 - fillrow - (fillother > 0 ? 1 : 0); i++){
        cout << "|                    |" << endl;
    }

    //Display partially filled row if necessary
    if (fillother > 0) {
        cout << "|";
        for (int i = 0; i < fillother; i++) {
            cout << "#";
        }
        for (int i = 0; i < 20 - fillother; i++) {
            cout << " ";
        }
        cout << "|" << endl;
    }

    //Display fill row
    for(i = 0; i < fillrow; i++){
        cout << "|####################|" << endl;
    }
    
    cout << "|____________________|" << endl;
}

int score_system(int x){
    if (x <= 30)
        return 10;
    else if (x >= 40)
        return 0;
    else
        return (10 - (x - 30))*7;
}

#endif
