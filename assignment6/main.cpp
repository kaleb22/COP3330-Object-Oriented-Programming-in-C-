#include "student.cpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string fname, lname, course, trash;                                                 // variables for the first name, last name and course
    int size;
    int test1, test2, test3, finalExam, ass1, ass2, ass3, ass4, ass5, ass6;             // variables for the grades
    int numA = 0, numB = 0, numC = 0, numD = 0, numF = 0;                               // counters for the grades
    string fileInput, fileOutput;                                                       // name of the files


    cout << "Please, enter the name of the file input\n";
    cout << "File name: ";
    cin >> fileInput;
    cout << "Please enter the name of the output file\n";
    cout << "File name: ";
    cin >> fileOutput;
    
    ifstream myFile (fileInput.c_str());                                      // Open the file
    ofstream output;
    
    if(myFile.is_open())
    {
        myFile >> size;
        myFile.ignore();
        
        Student** std = new Student*[size];                         // creates an array of pointers
        
        for(int i = 0; i < size; i++)
        {

            getline(myFile, lname, ',');
            myFile.ignore();                                        // for the white space after colon
            getline(myFile, fname);
            getline(myFile, course, ' ');

            if(course == "Computer")
            {
                getline(myFile, trash, ' ');                // discard Science
                course = "Computer Science";
                myFile >> ass1 >> ass2 >> ass3 >> ass4 >> ass5 >> ass6 >> test1 >> test2 >> finalExam;
                myFile.ignore();

                std[i] = new ComputerScience (fname, lname, course, ass1, ass2, ass3, ass4, ass5, ass6, test1, test2, finalExam);
            }
            else if(course == "Biology")
            {
                myFile >> ass1 >> test1 >> test2 >> test3 >> finalExam;
                myFile.ignore();
                
                std[i] = new Biology(fname, lname, course, ass1, test1, test2, test3, finalExam);
            }
            else
            {
                myFile >> ass1 >> test1 >> finalExam;
                myFile.ignore();
                
                std[i] = new Theater(fname, lname, course, ass1, test1, finalExam);
            }
        }
        
        myFile.close();                                                         // close the conection with the file
            
        output.open(fileOutput.c_str());                                        // open the file
        
        output << "Student Grade Summary" << '\n';                              // print the
        output << "----------------------" << "\n";                             // header
        
        int count = 0;
        
        for(int i = 0; i < size; i++)                                           // loop for all Biology Students
        {
            string cs = std[i]->GetCourse();
            
            if(cs == "Biology")
            {
                std[i]->Print(output, count) << endl;
                count = 1;
                char l = std[i]->ComputeLetter();
                
                if(l == 'A')
                    numA++;
                else if (l == 'B')
                    numB++;
                else if(l == 'C')
                    numC++;
                else if(l == 'D')
                    numD++;
                else
                    numF++;
            }
        }
        
        count = 0;
        
        for(int i = 0; i < size; i++)                                           // loop for all the Theater students
        {
            string cs = std[i]->GetCourse();
            
            if(cs == "Theater")
            {
                std[i]->Print(output, count) << endl;
                count = 1;
                char l = std[i]->ComputeLetter();
                
                if(l == 'A')
                    numA++;
                else if (l == 'B')
                    numB++;
                else if(l == 'C')
                    numC++;
                else if(l == 'D')
                    numD++;
                else
                    numF++;
            }
            
        }
        
        count = 0;
        
        for(int i = 0; i < size; i++)                                       // loop for all Computer Science students
        {
            string cs = std[i]->GetCourse();
            
            if(cs == "Computer Science")
            {
                std[i]->Print(output, count) << endl;
                count = 1;
                char l = std[i]->ComputeLetter();                   // pick up the letter to increase the num variable
                
                if(l == 'A')
                    numA++;
                else if (l == 'B')
                    numB++;
                else if(l == 'C')
                    numC++;
                else if(l == 'D')
                    numD++;
                else
                    numF++;
            }
            
        }
        
        // Print bottom summary
        output << "\n\nOVERALL GRADE DISTRIBUTION\n\n";
        output << "A: " << numA << '\n';
        output << "B: " << numB << '\n';
        output << "C: " << numC << '\n';
        output << "D: " << numD << '\n';
        output << "F: " << numF;
        
        output.close();                                         // close conection with the file
        
        for(int i = 0; i < size; i++)                           // loop to delete the pointers in the array
            delete std[i];                                      // delete the pointers
        
        delete [] std;                                          // de-allocate the memory used by the array
    }
    else
        output << "Unable to open document";                    // Error, not able to open the file


    return 0;
}