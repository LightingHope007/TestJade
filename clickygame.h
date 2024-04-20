#ifndef clickygame_h
#define clickygame_h

#include <iostream>
#include <chrono>//for timer system
#include <string>

using namespace std;

int clickygame(){
    const int targetPresses = 100;//target to press.
    
    cout << "Press a and d " << targetPresses << " to pick up a trash!!!\n";
    cout << "Press Enter to start...\n";
    cin.ignore(); // Wait for user to press Enter
    cin.ignore(10000,'\n');

    auto start = std::chrono::steady_clock::now();//start timer 
    int pressed = 0;
    char pick = '\0';
    char prevpick = '\0';
    int i;

    while(pressed < targetPresses){
        displayTrashCan(pressed/2);
        cout << "Presses: " << pressed << "/" << targetPresses << endl;
        cout << "Use your muscles!!(press enter to dump the trash...) " << endl;
        cin >> pick;
        if ((pick == 'a' && prevpick != 'a') || (pick == 'd' && prevpick != 'd')){
            prevpick = pick;
            pressed++;    
        }
        system("clear");      
    }
    
    auto end = std::chrono::steady_clock::now();//end timer
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "time use: " << elapsed_seconds.count() << endl;
    
    int time = static_cast<int>(elapsed_seconds.count());
    int score = score_system(time);
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
    if (x <= 20)
        return 10;
    else if (x >= 40)
        return 0;
    else
        return 10 - (x - 20) / 2;
}

#endif
