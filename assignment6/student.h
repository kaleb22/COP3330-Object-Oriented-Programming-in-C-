#include <string>

using namespace std;

class Student
{
    public:
    
    Student(string nm, string ln, string cs);                       // constructor to initialize the student data
    
    //accessor's 
    string GetName() const;
    string GetLast() const;
    string GetCourse() const;
    
    char ComputeLetter();                                           // return the letter grade

    // virtual functions to enable pointer call children function
    virtual double ComputeGrade()=0;                                // pure virtual function, no definition
    virtual ofstream& Print(ofstream& os, int count);               // function to print the grade summary

  
    protected:
    string firstName,
            lastName,
            course;
};

class Biology : public Student
{
    public:
    Biology(string nm, string ln, string cs, int lab, int t1, int t2, int t3, int fe);      // constructor to initialize the Biology data
    
    double ComputeGrade();                                                                  // return the final media of the student
    ofstream& Print(ofstream& os, int count);                                               // print the information for the Biology student
    
    // Accessor's
    int GetTest1() const;
    int GetTest2() const;
    int GetTest3() const;
    int GetLab() const;
    int GetFinalEx() const;
    
    
    private:
    int labGrade,
        test1,
        test2,
        test3,
        finalExam;
};

class Theater : public Student
{
    public:
    Theater(string nm, string ln, string cs, int pt, int mid, int fe);          // constructor to initialize the Theater data
    
    double ComputeGrade();                                                      // return the final media of the student
    ofstream& Print(ofstream& os, int count);                                   // print the information for the theater student
    
    //Accessor's
    int GetPart() const;
    int GetMid() const;
    int GetFinalEx() const;
    
    private:
    int part,
        midterm,
        finalExam;
};

class ComputerScience : public Student
{
    public:
    ComputerScience(string name, string last, string cs, int a1, int a2, int a3, int a4, int a5, int a6, int t1, int t2, int fe);       // constructor to initialize the CS data

    double ComputeGrade();                                                      // return the media of the CS student
    ofstream& Print(ofstream& os, int count);                                   // print the CS student information
    
    //Accessor's
    int GetTest1() const;
    int GetTest2() const;
    int GetFinalEx() const;
    int GetAss1() const;
    int GetAss2() const;
    int GetAss3() const;
    int GetAss4() const;
    int GetAss5() const;
    int GetAss6() const;
    
    private:
    int test1,
        test2,
        finalExam,
        ass1,
        ass2,
        ass3,
        ass4,
        ass5,
        ass6;
};