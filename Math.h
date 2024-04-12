#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cmath>

using namespace std;

int mod;

double Decimal(double num) 
    {
    return round(num * 100) / 100;
    }
double DisplayQuestion(){
    srand(time(NULL));
    double a[2];
    double ans;
    //rand size
    for(int i=0;i<2;i++)
        {
            switch(rand()%6)
            {
              case 0:
                   a[i] = (rand()%20)+1; break;
              case 1:
                   a[i] = (rand()%20)+10; break;
              case 2:
                   a[i] = (rand()%20)+20; break;
              case 3:
                   a[i] = (rand()%20)+30; mod++; break;
              case 4:
                   a[i] = (rand()%20)+40; mod++; break;
              case 5:
                   a[i] = (rand()%20)+50; mod+=2; break;
              default: break;
                   
            }
        }
        //rand operator
    switch(rand()%4)
        {
        case 0 :
            ans = a[0] + a[1];
            cout<<a[0]<<" + "<<a[1]<<" = ";
            break;
        case 1 :
            ans = a[0] - a[1];
            cout<<a[0]<<" - "<<a[1]<<" = ";
            break;
        case 2 :
            ans = a[0] * (int(a[1])%12+1);
            cout<<a[0]<<" x "<<int(a[1])%12+1<<" = ";
            mod++;
            break;
        case 3 :
            ans = a[0] / (int(a[1])%12+1);
            ans = round(ans);
            cout<<ans*(int(a[1])%12+1)<<" / "<<int(a[1])%12+1<<" = ";
            mod++;
            break;
        }
        
    return ans;
}
int Math_G() {
    
    int point = 0;
    int count = 0 ;
    while(count != 3)
    {
        mod=1;//set modifier
        //count time
        auto start = std::chrono::steady_clock::now();
        //add-on display 
        cout<<"================"<<endl<<"Question "<<count+1<<endl;
        //
        double ans = DisplayQuestion();//show question

        double answerIn;
        std::cin>>answerIn;
        cin.clear();
        cin.ignore(10000,'\n');

        auto end = std::chrono::steady_clock::now(); 
        std::chrono::duration<double> elapsed_seconds = end - start;
        system("clear");
        if(answerIn == ans)//funtion return
        {
            std::cout<<"Correct!"<<std::endl;
            if(elapsed_seconds.count()<10)
            { 
              point+=mod;  
            }
            
            
        }   
        else
        {
         std::cout<<"Incorrect!"<<std::endl; 
        }
    
    if(elapsed_seconds.count()>10)
    {
        std::cout << "Too Late" << std::endl;
        point--;
    } 
    std::cout <<"Your time is "<<std::setw(3)<< elapsed_seconds.count() << std::endl;
      
      count++;
    }

    if(point<0)point=0;
    cout<<"Point : "<<point<<endl;
    cout << "Press Enter to Continue";
    cin.ignore();

    return point;
    
    
}
