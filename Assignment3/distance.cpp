// Name: Kaleb Dalla Pria       Section: 10         Recitation Class: Tu - 3:30pm to 4:50pm

/* This file contains the definitions of the functions listed in the class Distance
 */
 
#include <iostream>
#include "distance.h"

using namespace std;

void Distance::Simplify(int cm, int cy, int cf, int in){                        // Simplify the distance objects
    
    int countfeet = cf;
    int countyards = cy;
    int countmiles = cm;
    int i, j, k, l;

    for(i = in; i >= 12; i -= 12)                                               // If inches > 12, add 1 foot
        countfeet++;
    
        
    for(j = countfeet; j >= 3; j -= 3)                                          // if feet > 3, add one yard
        countyards++;
    
    
    for(k = countyards; k >= 1760; k -= 1760)                                   // if yards > 1760, add 1 mile
        countmiles++;
        
    inches = i;
    feet = j;
    yards = k;
    miles = countmiles;
}

Distance::Distance(){                                                           // Initialize distance to 0
    
    miles = 0;
    yards = 0;
    feet = 0;
    inches = 0;
}

Distance::Distance(int in){                                                     // build a Distance object just with the number of inches
    
    if(in < 0)
    {
        miles = 0;
        yards = 0;
        feet = 0;
        inches = 0;
    }
    else
    {
        Simplify(0, 0, 0, in);
    }
}

Distance::Distance(int m, int y, int f, int i){
 
    if(m < 0 || y < 0 || f < 0 || i <  0)
    {
        miles = 0;
        yards = 0;
        feet = 0;
        inches = 0;
    }
    else
    {
        Simplify(m, y, f, i);
    }
}

ostream& operator<<(ostream& s, const Distance& d){
    
    if(d.miles == 0 && d.yards != 0 && d.feet != 0)
    {
            s << "(" << d.yards << "y " << d.feet << "' " << d.inches << "\"" << ")";        
    }

    else if(d.miles != 0 && d.yards == 0 && d.feet != 0)
    {
            s << "(" << d.miles <<"m " << d.feet << "' " << d.inches << "\"" << ")";        
    }

    else if(d.miles != 0 && d.yards != 0 && d.feet == 0)
    {
            s << "(" << d.miles <<"m " << d.yards << "y " << d.inches << "\"" << ")";        
    }

    else if(d.miles == 0 && d.yards == 0 && d.feet != 0)
    {
            s << "(" << d.feet << "' " << d.inches << "\"" << ")";    
    }
            
    else if(d.miles != 0 && d.yards == 0 && d.feet == 0)
    {
            s << "(" << d.miles <<"m " << d.inches << "\"" << ")";    
    }
           
    else if(d.miles == 0 && d.yards != 0 && d.feet == 0)
    {
            s << "(" << d.yards << "y " << d.inches << "\"" << ")";
    }
    else if(d.miles == 0 && d.yards == 0 && d.feet == 0)
    {
            s << "(" << d.inches << "\"" << ")";
    }
    else
    {
            s << "(" << d.miles <<"m " << d.yards << "y " << d.feet << "' " << d.inches << "\"" << ")";
    }
    
    return s;
}

istream& operator>>(istream& e, Distance& d2){
    
    char v1, v2,v3;
    
    e >> d2.miles >> v1 >> d2.yards >> v2 >> d2.feet >> v3 >> d2.inches;

    if(d2.miles < 0 || d2.yards < 0 || d2.feet < 0 || d2.inches < 0)
    {
        d2.miles = 0;
        d2.yards = 0;
        d2.feet = 0;
        d2.inches = 0;
    }
    else
    {
        
        int countfeet = d2.feet;
        int countyards = d2.yards;
        int countmiles = d2.miles;
        int i, j, k;
        
        for(i = d2.inches; i >= 12; i -= 12)
            countfeet++;
        
            
        for(j = countfeet; j >= 3; j -= 3)
            countyards++;
        
        
        for(k = countyards; k >= 1760; k -= 1760)
            countmiles++;
            
        d2.inches = i;
        d2.feet = j;
        d2.yards = k;
        d2.miles = countmiles;

    }
}

Distance operator+(const Distance& x1, const Distance& x2) {
    
    int newInches,
        newFeet,
        newYards,
        newMiles;
        
    newInches = x1.inches + x2.inches;
    newFeet = x1.feet + x2.feet;
    newYards = x1.yards + x2.yards;
    newMiles = x1.miles + x2.miles;
    
    return Distance(newMiles, newYards, newFeet, newInches);
}

Distance operator-(const Distance& x1, const Distance& x2){
    
    int newInches,
        newFeet,
        newYards,
        newMiles;
    
    int askfeet = 0;                                                            // if x1.feet < x2.feet askfeet = 1 
    int askyards = 0;                                                           // if x1.yards < x2. yards askyards = 1
    int askmiles =0;                                                            // if x1.miles < x2.miles askmiles = 1
    
    if(x1 < x2)
    {
        return Distance(0,0,0,0);
    }
    else
    {
        if(x1.inches < x2.inches)                                               // borrow 12 inches from feet
        {
              newInches = 12 + (x1.inches - x2.inches);
              askfeet = 1;
        }
        else
        {
           newInches = x1.inches - x2.inches; 
        }
        
        
        if(askfeet == 0 && x1.feet < x2.feet)                                   // borrow 3 feet from yards
        {
            newFeet = 3 + (x1.feet - x2.feet);
            askyards = 1;
        }
        else if(askfeet == 1 && x1.feet <= x2.feet)
        {
            if(x1.feet == 1)
            {
                newFeet = 2 - x2.feet;
                askyards = 1;
            }
            else
            {
                newFeet = 2 + (x1.feet - x2.feet);
                askyards = 1; 
            }

        }
        else
        {
            newFeet = x1.feet - x2.feet;
        }
        
        
        if(askyards == 0 && x1.yards < x2.yards)                                // borrow 1760 yards from miles
        {
            newYards = 1760 + (x1.yards - x2.yards);
            askmiles = 1;
        }
        else if(askyards == 1 && x1.yards < x2.yards)
        {
            newYards = 1759 + (x1.yards - x2.yards);
            askmiles = 1;
        }
        else if(askyards == 1 && x1.yards > x2.yards)
        {
            newYards = (x1.yards - x2.yards) - 1;
        }
        else if(askyards == 1 && x1.yards == x2.yards)
        {
            newYards = 1759;
        }
        else
        {
            newYards = x1.yards - x2.yards;
        }
        
        if(askmiles == 1)
        {
            newMiles =  (x1.miles - x2.miles) - 1;
        }
        else
        {
            newMiles = x1.miles - x2.miles;
        }

    }
        
    return Distance(newMiles, newYards, newFeet, newInches);                    // return new Distance object with the subtraction result (simplify is called in the constructor)
    
}

Distance operator*(const Distance z1, const int a){
    
    int newInches,
        newFeet,
        newYards,
        newMiles;
        
    newInches = z1.inches * a;
    newFeet = z1.feet * a;
    newYards = z1.yards * a;
    newMiles = z1.miles * a;
    
    return Distance(newMiles, newYards, newFeet, newInches);                    // built a new object with the multiplication result (simplify is called in the constructor)
        
}

bool operator<(const Distance& d1, const Distance& d2){
    
    if(d1.miles == d2.miles)
    {
        if(d1.yards < d2.yards)
        {
            return true;
        }
        else if(d1.yards == d2.yards)
        {
            if(d1.feet < d2.feet)
            {
                return true;
            }
            else if(d1.feet == d2.feet)
            {
                if(d1.inches < d2.inches)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    else if(d1.miles < d2.miles)
    {
        return true;
    }
    else
        return false;
    
}

bool operator>=(const Distance& d1, const Distance& d2){
    
   if(d1 < d2)
        return false;
    else
        return true;
    
}

bool operator > (const Distance& d1, const Distance& d2){
    
    if(d1.miles == d2.miles)
    {
        if(d1.yards > d2.yards)
        {
            return true;
        }
        else if(d1.yards == d2.yards)
        {
            if(d1.feet > d2.feet)
            {
                return true;
            }
            else if(d1.feet == d2.feet)
            {
                if(d1.inches > d2.inches)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    else if(d1.miles > d2.miles)
    {
        return true;
    }
    else
        return false;
    
}

bool operator <= (const Distance& d1, const Distance& d2){
    
    if(d1 > d2)
        return false;
    else
        return true;
}

bool operator==(const Distance& d1, const Distance& d2){
    
    if(d1.miles == d2.miles && d1.yards == d2.yards && d1.feet == d2.feet && d1.inches == d2.inches)
        return true;
    else
        return false;
    
}

bool operator!=(const Distance& d1, const Distance& d2){
    
    if(d1 == d2)
        return false;
    else
        return true;
}

Distance& Distance::operator++(){                                               // Prefixed notation, return the real object ++x;

    inches = inches + 1;
    
    Simplify(miles, yards, feet, inches);
    
    return *this;
}

Distance Distance::operator++(int){                                             // Suffixed notation x++;
    
    Distance temp = *this;                                                      // copy the object
    
    inches = inches + 1;                                                        // increment inches
    Simplify(miles, yards, feet, inches);
    
    return temp;                                                                // return the old value
}

Distance& Distance::operator--(){                                               // prefixed notation --x;
    
    if(inches != 0)
    {
        inches = inches -1;
        
        Simplify(miles, yards, feet, inches);        
    }

    
    return *this;
    
}

Distance Distance::operator--(int){                                             //Suffixed notationx x--;
    
    Distance temp = *this;                                                      // Copy the object
    
    if(inches != 0)
    {
        inches = inches -1;                                                     // decrement inches
        
        Simplify(miles, yards, feet, inches);        
    }
    
    return temp;                                                                // return the old value
    
}








