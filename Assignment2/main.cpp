#include <iostream>
#include "date.cpp"

using namespace std;

int main(){


   Date d1;		// should default to 1/1/2000
   Date d2(4,10,1992);  // should init to 4/10/1992
   
   int x;

   // display dates to the screen
   cout << "\nDate d1 is: ";
   d1.Show();			
   cout << "\nDate d2 is: ";
   d2.Show();

   d1.SetFormat('L');		// change format of d1 to "Long" format
   cout << "\nDate d1 is: ";
   d1.Show();
   
   x = d1.Compare(d2);
   
   cout << x << endl;
   
   d2.Set(2,29,1600);
   d2.SetFormat('T');
   d2.Show();
   
   d2.Increment(5);
   d1.Increment(365);
   
   d2.Show();
   d1.Show();
   d2.SetFormat('J');
   d2.Show();
   d1.SetFormat('J');
   d1.Show();
   
   
   
    return 0;
}