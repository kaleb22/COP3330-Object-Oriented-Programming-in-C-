// Name: Kaleb Dalla Pria       Section: 10         Recitation Class: Tu - 3:30pm to 4:50pm

/* This class is called Date and it objective is to create an object that represent dates in different ways and works as a calendar. Also,
 * with this class it is possible to compare two dates and see who comes first or increment dates by a value that the user can choose.
 */
class Date{
    public:
    
    //constructors
    Date();                                         // default constructor      
    Date(int m, int d, int y);                      // constructor with parameters 
    
    void Input();                                   // Allows user to input a date in the format month/day/year
    void Show() const;                              // Display the dates in different formarts dependind of the parameter passed by the function SetFormat() 
    
    
    bool Set(int m, int d, int y);                  // Allows the user to set a Date in the format m/d/yyyy
    bool SetFormat(char f);                         // change the way that the date is shown in the Show function.
    
    //accessors
    int GetMonth() const;                           // return month 
    int GetDay() const;                             // return day
    int GetYear() const;                            // return year
    
    int Compare(const Date& x) const;               // return 1 if x comes first, 0 if they are igual or -1 if the calling object comes first.
    void Increment(int d = 1);                      // increment days, default is to increment by 1.
    
    private:
    int day;                                        // store the day
    int month;                                      // store the month
    int year;                                       // store the year
    char format;                                    // store the format character for the SetFormat() function
};