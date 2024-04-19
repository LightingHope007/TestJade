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

int Check_Ans(char[], string, int);

int PS()
{
    srand(time(nullptr));
    char asciiChars[20];
    int point = 0, ex;

    for (int j = 0; j < 3; j++)
    {
        if (j == 0)
        {
            for (int i = 0; i < 17; i += 4)
            {
                switch (rand() % 2)
                {
                case 0:
                    asciiChars[i] = static_cast<char>((rand() % 26) + 65); 
                case 1:
                    asciiChars[i] = static_cast<char>((rand() % 26) + 97); 
                    break;
                default:
                    break;
                }
                for (int n = i + 1; n < (i + 4); n++)
                {
                    asciiChars[n] = ' ';
                }
            }
            ex = 17;
        }
        else if (j == 1)
        {
            for (int i = 0; i < 13; i += 3)
            {
                switch (rand() % 2)
                {
                case 0:
                    asciiChars[i] = static_cast<char>((rand() % 26) + 65);
                    break;
                case 1:
                    asciiChars[i] = static_cast<char>((rand() % 26) + 97); 
                    break;
                default:
                    break;
                }
                for (int n = i + 1; n < (i + 3); n++)
                {
                    asciiChars[n] = ' ';
                }
            }
            ex = 13;
        }
        else
        {
            for (int i = 0; i < 15; i += 2)
            {
                switch (rand() % 2)
                {
                case 0:
                    asciiChars[i] = static_cast<char>((rand() % 26) + 65); 
                    break;
                case 1:
                    asciiChars[i] = static_cast<char>((rand() % 26) + 97); 
                    break;
                default:
                    break;
                }
                for (int n = i + 1; n < (i + 2); n++)
                {
                    asciiChars[n] = ' ';
                }
            }
            ex = 15;
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

        auto start = std::chrono::steady_clock::now();
        string answerIn;
        std::getline(std::cin, answerIn);

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (Check_Ans(asciiChars, answerIn , ex) == 0)
        {
            std::cout << "Correct" << std::endl;
            if (elapsed_seconds.count() < 15)
            {
                point++;
            }
        }
        else
        {
            std::cout << "Incorrect" << std::endl;
        }

        if (elapsed_seconds.count() > 15)
        {
            std::cout << "Too Late" << std::endl;
        }
        std::cout << "Your Time is " << std::setw(3) << elapsed_seconds.count() << " seconds" << std::endl;
        cout<<"============================"<<endl;
    }
    cout<<"     +---------+"<<endl;
    cout<<"     |Point : "<<point<<"|"<<endl;
    cout<<"     +---------+"<<endl;
    cout << "Press Enter to Continue";
    cin.ignore();

    return point;
}


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