#include<iostream>
#include<string>
#include <iomanip> 
using namespace std;
#include "roster.h"
#include "student.h"

int main() {
	const int numStudents = 5;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Caden,Jean,cjean31@wgu.edu,21,36,39,44,SOFTWARE"
	};

	cout << "\n====================================================================" << endl;
	cout << "           C867 - Scripting and Programming Applications	           " << endl;
	cout << "                         Language: C++                                " << endl;
	cout << "                      Student ID: #010723936	                       " << endl;
	cout << "                          Caden Jean                                  " << endl;
	cout << "====================================================================\n" << endl;

	Roster classRoster;

	for (int i = 0; i < numStudents; ++i)
	{
		classRoster.parseStudentData(studentData[i]);
	}

	cout << "\n====================================================================" << endl;
	cout << "                           Class Roster                               " << endl;
	cout << "====================================================================\n" << endl;
	classRoster.printAll();
	cout << "\n====================================================================" << endl;
	cout << "                          Invalid Emails                              " << endl;
	cout << "====================================================================\n" << endl;
	classRoster.printInvalidEmails();
	cout << "\n====================================================================" << endl;
	cout << "                        Average Days In Course                        " << endl;
	cout << "====================================================================\n" << endl;

	int i = 0;
	while (i < numStudents)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
		i++;
	}

	cout << "\n====================================================================" << endl;
	cout << "                         By Degree Program                            " << endl;
	cout << "====================================================================\n" << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << "\n====================================================================" << endl;
	cout << "                             Remove A3                                " << endl;
	cout << "====================================================================\n" << endl;
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	cout << "\n====================================================================" << endl;
	cout << "    Attempting to remove Student with ID A3: error occured            " << endl;
	cout << "====================================================================\n" << endl;

	classRoster.~Roster();

	return 0;
}