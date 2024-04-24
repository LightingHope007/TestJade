#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cmath>

using namespace std;
using namespace chrono;

int mod,ani;
int Check_Ans(string, string);
void art();

double Decimal(double num) 
    {
    return round(num * 100) / 100;
    }
double DisplayQuestion(){ //Make question
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
                   a[i] = (rand()%20)+50; mod++; break;
              default: break;
                   
            }
        }
        //rand operator
    switch(rand()%4)
        {
        case 0 :
            ans = a[0] + a[1];
            cout<<"================"<<endl;
            cout<<a[0]<<" + "<<a[1]<<" = ";
            break;
        case 1 :
            ans = a[0] - a[1];
            cout<<"================"<<endl;
            cout<<a[0]<<" - "<<a[1]<<" = ";
            break;
        case 2 :
            ans = a[0] * (int(a[1])%12+1);
            cout<<"================"<<endl;
            cout<<a[0]<<" x "<<int(a[1])%12+1<<" = ";
            break;
        case 3 :
            ans = a[0] / (int(a[1])%12+1);
            ans = round(ans);
            cout<<"================"<<endl;
            cout<<ans*(int(a[1])%12+1)<<" / "<<int(a[1])%12+1<<" = ";
            break;
        }
        
    return ans;
}
//run
int Math_G() { 
    
    int point = 0;
    int count = 0 ;
    double time=30;
    while(time>0)
    {
        count++;
        mod=1;//set modifier
        //count time
        auto start = steady_clock::now();
        //add-on display 
        art();
        //
        cout<<"================"<<endl<<"Question "<<count<<endl;
        //
        int ans = DisplayQuestion();//show question
        string numtostr = to_string(ans);
        string answerIn;
        getline(cin, answerIn);
        
        auto end = steady_clock::now(); 
        duration<double> elapsed_seconds = end - start;

        system("clear");

        if(Check_Ans(numtostr, answerIn) == 0)//funtion return
        {
            cout<<"Correct! Get "<<mod<<" points"<<endl;
            if(elapsed_seconds.count()<10)
            { 
              point+=mod;  
            }
            
            
        }   
        else
        {
         cout<<"Incorrect!"<<endl; 
        }
    
    if(elapsed_seconds.count()>10)
    {
        cout << "Too Late" << endl;
        point--;
    } 
    //cout <<"Your time is "<<setw(3)<< elapsed_seconds.count() << endl;
    cout<<"================"<<endl;
    time-=elapsed_seconds.count();
    }
    

    if(point<0)point=0;
    cout<<"     +---------+"<<endl;
    cout<<"     |Point : "<<point<<"|"<<endl;
    cout<<"     +---------+"<<endl;
    cout << "Press Enter to Continue";
    cin.clear();
    cin.ignore(10000,'\n');

    return point;
}
//anser correction
int Check_Ans(string correctAns, string userAns) 
{
    if(userAns.length() > correctAns.length()) return 1;
    for (int n = 0; n < correctAns.length() ; n++)
    {
        if (correctAns[n] != userAns[n])
        {
            return 1;
        }
    }
    return 0; 
}

void art(){
    if(ani%2==0){
        cout << R"(              ###*++++*###              
           ##+=----------=+##           
         #=----+*-------------##         
      #:----*-.+=---+----------+#        
      #*=-=#..:=*=--#+--=*------*#       
      +#:=*       -**..=**=-*++-+#       
      ##.+-    _        _     #*=###     
       ##*     O        O     =   -##    
       #==////      .    ////-*+:.:#     
        #*+      ______     :-*+=+#       
          #:     \____/    .=+==+#        
           #+......::....*+==+#         
             ##+:.....:+*===*#          
             #+=*..#-.++==+##           
            #+==+*:..*+==+#             
            #+=*==*:*+==*#              
           #+=+*==+++===+#              
           #+=*+===.====+#              
    ###############################     
         #*==*#+..:=:....:=##           
          #........#........*#          
         #+*****************+##    )"<<endl;
    }
    else{
        cout << R"(              ###*++++*###              
           ##+=----------=+##           
         #=----+*-------------##         
      #:----*-.+=---+----------+#        
      #*=-=#..:=*=--#+--=*------*#       
      +#:=*       -**..=**=-*++-+#       
      ##.+-    _        _     #*=##     
       ##*     O        <     = =#*    
       #==////      .    //// ==##     
        #*+      ______      -*#       
          #:     \____/    .=:#         
           #+......::....*+=#          /|___
             ##+:.....:+*==########:=++   __)     
             #+=*..#-.++=+==++=+=-;:++   __/
            #+==+*:..*+==+####+;=###++-___/        
            #+=*==*:*+==*#              
           #+=+*==+++===+#              
           #+=*+===.====+#              
    ###############################     
         #*==*#+..:=:....:=##           
          #........#........*#          
         #+*****************+##       )"<<endl;
    }
    ani++;
}
