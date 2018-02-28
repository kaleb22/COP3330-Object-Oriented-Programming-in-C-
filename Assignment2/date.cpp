// Name: Kaleb Dalla Pria   Object Oriented Programming    Section: 10     Recitation Class: Tu - 3:30pm - 4:50 pm

/* This is the file that contains the definitions for the functions listed in the class Date.
 */

#include <iostream>
#include "date.h"

using namespace std;

Date::Date(){                                                                   
    
    month = 1;
    day = 1;
    year = 2000;
    
    format = 'D';                                                               // default format for function Show()
}

Date::Date(int m, int d, int y){
    
    if(m > 12 || m < 1 || d < 1 || y < 0)                                       // define the bounderies
    {
        month = 1;
        day = 1;
        year = 2000;
    }
    else if(m == 2 && d < 29)                                                   
    {
        month = m;
        day = d;
        year = y;
    }
    else if (m == 4 && d < 31 || m == 6 &&  d < 31 || m == 9 && d < 31 || m == 11 && d < 31)
    {
        month = m;
        day = d;
        year = y;
    }
    else if(m == 1 && d < 32 || m == 3 && d < 32 || m == 5 && d < 32 || m == 7 && d < 32 || m == 8 && d < 32 || m == 10 && d < 32 || m == 12 && d < 32)
    {
        month = m;
        day = d;
        year = y;
    }
    else if(m == 2 && d <= 29 && y % 4 == 0 && y % 400 == 0){                   // includes leap years (century ones)
        month = m;
        day = d;
        year = y;
        
    }
    else if(m == 2 && d <= 29 && y % 4 == 0 && y % 400 == 0){                   // include leap years (in general)
        month = m;
        day = d;
        year = y;
       
    }
    else
    {
        month = 1;
        day = 1;
        year = 2000;
    }
    
    format = 'D';                                                               // default format for function Show()
}

void Date::Input(){
    
    int verificador, m, d, y;                                                   // variable verificador checks if the date is valid or not
    char slash1;                                                                // store the first '/'
    char slash2;                                                                // store the second '/'
    
    do {
        
        cout << "Please, enter a valid date:" << endl;
        cin >> m >> slash1 >> d >> slash2 >> y;
        
        if(m > 12 || m < 1 || d < 1 || y < 0)
        {
            verificador = 0;
            cout << "Sorry, invalide date. Try again." << endl;
        }
        else if(m == 2 && d < 29)
        {
            month = m;
            day = d;
            year = y;
            verificador = 1;
        }
        else if (m == 4 && d < 31 || m == 6 &&  d < 31 || m == 9 && d < 31 || m == 11 && d < 31)
        {
            month = m;
            day = d;
            year = y;
            verificador = 1;
        }
        else if(m == 1 && d < 32 || m == 3 && d < 32 || m == 5 && d < 32 || m == 7 && d < 32 || m == 8 && d < 32 || m == 10 && d < 32 || m == 12 && d < 32)
        {
            month = m;
            day = d;
            year = y;
            verificador = 1;
        }
        else if(m == 2 && d <= 29 && y % 4 == 0 && y % 400 == 0){
             month = m;
             day = d;
             year = y;
             verificador = 1;
        }
        else if(m == 2 && d <= 29 && y % 4 == 0 && y % 400 == 0){
            month = m;
            day = d;
            year = y;
            verificador = 1;
        }
        else
        {
            verificador = 0;
            cout << "Sorry, invalide date. Try again." << endl;
        }
    
    } while (verificador != 1);                                                 // repeat the loop until the user enter a valid date
        
}


bool Date::Set(int m, int d, int y)
{
    
    if(m > 12 || m < 1 || d < 1 || y < 0)                                       // define the bounderies
    {
        return false;
    }
    else if(m == 2 && d < 29)
    {
        month = m;
        day = d;
        year = y;
        return true;
    }
    else if (m == 4 && d < 31 || m == 6 &&  d < 31 || m == 9 && d < 31 || m == 11 && d < 31)
    {
        month = m;
        day = d;
        year = y;
        return true;
        
    }
    else if(m == 1 && d < 32 || m == 3 && d < 32 || m == 5 && d < 32 || m == 7 && d < 32 || m == 8 && d < 32 || m == 10 && d < 32 || m == 12 && d < 32)
    {
        month = m;
        day = d;
        year = y;
        return true;
    }
    else if(m == 2 && d <= 29 && y % 4 == 0 && y % 400 == 0){                   // include leap years (century ones)
        month = m;
        day = d;
        year = y;
        return true;
    }
    else if(m == 2 && d <= 29 && y % 4 == 0){                                   // include leap years (in general)
        month = m;
        day = d;
        year = y;
        return true;
    }
    else
    {
        return false;
    }
    
}

int Date::GetMonth() const{
    
    return month;
}

int Date::GetDay() const{
    
    return day;
}

int Date::GetYear() const{
    
    return year;
}

void Date::Increment(int d){
    
    int resto = 0;                                                              // variable resto stores the result of the subtraction between the days in a month and the present day
    int m = month;

    do {
        
        if( m == 4 || m == 6 || m == 9 || m == 11)                              // months 4, 6, 9 and 11 has 30 days. So you subtract the current day from 30
            resto = 30 - day;
        else if( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) // months 1, 3, 5, 7, 8, 10 and 12 has 31 days. So you subtract the current day from 31
           resto = 31 - day;
        else if(m == 2 && year % 4 == 0 && year % 400 == 0)                     //includes leap century years
            resto = 29 - day;
        else if(m == 2 && year % 4 == 0)                                        //includes leap general years
            resto = 29 - day;
        else
           resto = 28 - day;
    
    
        if( resto >= d){
            day = day + d;
            d = 0;
        }
        else
        {
           d = d - resto; 
           day = 0;
           
           if(m == 12)
           {
                m = 1;
                year = year + 1;   
           }
            else
                m = m + 1;
        }
        
    }while (d != 0);                                                            // still doing the loop until d == 0
        
    month = m;
    
}

int Date::Compare(const Date& d) const{                                         // compare two dates
    
    if (year < d.year)                                                          
        return -1;
    else if (year > d.year)
        return 1;
    else
    {
        if(month < d.month)
            return -1;
        else if (month > d.month)
            return 1;
        else 
        {
            if (day < d.day)
                return -1;
            else if(day > d.day)
                return 1;
            else
                return 0;
            
        }
    }
        
}

bool Date::SetFormat(char f){
    

   if (f == 'T')
    {
        format = 'T';
        return true;
    }
        
    else if( f == 'L')
    {
        format = 'L';
        return true;
    }
    else if(f == 'D')
    {
        format = 'D';
        return true;
    }
    else if(f == 'J')
    {
        format = 'J';
        return true;
    }
        return false;
    
}

void Date::Show() const
{
    
    int resto;                                                                  // variable resto stores the last 2 digits from the year
    
    if(format == 'D')                                                           // default format mm/d/yyyy
        cout << month << "/" << day << "/" << year << endl;
    else if(format == 'T')                                                      // Changes to two digit mm/dd/yy
    {
        if(year > 99)
            resto = year % 100;
        else
            resto = year;
        
        if(month < 10 && day < 10)
        {
            if( resto < 10)
                cout << '0' << month << "/" << '0' << day << "/" << '0' << resto << endl;
            else
                cout << '0' << month << "/" << '0' << day << "/" << resto << endl;
        }
        else if(month < 10 && day > 10)
        {
            
            if(resto < 10)
                cout << '0' << month << "/" << day << "/" << '0' << resto << endl;
            else
                cout << '0' << month << "/" << day << "/" << resto << endl;
        }
        else
        {
            if(resto < 10)
                cout << month << "/" << day << "/" << '0' << resto << endl;
            else
                cout << month << "/" << day << "/" << resto << endl;
        }
            
    }
    else if(format == 'L')                                                      //Set to Long format Month day, yyyy
    {
        if(month == 1)
            cout << "Jan " << day << ", " << year << endl;
        else if(month == 2)
            cout << "Fev " << day << ", " << year << endl;
        else if(month == 3)
            cout << "Mar "  << day << ", " << year << endl;
        else if(month == 4)
            cout << "Apr " << day << ", " << year << endl;
        else if(month == 5)
            cout << "May " << day << ", " << year << endl;
        else if(month == 6)
            cout << "June " << day << ", " << year << endl;
        else if(month == 7)
            cout << "July " << day << ", " << year << endl;
        else if(month == 8)
            cout << "Aug " << day << ", " << year << endl;
        else if(month == 9)
            cout << "Sept " << day << ", " << year << endl;
        else if(month == 10)
            cout << "Oct " << day << ", " << year << endl;
        else if(month == 11)
            cout << "Nov " << day << ", " << year << endl;
        else
            cout << "Dec " << day << ", " << year << endl;
    }
    else if(format == 'J')                                                      // Sets to Julian day format yy-days
    {
        
        int i;
        int counter = 0;
        int resto;
        
        for(i = 1; i < month; i++){                                             // this loop counts the day until the last month
            
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                counter = counter + 31;
            else if(i == 4 || i == 6 || i == 9 || i == 11)
                counter = counter + 30;
            else if(i == 2 && year % 4 == 0 && year % 400 == 0)
                counter = counter + 29;
            else if(i == 2 && year % 4 == 0)
                counter = counter + 29;
            else
                counter = counter + 28;
        }
        
        counter = counter + day;                                                // add the days of the current month to get the total
        
        if(year > 99)
            resto = year % 100;
        else
            resto = year;
            
        if(resto < 10 && counter < 99)
            cout << '0' << resto << '-' << '0' << counter << endl;
        else if(resto > 10 && counter < 99)
            cout << resto << '-' << '0' << counter << endl;
        else if(resto < 10 && counter > 99)
            cout << '0' << resto << '-' << counter << endl;
        else
            cout << resto << '-' << counter;
        
    }
    else
        cout << endl;
    
}