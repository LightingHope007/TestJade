#include <iostream>
#include <cstdlib>//for random
#include <time.h>//for random
#include <cstring>

#include "gamefn.h"
#include "LL.h"

using namespace std;

int main(){
    LL L;
    Day *t;
    int i;
    cout<<"Hello world"<<endl;
    for(i=0;i<7;i++) {
        t=new Day();
        L.add_node(t);
    }
}
