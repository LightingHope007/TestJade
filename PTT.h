#ifndef PTT_h
#define PTT_h

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include <fstream>

#include "PTT_class.h"
#include "LL.h"

using namespace std;
//run the game
int PTT(){
    string myText;
    LL wordL;
    NODE* t;
    int score=0;
    double time=90;

    // Read from the text file
    ifstream pool("PTT_pool.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (pool, myText)) {
    // Output the text from the file
        t= new PTTquiz();
        t->Tgetdata(myText);
        wordL.add_node(t);
    }

    wordL.PTTrun(&score,&time);

    cout<<"     +---------+"<<endl;
    cout<<"     |Point : "<<score<<"|"<<endl;
    cout<<"     +---------+"<<endl;
    cout << "Press Enter to Continue";
    cin.clear();
    cin.ignore(10000,'\n');

    // Close the file
    pool.close();
    return score;
}

#endif