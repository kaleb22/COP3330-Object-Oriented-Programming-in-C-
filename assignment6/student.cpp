#include "student.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

Student::Student(string nm, string l, string cs)
{
    firstName = nm;
    lastName = l;
    course = cs;
}

ComputerScience::ComputerScience(string name, string last, string cs, int a1, int a2, int a3, int a4, int a5, int a6, int t1, int t2, int fe) : Student(name, last, cs)
{
    ass1 = a1;
    ass2 = a2;
    ass3 = a3;
    ass4 = a4;
    ass5 = a5;
    ass6 = a6;
    test1 = t1;
    test2 = t2;
    finalExam = fe;

}

Biology::Biology(string nm, string ln, string cs, int lab, int t1, int t2, int t3, int fe) : Student(nm, ln, cs)
{
    labGrade = lab;
    test1 = t1;
    test2 = t2;
    test3 = t3;
    finalExam = fe;
    
}

Theater::Theater(string nm, string ln, string cs, int pt, int mid, int fe) : Student(nm, ln, cs)
{
    part = pt;
    midterm = mid;
    finalExam = fe;
 
}

double Theater::ComputeGrade()
{
    double media1, media2, media3;
    
    media1 = (part * 40) / 100.00;
    media2 = (midterm * 25) / 100.00;
    media3 = (finalExam * 35) / 100.00;
    
    return media1 + media2 + media3;
}

double Biology::ComputeGrade()
{
    double media1, media2, media3, media4, media5;
    
    media1 = (labGrade * 30) / 100.00;
    media2 = (test1 * 15) / 100.00;
    media3 = (test2 * 15) / 100.00;
    media4 = (test3 * 15) / 100.00;
    media5 = (finalExam * 25) / 100.00;
    
    return media1 + media2 + media3 + media4 + media5;
}

double ComputerScience::ComputeGrade()
{
    double media1, media2, media3, media4;
    
    media1 = ((ass1 + ass2 + ass3 + ass4 + ass5 + ass6) * 30 ) / 600.00;
    media2 = (test1 * 20) / 100.00;
    media3 = (test2 * 20) / 100.00;
    media4 = (finalExam * 30) / 100.00;
    
    return media1 + media2 + media3 + media4;
}

ofstream& Student::Print(ofstream& os, int count)
{
    
    if(course == "Biology")
    {
        os << "\nBIOLOGY CLASS" << '\n' << endl;
    }
    else if(course == "Computer Science")
    {
        os << "\nCOMPUTER SCIENCE CLASS" << '\n' << endl;
    }
    else
    {
        os << "\nTHEATER CLASS" << '\n' << endl;
    }
    
    
        // capture current output stream settings
   int oldprecision = os.precision();
   char oldfill = os.fill();
   ios_base::fmtflags oldflags = os.flags();

   // do my output changes
   os.setf(ios::left);
   os << fixed;
   
   
   // print first line
            os.width(40);
            os << "Student";
            os.width(10);
            os <<  "Final";
            os.width(10);
            os << "Final";
            os.width(10);
            os << "Letter" << endl;
    // print second line
    
            os.width(40);
            os << "Name";
            os.width(10);
            os <<  "Exam";
            os.width(10);
            os << "Avg";
            os.width(10);
            os << "Grade" << endl;
            os << "------------------------------------------------------------------" << endl;
            
            
   // PUT THINGS BACK THE WAY THEY WERE WHEN I FOUND THEM
   os.precision(oldprecision);	// restore old precision setting
   os.fill(oldfill);			// restore old fill char setting
   os.flags(oldflags);		// restore all prior format flags
   
   return os;
}

ofstream& ComputerScience::Print(ofstream& os, int count)
{
    if(count == 0)                      // first time
        Student::Print(os, count);
    
    // capture current output stream settings
   int oldprecision = os.precision();
   char oldfill = os.fill();
   ios_base::fmtflags oldflags = os.flags();

   // do my output changes
   os.setf(ios::left);
   os << setprecision(2);
   os << fixed;
   
   char letter = ComputeLetter();
   
   string fullName = firstName + ' ' + lastName;
   
   // print first line
            os.width(40);
            os << fullName;
            os.width(10);
            os <<  finalExam;
            os.width(12);
            os << ComputeGrade();
            os.width(10);
            os << letter;
            
    // PUT THINGS BACK THE WAY THEY WERE WHEN I FOUND THEM
   os.precision(oldprecision);	// restore old precision setting
   os.fill(oldfill);			// restore old fill char setting
   os.flags(oldflags);		// restore all prior format flags
   
   return os;
}

ofstream& Biology::Print(ofstream& os, int count)
{
    if(count == 0)                      // first time
        Student::Print(os, count);

    // capture current output stream settings
   int oldprecision = os.precision();
   char oldfill = os.fill();
   ios_base::fmtflags oldflags = os.flags();

   // do my output changes
   os.setf(ios::left);
   os << setprecision(2);
   os << fixed;
   
   char letter = ComputeLetter();
   
   string fullName = firstName + ' ' + lastName;
   
   // print first line
            os.width(40);
            os << fullName;
            os.width(10);
            os <<  finalExam;
            os.width(12);
            os << ComputeGrade();
            os.width(10);
            os << letter;
            
    // PUT THINGS BACK THE WAY THEY WERE WHEN I FOUND THEM
   os.precision(oldprecision);	// restore old precision setting
   os.fill(oldfill);			// restore old fill char setting
   os.flags(oldflags);		// restore all prior format flags
    
    return os;
}

ofstream& Theater::Print(ofstream& os, int count)
{
    if(count == 0)                      // first time
        Student::Print(os, count);

    // capture current output stream settings
   int oldprecision = os.precision();
   char oldfill = os.fill();
   ios_base::fmtflags oldflags = os.flags();

   // do my output changes
   os.setf(ios::left);
   os << setprecision(2);
   os << fixed;
   
   char letter = ComputeLetter();
   
   string fullName = firstName + ' ' + lastName;
   
   // print first line
            os.width(40);
            os << fullName;
            os.width(10);
            os <<  finalExam;
            os.width(12);
            os << ComputeGrade();
            os.width(10);
            os << letter;
            
    // PUT THINGS BACK THE WAY THEY WERE WHEN I FOUND THEM
   os.precision(oldprecision);	// restore old precision setting
   os.fill(oldfill);			// restore old fill char setting
   os.flags(oldflags);		// restore all prior format flags
    
    return os;
}

string Student::GetName() const
{
    return firstName;
}

string Student::GetLast() const
{
    return lastName;
}

string Student::GetCourse() const
{
    return course;
}

char Student::ComputeLetter()
{
    double media;
    
    media = ComputeGrade();
    
    if(media >= 90)
        return 'A';
    else if(media >= 80 && media < 90)
        return 'B';
    else if(media >= 70 && media < 80)
        return 'C';
    else if(media >= 60 && media < 70)
        return 'D';
    else
        return 'F';
}

int Biology::GetTest1() const
{
    return test1;
}

int Biology::GetTest2() const
{
    return test2;
}

int Biology::GetTest3() const
{
    return test3;
}

int Biology::GetLab() const
{
    return labGrade;
}

int Biology::GetFinalEx() const
{
    return finalExam;
}

int Theater::GetPart() const
{
    return part;
}

int Theater::GetMid() const
{
    return midterm;
}

int Theater::GetFinalEx() const
{
    return finalExam;
}

int ComputerScience::GetAss1() const
{
    return ass1;
}

int ComputerScience::GetAss2() const
{
    return ass2;
}

int ComputerScience::GetAss3() const
{
    return ass3;
}

int ComputerScience::GetAss4() const
{
    return ass4;
}

int ComputerScience::GetAss5() const
{
    return ass5;
}

int ComputerScience::GetAss6() const
{
    return ass6;
}

int ComputerScience::GetTest1() const
{
    return test1;
}

int ComputerScience::GetTest2() const
{
    return test2;   
}

int ComputerScience::GetFinalEx() const
{
    return finalExam;
}