#include <iostream>
#include "distance.cpp"

using namespace std;

int main(){
    
    Distance d1(1000000000,555,3,5);
    Distance d2(11,778,2,88);
    Distance d3(15263748);
    Distance d4(654321);
    Distance d5, d6;

    cout << d1 << " " << d4 << endl;    
   
    d5 = d1 - d4;
    d6 = d2 + d3;
    
    cout << d5 << endl;
    

    if(d1 != d2)
        cout << "ok";
    else
        cout << "fail";
   
    return 0;
}