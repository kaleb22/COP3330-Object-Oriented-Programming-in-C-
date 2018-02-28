// Name: Kaleb Dalla Pria       Section: 10         Recitation Class: Tu - 3:30pm to 4:50pm

/* This class is called MyString and the objective is to simulate the string.h class that is class of C++ library.
 */

#include <iostream>
using namespace std;

class MyString
{
  friend ostream& operator<< (ostream& os, const MyString& my);             // Done
  friend istream& operator>> (istream& is, MyString& my );                  // DONEEEEEEEEEEEEEEEEEEEEEEEEEEE!!!!!!!
  friend istream& getline (istream& is, MyString& my, char delim = '\n');   // DONE

  friend MyString operator+ (const MyString& my1, const MyString& my2);     // Done

  friend bool operator< (const MyString& st1, const MyString& st2);         // Done
  friend bool operator> (const MyString& st1, const MyString& st2);
  friend bool operator<=(const MyString& st1, const MyString& st2);
  friend bool operator>=(const MyString& st1, const MyString& st2);
  friend bool operator==(const MyString& st1 , const MyString& st2);        // Done
  friend bool operator!=(const MyString& st1, const MyString& st2);         // Done

public:
  MyString();				// empty string                                            Done
  MyString(const char* st);		// conversion from c-string                      Done
  MyString(int num);			// conversion from int                               Done
  ~MyString();				// destructor                                            Done
  MyString(const MyString& st);		// copy constructor                          Done
  MyString& operator=(const MyString& st);   // assignment operator            Done

  MyString& operator+=(const MyString& st);  // concatenation/assignment       Done

  // bracket operators to access char positions
  char& operator[] (unsigned int index);                                      // Done
  const char& operator[] (unsigned int index) const;                          // Done

  // insert s into the string at position "index"
  MyString& insert(unsigned int index, const MyString& s);                    // Done

  // find index of the first occurrence of s inside the string
  //  return the index, or -1 if not found
  int indexOf(const MyString& st) const;                                      // Done
  
  int getLength() const;		// return string length                            Done
  const char* getCString() const;	// return c-string equiv                     Done

  MyString substring(unsigned int index, unsigned int lenght) const;           // Done
  MyString substring(unsigned int index) const;                                // Done
  
  // extra credit
  friend MyString operator- (MyString my1, const MyString& my2);

private:

  char* string;
  int size;                            // includes the null character
  int LenghtOfInt(int num);            // it counts the number of digits that a number has
  int LenghOfChar(const char* st);     // it returns the lenght of a c-string
  char null;                           // stores the null character
  void Grow();                         // grows the array by 5
  int CheckSpace(const char& ch);      // return -1 if white space, 0 non white space
};
