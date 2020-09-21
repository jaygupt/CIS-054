/**
 * Jay Gupta
 * 5/14/2020
 * Program: Derived-Class.cpp (V1.0)
 * CIS 054 C/C++ Programming 
*/

#include <iostream>
#include <cstring>
using namespace std;

////////////// Person class Definition /////////////////
class Person {
protected:  // A derived class can access protected data
    char Name[20];
public:
    Person (const char* n)
    {
        // choose the version of strcpy for your compiler
        // comment out the other version
//      strcpy_s(Name, n);  // for Microsoft
        strcpy  (Name, n);  // for everywhere except Microsoft
    }
    virtual void print() const
    {
        cout << "Person:  " << Name << endl;
    }
};

///////////// Student class Definition //////////////
class Student : public Person  {
private:
    int    units;
public:
    // Student constructor gets name from Person class
    Student (const char* n, int u) : Person ( n)
    {
        units = u;
    }
    virtual void print() const
    {
        cout << "Student: " << Name << "  Units: " << units << endl;
    }
};

//////////// Teacher class Definition /////////////////
class Teacher : public Person  {
	private:
		int    numberOfStudents;
		int	   numberOfClasses;
	public:
        // Teacher constructor gets 'name' from the Person class
		Teacher (const char* n, int s, int c) : Person ( n)
		{
			numberOfStudents = s;
			numberOfClasses = c;
		}
		virtual void print() const
		{
			cout << "Teacher: " << Name 
				<< "  Students: " << numberOfStudents 
				<< "  Classes: " << numberOfClasses << endl;
		}
};

/////////// Employee Class Definition /////////////////
class Employee : public Person  {
	private:
		int EmpNo; // Employee Number 
		double hours; 
        double payRate; 
        double totalPay;  
	public:
        // Employee constructor gets 'name' from the Person class
		Employee (const char* n, int eN, double h, double pR) : Person (n)
		{
			EmpNo = eN; 
            hours = h; 
            payRate = pR;
            totalPay = hours * payRate; 
		}
		virtual void print() const 
		{  
			cout << "Employee: " << Name  
                 << "  ID: " << EmpNo
				 << "  Total Pay: " << totalPay << endl;
		}
};

/////////// main program ///////////////////////
int main(int argc, char* argv[])
{
    // create objects from several different types of classes
	Student s1("Joe Williams", 12);
	Student s2("Mary Smith  ", 9);
	Student s3("Tam  Nguyen ", 10);
	Student s4("Jose Chavez ", 11);
	Teacher t1("Dan McElroy ", 28, 3);
	Teacher t3("Fred Jones  ", 18, 2);

    // OBJECTS FROM EMPLOYEE CLASS
    Employee e1("Joey Smith", 123, 35.91, 27.95); 
    Employee e2("Lance Armpy", 456, 44.7, 48.25); 

	// Create an array of pointers to different people
	// NOTE: The array of pointers is not in the same order as the above list
	Person *List[] = {&s2, &s3, &s4, &s2, &t1, &t3, &e1, &e2};	
	int SizeOfList = sizeof(List)/sizeof(Person*);
    
    cout << endl; 
	for (int i=0; i<SizeOfList; i++)
	{
		// call the appropriate virtual print routine based
		// on the type of object being pointed to
        if (i == 4 || i == 6) {
            cout << endl; 
        }
		List[i]->print();
	}
    cout << endl; 
	return 0;
}
