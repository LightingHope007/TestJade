#ifndef PTT_h
#define PTT_h

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include <fstream>

#include "NODE.h"
#include "LL.h"

using namespace std;

int PTT(){
    string myText;
    LL wordL;
    NODE* t;
    int score;
    double time=60;

    // Read from the text file
    ifstream pool("PTT_pool.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (pool, myText)) {
    // Output the text from the file
        t= new NODE();
        t->Tgetdata(myText);
        wordL.add_node(t);
    }

    wordL.PTTrun(&score,&time);

    cout<<"     +---------+"<<endl;
    cout<<"     |Point : "<<score<<"|"<<endl;
    cout<<"     +---------+"<<endl;
    cout << "Press Enter to Continue";
    cin.ignore();

    // Close the file
    pool.close();
    return score;
}

#endif