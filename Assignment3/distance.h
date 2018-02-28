// Name: Kaleb Dalla Pria       Section: 10         Recitation Class: Tu - 3:30pm to 4:50pm

/* This class is called Distance and the main goal of this class is to represent a Distance object
 * in terms of (MILESm, YARDSy, FEET', INCHES"). Thus, with this class it is possible to compare, add, subtract and multiply
 * two distance objects using the straightforward notation that we are acostumate to.
 */
#include <iostream>
using namespace std;

class Distance{
    
    friend ostream& operator<<(ostream& s, const Distance& d);                  
    friend istream& operator>>(istream& e, Distance& d2);                       
    
    friend Distance operator+(const Distance& x1, const Distance& x2);          // add two distance objects
    friend Distance operator-(const Distance& x1, const Distance& x2);          // subtract two distances objects
    
    friend Distance operator*(const Distance z1, const int a);                  // multiply one distance object with one int
    
    // This functions compare two distance objects
    friend bool operator < (const Distance& d1, const Distance& d2);            
    friend bool operator > (const Distance& d1, const Distance& d2);            
    friend bool operator <= (const Distance& d1, const Distance& d2);           
    friend bool operator >= (const Distance& d1, const Distance& d2);           
    friend bool operator == (const Distance& d1, const Distance& d2);           
    friend bool operator != (const Distance& d1, const Distance& d2);           
    
    public:
    
    //Constructors
    Distance();                                   // initialize distence to 0   
    Distance(int in);                             // convert inches to Distance type 
    Distance(int m, int y, int f, int i);         // Initialize distance to (miles, yards, feet, inches)
    
    //increment and decrement operators
    Distance& operator++();                      // prefixed notation 
    Distance operator++(int);                    // posfixed notation
    Distance& operator--();                      // prefixed notation
    Distance operator--(int);                    // posfixed notation
    
    private:
    int miles,
        yards,
        feet,
        inches;
    void Simplify(int cm, int cy, int cf, int in);                              // Simplify the distance objects

};