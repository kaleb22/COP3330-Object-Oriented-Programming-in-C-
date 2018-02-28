#include <iostream>
#include <iomanip> 
#include "diamond.cpp"

using namespace std;

int main(){
    
    Diamond d1(-1, 'X', 'Y');

       cout << "Teste de area, getsize and perimetro, Verifica se o constructor is working" << endl;
       cout << d1.GetSize() <<  " "<< d1.Area() << " " << d1.Perimeter() << endl;

        d1.Grow();

        
        cout << endl;
        
       cout << "Now d1 Grows: " << endl;
       cout << d1.GetSize() <<  " "<< d1.Area() << " " << d1.Perimeter() << endl;
       d1.Draw();

       d1.Shrink();

       cout << endl;
       
       cout << "Teste o Shrink" << endl;
       cout << d1.GetSize() <<  " "<< d1.Area() << " " << d1.Perimeter() << endl;

       cout << endl;

    
       d1.SetBorder(32);

       cout << endl;
 
       
       cout << endl;
       
       d1.SetFill(127);

       cout << endl;
       
       d1.Summary();


    
    return 0;
    
}