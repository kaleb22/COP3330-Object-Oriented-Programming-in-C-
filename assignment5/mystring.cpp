// Name: Kaleb Dalla Pria       Section: 10         Recitation Class: Tu - 3:30pm to 4:50pm

/* This file contains the definitions for all the functions that are written in the class MyString.
 */

#include "mystring.h"
#include <iostream>

using namespace std;

MyString::MyString()
{
    size = 1;
    string = new char[size];
    null = '\0';                         // stores the null character 
    
    string[0] = '\0';                    // put nothing inside

}

MyString::MyString(const char* st)
{
    size = LenghOfChar(st);
    
    string = new char[size];                // creates a new dynamic array
    
    int i;
    for(i = 0; i < size; i++) 

        string[i] = st[i];                  // copy one array to the other one
        
    string[i] = '\0';                       // stores the null character at the end

    null = '\0';                            // stores the null character
}

MyString::MyString(int num)
{
    size = LenghtOfInt(num);

    string = new char[size];                        // creates the dynamic allocation for the conversion + 1 to null character
    
    int  resto;
    char transfer;
    
    for (int i = size-1; i >= 0; i--)                  // while num != 0, keep reading the number
    {
        resto = num % 10;                           // takes the last digit
        num = num / 10;                             // remove the last digit
        transfer = resto + '0';                     // convert it to char
        string[i] = transfer;                       // store into the array
    }
    
    string[size] = '\0';

    null = '\0';                                    // stores the null character
}
MyString::~MyString()
{
   delete [] string;
}

MyString::MyString(const MyString& st)              // copy constructor, allow deep copy
{
    size = st.size;
    
    string = new char[st.size];                     // create a new array
    
    for(int i = 0; i < size; i++)
        string[i] = st.string[i];                   // copy one array to the other one.
        
    null = '\0';                                    // stores the null character
}

MyString& MyString::operator=(const MyString& st)
{
    if(this != &st)                          // only copy if the object passed is not already this one
    {
        delete [] string;                   // delete old data

        size = st.size;                 // null character
        string = new char[st.size];         // create a new array
        
        int i;
        
        for(i = 0; i < size; i++)
            string[i] = st.string[i];       // copy one array to the other one
    }
    
    return *this;                           // return the object itself, by reference
}

bool operator==(const MyString& st1 , const MyString& st2)
{
    int counter = 0;
    
    if(st1.size == st2.size)
    {
        for(int i = 0; i < st1.size; i++)
        {
            if(st1.string[i] == st2.string[i])
                counter++;
        }
    }
    else
        return false;               // different size couldn't be equal
        
    if(counter == st1.size)
        return true;                // same size and equal
    else
        return false;               // same size but not the same string
}

bool operator!=(const MyString& st1, const MyString& st2)
{
    if(st1 == st2)
        return false;
    else
        return true;
}

bool operator> (const MyString& st1, const MyString& st2)
{
        
    int i = 0;
    while ((st1.string[i] != '\0') && (st1.string[i] == st2.string[i]))         // while st1 is not null character and they are the same, keep searching
    {
        i++;
    }
    
    int resul = st1.string[i] - st2.string[i];                                  // return the subtraction of the two ascii letters

    if(resul > 0)                                   // negative number if st1 comes first
        return true;
    else
        return false;                                // positive number if st2 comes first
}

bool operator<=(const MyString& st1, const MyString& st2)
{
    if(st1 > st2)
        return false;
    else
        return true;
}

bool operator< (const MyString& st1, const MyString& st2)
{
    
    int i = 0;
    while ((st1.string[i] != '\0') && (st1.string[i] == st2.string[i]))         // while st1 is not null character and they are the same, keep searching
    {
        i++;
    }
    
    int resul = st1.string[i] - st2.string[i];                                  // return the subtraction of the two ascii letters
    
    if(resul >= 0)                                   // positive number if st2 comes first
        return false;
    else
        return true;                                // negative number if st1 comes first
        
}

bool operator>=(const MyString& st1, const MyString& st2)
{
    if(st1 < st2)
        return false;
    else
        return true;
}

ostream& operator<< (ostream& os, const MyString& my)
{

   for(int i = 0; my.string[i] != '\0'; i++)
        os << my.string[i];
    
    return os;
}

int MyString::CheckSpace(const char& ch)
{
    if(ch == ' ')
        return -1;                                      // -1 is space
    else if(ch == '\t')
        return -1;
    else if(ch == '\n')
        return -1;
    else if(ch == '\v')
        return -1;
    else if(ch == '\f')
        return -1;
    else if(ch == '\r')
        return -1;
    else
        return 0;                                       // not space
}

istream& operator>> (istream& is, MyString& my)
{
    my.Grow();                          // first grow
    
    int i = 0;
    char ch;
    int j = -1;                         // my flag
    
    while( j == -1)                     // ignore the white spaces
    {
        ch = is.get();
        j = my.CheckSpace(ch);
    }
    
    my.string[i] = ch;                  // catch the first non white space
    
    j = 0;                              // reset flag
   for(i = 1; j != -1; i++ )            // keeps reading until white space
    {   
        if(i == my.size)                // out of space, grow
        {
            my.Grow();
        }
        
        ch = is.get();                  // catch the character
        j = my.CheckSpace(ch);          // verify if it is white space
        my.string[i] = ch;              // put it inside mystring

    } 
    
    my.string[i] = '\0';                // overwrite the white space with the null character
}

istream& getline (istream& is, MyString& my, char delim)
{
    my.Grow();                          // first grow
    
    int i = 0;
    char ch;
    
    ch = is.get();
    my.string[i] = ch;

   for(i = 1; ch != delim; i++ )            // keeps reading until white space
    {   
        if(i == my.size)                // out of space, grow
        {
            my.Grow();
        }
        
        ch = is.get();                  // catch the character
        
        if(ch == delim)
            my.string[i] = '\0';                // overwrite the white space with the null character
        else
            my.string[i] = ch;              // put it inside mystring
    } 
    

}

MyString operator+ (const MyString& my1, const MyString& my2)
{
    MyString d1;
    
    d1.size = (my1.size + my2.size - 1);                                    // to delete the null value of the firts one
    
    d1.string = new char[d1.size];                         // dealocates a new array
    
    int i;
    for(i = 0; my1.string[i] != '\0'; i++)
        d1.string[i] = my1.string[i];                   // copy my1 to d1


    int k, j;
    for(j = i, k = 0; j < d1.size; k++, j++)
        d1.string[j] = my2.string[k];                   // copy my2 right after my1 finish

    d1.string[j] = my2.string[k];                       // copy '\0' to the end of the array

    return d1;
}

MyString& MyString::operator+=(const MyString& st)
{
    size = (size + st.size) - 1;                        // grow to store the two arrays and discard the null character of the firts array
    
    char* newString = new char[size];                   // creates a new array of the new size
    
    int i;
    for(i = 0; string[i] != '\0'; i++)                  // copies until null character
        newString[i] = string[i];                       // copy the first array into the new one       


    int k;
    for(int j = i, k = 0; j < size; k++, j++)
        newString[j] = st.string[k];                   // copy st to the final of string


    delete [] string;                           // delete the old array    
    string = newString;                         // points the old array to the new one
        
    return *this;                                   // return the calling object
}

const char* MyString::getCString() const
{
    return string;                           // Just return the calling object because my array is already a C-string array
}

char& MyString::operator[] (unsigned int index)
{
    if(index >= size)
    {
        while(index > size)                 // keep growing the array until index < size
        {
            Grow();
        }
        
        int i;
        for(i = 0; string[i] != '\0'; i++)
        {
            
        }
        
        int j = 0;
        for(j = i; j < index; j++)
            string[j] = ' ';                // set blank spaces between the end of the string and the index
            
        string[j] = string[index];
        string[j+1] = '\0';
        
        return string[index];
        
    }
    else
        return string[index];
}

const char& MyString::operator[] (unsigned int index) const
{
    
    if( index >= size)
        return null;                    // return the null character initialized in the constructors
    else
        return string[index];

}

MyString MyString::substring(unsigned int index) const
{
    MyString temp;                                  // create a temporaty MyString object
    
    temp.size = size - index;                       // update the size
    char* newString = new char[temp.size];
    
    int j;
    for(int i = index, j = 0; i < size; j++, i++)
        newString[j] = string[i];                 // copy the substring
        
    delete [] temp.string;
    temp.string = newString;
    
    return temp;                                    // return the substring
}

MyString MyString::substring(unsigned int index, unsigned int lenght) const
{
    MyString temp;                                      // create a temporaty MyString object
    
    int resul = size - index;
    
    if(resul < lenght)                                  // lenght too big
    {
        temp.size = size - index;                       // update the size
        
        int j;
        for(int i = index, j = 0; i < size; j++, i++)   // copy until the end of the string
            temp.string[j] = string[i];                 // copy the substring
    }
   else
    {
        temp.size = lenght;
        
        int j;
        for(int i = index, j = 0; j < temp.size; j++, i++)
            temp.string[j] = string[i];                 // copy the substring
    }
    

    return temp;                                        // return the substring
}

MyString& MyString::insert(unsigned int index, const MyString& s)
{
    if(index > size)
    {
        int newSize = (size + s.size) - 1;              // - 1 to discard null character 
        
        int oldsize = size;
        
        while(size < newSize)                           // keep growing until size is enough
        {
            Grow();                                 
        }
        
        int j;
        for(int i = oldsize, j = 0; j < s.size; j++, i++)
            string[i] = s.string[j];                    // copy string at the end of array

    }
    else
    {   
        int newSize = (size + s.size) - 1;              // discard the null character of the first string
        
        char* newString = new char[newSize];
        
        int i;
        for(i = 0; i < index; i++)
            newString[i] = string[i];                   // copy the beginnig of the first string until index
         
        int j, k; 
        for(j = i, k = 0; k < s.string[k] != '\0'; k++, j++)
            newString[j] = s.string[k];                 // copy the second string in the middle of the new one

        int m, l;    
        for(l = j, m = index; string[m] != '\0'; l++, m++ )
            newString[l] = string[m];                   // copy the rest of the first string
            
        newString[l] = string[m];                       // copy the null character
            
        size = newSize;
        delete [] string;
        string = newString;
    }
    
    return *this;
}

int MyString::getLength() const
{
    int counter = 0;
    
    for(int i = 0; string[i] != '\0'; i++)
        counter++;
    
    return counter;
}

int MyString::indexOf(const MyString& st) const 
{
    int check = st.getLength();                    // stores the lenght of the string
    
    int counter = 0;                              // if counter == check, there is a substring
    int j = 0;
    int firstIndex = -1;
    int flag = 0;
    
    for(int i = 0; string[i] != '\0'; i++)               // goes throught the string
    {
       if(flag == 1)                            
            break;
        
        for(j = counter; j < st.string[j] != '\0'; j++)     // goes throught the st.string
        {
          if(st.string[j] == string[i])                     // if the first letter of st.string is equal to the letter of string
            {
                counter++;                                  // counter increase
                
                if(counter == check)                        // if counter == check (the size of the substring), so the substring exist
                {
                    flag = 1;                               // to leave the first loop
                    firstIndex = (i - counter) + 1;         // return the index of the first match
                }
                break;                                      // leave the loop to move one unit forward into the string
                
            }
            else
            {
                j = 0;                                      // reset the second loop
                counter = 0;                                // reset the counter
                break;                                      // leave the loop to move one unit forward into the string
            }
        }
    }    
    
    return firstIndex;                                      // return the index
    
}

void MyString::Grow()
{
    size = size + 5;
    
    char* newString = new char[size];                                // build a new array of size + 5
    
    int i;
    for(i = 0; string[i] != '\0'; i++)
        newString[i] = string[i];                                   // copy old array to the new one
        
    newString[i] = string[i];                                       // copy the null character
    
    delete [] string;                                               // delete old array
    string = newString;                                             // points the new array to the old one
}

int MyString::LenghtOfInt(int num)
{
    int counter = 0;
    
    if(num == 0)
        counter = 1;
    
    for(counter = 0; num != 0; counter++)
         num = num / 10;


    return counter;
}

int MyString::LenghOfChar(const char* st)
{
    int counter = 0;
    
    for(int i = 0; st[i] != '\0'; i++)
        counter++;
        
    return counter+1;                           // count the null character
}

// extra credit
MyString operator- (MyString my1, const MyString& my2)
{
    int index = my1.indexOf(my2);           // catch the first index
        
    if(index < 0)                           // check if there is a substring
        return my1;
    else
    {
        while (index > 0)                   // while there is a substring
        {
            int test = my1.getLength();
            int resul = test - index;
            int lenght = my2.getLength();

            if(resul == lenght)             // if substring is at the end
            {
                my1.string[index] = '\0';   // just add the null character
                
                index = my1.indexOf(my2);   // call for check new substring

            }
            else
            {
                int j, i;
                for(i = index, j = 0; i + lenght < test; j++, i++)
                    my1.string[i] = my1.string[i + lenght];             // delete the substring from the string
                    
                my1.string[i] = '\0';                                   // put the null character at the end

                index = my1.indexOf(my2);                               // call for check new substring

            } 
        } 
    } 
    
        return my1;                                                     // return the new string
        
}