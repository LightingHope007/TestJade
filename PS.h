#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cmath>
#include <cstring>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

#include <cstdlib>
#include <ctime>

using namespace std;
using namespace chrono;

int Check_Ans(char[], string, int);
string GenQuestion(char[], int*);
//run
int PS()
{
    srand(time(nullptr));
    char asciiChars[20];
    int point = 0, ex, mod;
    double time=30;

    while (time>0)
    {
        cout<<endl<<"||==||==||==||==||==||==||==||"<<endl;
        for(int i =0;i<point;i++){
            cout<<"....v";
            if(i%5==0&&i!=0)cout<<"...."<<endl<<endl;
        }
        cout<<endl<<"||==||==||==||==||==||==||==||"<<endl;
        GenQuestion(asciiChars,&ex);
        switch(ex){
            case 17: mod=1; break;
            case 15: mod=2; break;
            case 13: mod=3; break;
            defualt: break;
        }
        cout<<"    ";
        for(int line = -1; line <=ex;line++)
        {
            if(line == -1 || line == ex) 
            {
                cout<<"+";
                if(line == ex)
                {
                    cout<<endl;
                }
            }
            if(line != ex) cout<<"-";
        }
        cout << "     ";
        for (int i = 0; i < ex; i++)
        {   
            cout << asciiChars[i];
        }
        cout<<endl;
        cout<<"    ";
        for(int line = -1; line <=ex;line++)
        {
            if(line == -1 || line == ex) 
            {
                cout<<"+";
                if(line == ex)
                {
                    cout<<endl;
                }
            }
            if(line != ex)cout<<"-";
        }
        cout<<endl;
        cout << "Ans: ";

        auto start = steady_clock::now();
        string answerIn;
        getline(cin, answerIn);

        auto end = steady_clock::now();
        duration<double> elapsed_seconds = end - start;
        system("clear");

        if (Check_Ans(asciiChars, answerIn , ex) == 0)
        {
            cout << "Correct" << endl;
            if (elapsed_seconds.count() < 15)
            {
                point+=mod;
            }
        }
        else
        {
            cout << "Incorrect" << endl;
        }

        if (elapsed_seconds.count() > 15)
        {
            cout << "Too Late" << endl;
        }
        //cout << "Your Time is " << setw(3) << elapsed_seconds.count() << " seconds" << endl;
        cout<<"============================"<<endl;
        time-=elapsed_seconds.count();
    }
    cout<<"     +---------+"<<endl;
    cout<<"     |Point : "<<point<<"|"<<endl;
    cout<<"     +---------+"<<endl;
    cout << "Press Enter to Continue";
    cin.clear();
    cin.ignore(10000,'\n');

    return point;
}
//check correction
int Check_Ans(char correctAns[], string userAns, int c)
{
    if(userAns.length() > c) return 1;
    for (int n = 0; n < c; n++)
    {
        if (correctAns[n] != userAns[n])
        {
            return 1;
        }
    }
    return 0; 
}
//generate stage
string GenQuestion(char question[], int* a){
    int k,j;
    char* t=question;
    srand(time(NULL));
    switch(rand()%3){
        case 0: j=17; k=4; break;
        case 1: j=13; k=3; break;
        case 2: j=15; k=2; break;
        default: break;
    }


    for (int i = 0; i < j; i += k)
            {
                switch (rand() % 2)
                {
                case 0:
                    question[i] = static_cast<char>((rand() % 26) + 65); 
                    break;
                case 1:
                    question[i] = static_cast<char>((rand() % 26) + 97); 
                    break;
                default:
                    break;
                }
                for (int n = i + 1; n < (i + 4); n++)
                {
                    question[n] = ' ';
                }
            }
            (*a)=j;
            return question;
}