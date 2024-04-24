#ifndef quicktime_h
#define quicktime_h

#include <iostream>
#include <ctime>//for random character
#include <cstdlib>//for random character
#include <chrono>//for timer system

using namespace std;
using namespace chrono;

char randchar();
int randnum(int, int);
int score_quicktime(int);
void schoolart(int);

int quicktime(){
    srand(time(0)); // Seed the random number generator

    cout << "Quickly! you need to push these log to build a school!!!\n";
    cout << "when a random character aprear, input a character random times\n";
    cout << "Press Enter to start...\n";
    while (cin.get() != '\n');

    auto start = steady_clock::now();//start timer
    int i;
    char rchar; // Generate a random character
    int rinput;// Generate a random number
    char pick = '\0';
    int pressed = 0;
    

    for(i = 0; i < 10; i++){//default 10 round
        rchar = randchar(); // Generate a random character
        rinput = randnum(10, 20); // Generate a random number between 10 - 20
        pressed = 0;
        pick = '\0';
        system("clear"); 
        while(pressed < rinput){
            schoolart(i);
            cout << "Here's the character: " << rchar << endl;
            cout << "Presses: " << pressed << "/" << rinput << endl;
            cout << "Use your muscles!!(press enter see a result!!!) " << endl;

            pick = cin.get();
            if (pick == rchar){
                pressed++;
            }
            system("clear"); 
        }
    }
    
    schoolart(10);
    cout << "School is finished!!!" << endl;

    auto end = steady_clock::now();//end timer
    duration<double> elapsed_seconds = end - start;
    cout << "time use: " << elapsed_seconds.count() << endl;
    cin.clear();
    cin.ignore(10000,'\n');
    int time = static_cast<int>(elapsed_seconds.count());
    int score = score_quicktime(time);

    cout<<"     +---------+"<<endl;
    cout<<"     |Point : "<<score<<" |"<<endl;
    cout<<"     +---------+"<<endl;
    cout << "Press Enter to Continue";
    cin.ignore(10000,'\n');
    cin.clear();

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
        return 70;
    else if (x >= 46)
        return 0;
    else
        return (10 - (x - 36))*7;
}

void schoolart(int i){
    if(i >= 10){
        cout << "                                            ##                                            " << endl;
        cout << "                                            ##+++++++++++=:                               " << endl;
        cout << "                                            ############*:                                " << endl;
        cout << "                                            ############+                                 " << endl;
        cout << "                                            #############+.                               " << endl;
        cout << "                                            %%............                                " << endl;
        cout << "                                            %%                                            " << endl;
        cout << "                                           -##-.                                          " << endl;
    }
    if(i >= 9){
        cout << "                                        :+######+-                                        " << endl;
        cout << "                                     :=*##*=-:=*##*=:                                     " << endl;
        cout << "       .++++++++++++++++++++++++++++*##*+-::::::-=*##*++++++++++++++++++++++++++++:       " << endl;
    }
    if(i >= 8){
        cout << "      -##############################*=::-::...:-::-+##############################+      " << endl;
        cout << "     +############################*=::::-   .:   -::::=*############################*.    " << endl;
        cout << "   :*##########################*+-::::::-   .-   :-::::::=*###########################-   " << endl;
    }
    if(i >= 7){
        cout << "::-----------------------------::::--------------------:::::----------------------------::" << endl;
        cout << "  =###########################*:::::::::-:  .-  :-:::::::::+###########################+  " << endl;
        cout << ".+############################*:::::::::::-::::-:::::::::::+############################*." << endl;

    }
    if(i >= 6){
        cout << "   ----------------------------:::::.=-:---.--------..:-:::----------------------------.  " << endl;
        cout << "   ======::::::.======:::::::=-::::: =+---=-+=:==:+=: .-:::-==::::::.======.::::::=====.  " << endl;
        cout << "   ======.--:-- =====-.--:-::=-:::--..:.:.....:..:..:.:-:::-==.--:--.====== --:-:.=====.  " << endl;

    }
    if(i >= 5){
        cout << "   ======.:::-- =====-.:::-::=-::::::::::::::::::::::::::::-==.:::--.====== -::--.=====.  " << endl;
        cout << "   ======.::.:- =====-.:-.:::=-::::::::::::::::::::::::::::-==.::::-.====== :-.::.=====.  " << endl;
        cout << "   ======-:::::-=====-::::::-=-::::::::::::::::::::::::::::-==-:::::-======-:::::-=====.  " << endl;
    }
    if(i >= 4){
        cout << "   ===========================-::::::::::::::::::::::::::::-===========================.  " << endl;
        cout << "   ======.::.::.======.::::::=-::::::================::::::-==::::::.======.::.:::=====.  " << endl;
        cout << "   ======.--:-- =====-.--:-::=-::::::*=====-+*======*-:::::-==.--:--.====== --:--.=====.  " << endl;
    }
    if(i >= 3){
        cout << "   ======.-::-- =====-.-::-::=-::::::*=-----+*=----=*-:::::-==.:::--.====== -::--.=====.  " << endl;
        cout << "   ======.::.:: =====- ::.:.:=-::::::*=-----+*=----=*-:::::-==.::.:: ====== ::.::.=====.  " << endl;
        cout << "   ======-------======-------=-::::::*=-----+*-----=*-:::::-==-------======-------=====.  " << endl;
    }
    if(i >= 2){
        cout << "   ======-------======------==-::::::*=----:+*:----=*-:::::-===------======------======.  " << endl;
        cout << "   ======.-:.-: =====-.-::-::=-::::::*=-----+*-----=*-:::::-==.:::-: ====== -::-:.=====.  " << endl;
        cout << "   ======.:::-- =====-.:::-::=-::::::*=-----+*-----=*-:::::-==.:::--.====== :::--.=====.  " << endl;
    }
    if(i >= 1){
        cout << "   ======.--:-- =====-.--:-::=-::::::*=-----+*-----=*-:::::-==.--:--.====== --:--.=====.  " << endl;
        cout << "   ======...... =====- ......=-::::::*=-----+*=----=*-:::::-==...... ====== ......=====.  " << endl;
        cout << "   ===========================-::::::++=====+++====++-:::::-===========================.  " << endl;
    }
    if(i >= 0){
        cout << "  :++++++++++++++++++++++++++++===-.                   :-==++++++++++++++++++++++++++++-  " << endl;
        cout << "  -*****************************+=:::::::::::::::::::::::=+****************************=  " << endl;
    }
}

#endif





    

    