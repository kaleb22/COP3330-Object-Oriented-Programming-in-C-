// Name: Kaleb Dalla Pria       Section: 10         Recitation Class: Tu - 3:30pm to 4:50pm

/* This is the file that contains all the definitions of the class Song. 
 */

#include "song.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

Song::Song()
{
    strcpy(title, " ");
    strcpy(artist, " ");
    size = 0;
    
}

const char* Song::GetTitle() const 
{
    return title;    
    
}

const char* Song::GetArtist() const
{
    return artist;
    
}

int Song::GetSize() const
{
    return size;
    
}

Style Song::GetCategory() const
{
    return category;
    
}

void Song::Set(const char* t, const char* a, Style st, int sz) 
{
    int i;
    
    size = sz;
    category = st;
    
    for(i = 0; i < 36; i++)
    {
        title[i] = t[i];
    }
    
    for(i = 0; i < 21; i++)
    {
        artist[i] = a[i];
    }
    
}

ostream& operator << (ostream& os, const Song& s)
{
    double newSize = s.size / 1000.0;
    
    // capture current output stream settings
   int oldprecision = os.precision();
   char oldfill = os.fill();
   ios_base::fmtflags oldflags = os.flags();

   // do my output changes
   os.setf(ios::left);
   os << setprecision(1);
   os << fixed;
   os.width(36);
   
   // print
    switch (s.category)
    {
        case 0 : 
        {
            os << s.title;
            os.width(20);
            os <<  s.artist;
            os.width(17);
            os << "POP";
            os.width(5);
            os <<  newSize; 
        }
            break;
        
        case 1 :
        {
            os.width(36);
            os << s.title;
            os.width(20);
            os <<  s.artist;
            os.width(17);
            os << "ROCK";
            os.width(5);
            os <<  newSize;     
            
        }
        break;
        
        case 2 : 
        {
            os.width(36);
            os << s.title;
            os.width(20);
            os <<  s.artist;
            os.width(17);
            os << "ALTER";
            os.width(5);
            os <<  newSize;        
        }
        break;
        
        case 3 : 
        {
            os.width(36);
            os << s.title;
            os.width(20);
            os <<  s.artist;
            os.width(17);
            os << "COUNTRY";
            os.width(5);
            os <<  newSize;        
        }
        break;
        
        case 4 : 
        {
            os.width(36);
            os << s.title;
            os.width(20);
            os <<  s.artist;
            os.width(17);
            os << "HIPHOP";
            os.width(5);
            os <<  newSize;
        }
        break;
        
        case 5 : 
        {
            os.width(36);
            os << s.title;
            os.width(20);
            os <<  s.artist;
            os.width(17);
            os << "PARODY";
            os.width(5);
            os <<  newSize;        
        }
        break;
    }

   // PUT THINGS BACK THE WAY THEY WERE WHEN I FOUND THEM
   os.precision(oldprecision);	// restore old precision setting
   os.fill(oldfill);			// restore old fill char setting
   os.flags(oldflags);		// restore all prior format flags
    
}  
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
