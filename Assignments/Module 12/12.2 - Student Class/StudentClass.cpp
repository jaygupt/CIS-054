/*
 * Name: Jay Gupta
 * Program: StudentClass.cpp (V1.0)
 * Date: 5/4/2020
 * Professor McElroy
 * CIS054 C/C++ Programming  
*/

#include <string>
#include <iostream>
#include <cctype>       // used by isalpha (test for a character)
#include <iomanip>
using namespace std;

class Student
{
private:
    string name;
    int IdNumber;
    double gpa;
    string major; 
public:
    // constructors
    Student();  // default constructor
    Student(string n, int id, double g, string major);

    //mutators and accessors
    void setName(string n);
    string getName();
    void setIdNumber(int id);
    int  getIdNumber();
    void setGpa(double g);
    double getGpa();
    void setMajor(string major); 
    string getMajor(); 
};


// default Student constructor
Student::Student()
{
    name = "";  // set name to an empty string
    IdNumber = 0;
    gpa = 0.0;
    major = ""; // set major to an empty string 
}
// Fully qualified Student constructor
Student::Student(string n, int id, double g, string m)
{
    setName(n);         // use setName to validate data
    setIdNumber(id);    // use setIdNumber to validate data
    setGpa(g);          // use setGpa to validate data
    setMajor(m);        // use setMajor to validate data 
}

//mutators and accessors
void Student::setName(string n)
{
    if ( isupper(n[0]) )   // 1st character of name must be A-Z
        name = n;
    else
        name = "--Bad name entered";
}
string Student::getName()
{
    return name;
}
void Student::setIdNumber(int id)
{
    if ( id>1  && id<100000)   // must be from 0 to 100000
        IdNumber = id;
    else
        IdNumber = 0;          // indicate an illegal selection
}
int  Student::getIdNumber()
{
    return IdNumber;
}
void Student::setGpa(double g)
{
    if (g>=0.0 && g<=4.0)         // gpa must be from 0.0 to 4.0
        gpa = g;
    else {
        gpa = -1; // illegal value 
    }
}
double Student::getGpa()
{
    return gpa;
}
void Student::setMajor(string m) {
    if (isupper(m[0])) {
        major = m; // want first letter, like name, to be capitalized
    } else {
        major = "Invalid major."; 
    }
}
string Student::getMajor() {
    return major; 
}

// define an array of students
Student CIS054[] = {
    Student ("Joe Williams", 42923, 3.4, "CIS"),
    Student ("Sally Washington", 55458, 3.7, "Physics"),
    Student ("Fred MacIntosh", 43252, 2.8, "Ethnic Studies"),
    Student ("Jose De La Cruz", -990, 3.0, "Chemistry"),
    Student ("Dan McElroy", 77777, 4.0, "CIS"),
    Student ("thinh Nguyen", 73657, 5.0, "Geology")
};


int main(int argc, char* argv[])
{
    int NumberOfStudents = sizeof(CIS054)/sizeof(Student);

    // header
    cout << endl << left << "  " << setw(7) << "ID #" << setw(20) << "NAME" << "MAJOR" << endl; 
    cout << "  " << "===========================================" << endl; 

    // Display the header line
     // List all the students in the course
    for (int i=0; i<NumberOfStudents; i++)
        cout << "  " << left << setw(7) << CIS054[i].getIdNumber() << setw(20) << CIS054[i].getName() << CIS054[i].getMajor() << endl; 
    cout << endl;   // blank line after displaying the student names 

    // compute the average gpa of all the students
    double total=0;
    for (int i=0; i<NumberOfStudents; i++)
        total += CIS054[i].getGpa();
    double average = total / NumberOfStudents;
    cout << "  " << "The average GPA of all the students is " << average << endl;

    // error detection
    for (int i = 0; i < NumberOfStudents; i++) {
        if (CIS054[i].getIdNumber() == 0) {
            // illegal value for id 
            cout << "  Illegal ID value for " << CIS054[i].getName() <<  "!" << endl; 
        } 

        if (CIS054[i].getGpa() == -1) {
            // illegal value for GPA
            cout << "  Illegal GPA value for " << CIS054[i].getName() << "!" << endl; 
        }
    }

    cout << endl; 
    
	return 0;
}
