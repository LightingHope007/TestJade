#ifndef PlantTheTree_h
#define PlantTheTree_h

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>
#include <fstream>

#include "NODE.h"
#include "LL.h"
#include "PTT_class.h"

using namespace std;

int PTT(){
    string myText;
    LL wordL;
    NODE* t;
    int score;


    // Read from the text file
    ifstream pool("PTT_pool.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (pool, myText)) {
    // Output the text from the file
        t= new NODE();
        t->Tgetdata(myText);
        wordL.add_node(t);
    }

    wordL.PTTrun(score,5);

    cout<<score<<endl;
    cout << "Press Enter to Continue";
    cin.ignore();

    // Close the file
    pool.close();
    return score;
}

#endif