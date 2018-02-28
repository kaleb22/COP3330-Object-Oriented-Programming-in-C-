// Name: Kaleb Dalla Pria   Object Oriented Programming    Section: 10     Recitation Class: Tu - 3:30pm - 4:50 pm

/* This is the file that contains the definitions of the functions listed in the class Diamond.
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include "diamond.h"

using namespace std;

Diamond::Diamond(int s, char b, char in){
    
    if(s < 1)
        s = 1;
    else if(s > 39)
        s = 39;
    else
        size = s;
        
    size = s;
    border = b;
    inside = in;

}

int Diamond::Perimeter(){
    
    return size * 4;
}

int Diamond::GetSize(){
    
    return size;
}

double Diamond::Area(){
    
    return ((pow (size, 2) * sqrt(3) ) / 4) * 2;
}

void Diamond::Grow(){
    
    if(size != 39)
        size = size + 1;

}

void Diamond::Shrink(){
    
    if(size != 1)
        size = size - 1;
}

void Diamond::SetBorder(char b){
    
    if(b < 33 || b > 126)
        border = '#';
    else
        border = b;
    
}

void Diamond::SetFill(char in){
    
    if(in < 33 || in > 126)
        inside = '*';
    else
        inside = in;
}

void Diamond::Draw(){

//this first block of for, starts to draw the diamond. It draws the upper part of the diamond

          for(int i = 1; i <= size; i++){               // i begin in 1 and Increase until it reaches the value of the size
       
            for(int j = (size-i); j > 0; j--)           // print (size-i) spaces for each line
                cout << " ";
                
            for(int j = i; j > 0; j--)                  // print the first piece of the diamond
            
                if(j < i && j > 1)
                    cout << inside << " ";
                else
                    cout << border << " ";
        
        cout << "\n";                                    // end the line
   
      }
      
// this second block of for, starts in the middle and print the bottom of the diamond
      
        for(int i = size-1; i > 0; i--){               // At this time, i Begins in (size - 1) and decrease
       
            for(int j = (size-i); j > 0; j--)          // print (size - i) space for each line
                cout << " ";
                
            for(int j = i; j > 0; j--)                 // print the first piece of the bottom of the diamond.
                
                if(j < i && j > 1)
                    cout << inside << " ";
                else
                    cout << border << " ";
        
    cout << "\n";							           // end the line
   }
    
    
}

void Diamond::Summary(){
    
    cout <<  "Size of diamond's side is : " << size << " units" << endl;
    cout << "Perimeter of the diamond is : " << Perimeter() << " units" << endl;
    cout.precision(2);
    cout << std::fixed << "Area of the diamond is : " << Area() << " units" << endl;
    cout << "Diamond looks like: " << endl;
    Draw();
}