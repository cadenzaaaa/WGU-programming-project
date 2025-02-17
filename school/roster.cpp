
#include <iostream>
#include <string>
#include <map>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Caden,Jean,cjean31@wgu.edu,21,36,39,44,SOFTWARE"
	};

	void Roster::parseStudentData(string studentData)
	{
		// Parse student ID
		int pos1 = studentData.find(",");
		string studentID = studentData.substr(0, pos1);

		// Parse first name
		int pos2 = pos1 + 1;
		pos1 = studentData.find(",", pos2);
		string firstName = studentData.substr(pos2, pos1 - pos2);

		// Parse last name
		pos2 = pos1 + 1;
		pos1 = studentData.find(",", pos2);
		string lastName = studentData.substr(pos2, pos1 - pos2);

		// Parse email
		pos2 = pos1 + 1;
		pos1 = studentData.find(",", pos2);
		string emailAddress = studentData.substr(pos2, pos1 - pos2);

		// Parse age
		pos2 = pos1 + 1;
		pos1 = studentData.find(",", pos2);
		int age = stoi(studentData.substr(pos2, pos1 - pos2));

		// Parse days in course 1
		pos2 = pos1 + 1;
		pos1 = studentData.find(",", pos2);
		int courseDays1 = stoi(studentData.substr(pos2, pos1 - pos2));

		// Parse days in course 2
		pos2 = pos1 + 1;
		pos1 = studentData.find(",", pos2);
		int courseDays2 = stoi(studentData.substr(pos2, pos1 - pos2));

		// Parse days in course 3
		pos2 = pos1 + 1;
		pos1 = studentData.find(",", pos2);
		int courseDays3 = stoi(studentData.substr(pos2, pos1 - pos2));

		// Parse degree program
		pos2 = pos1 + 1;
		pos1 = studentData.find('/0', pos2);
		DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
		if (studentData.substr(pos2, pos1 - pos2) == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}
		else if (studentData.substr(pos2, pos1 - pos2) == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
		}
	
	//Add data to roster
	add(studentID, firstName, lastName, emailAddress, age, courseDays1, courseDays2, courseDays3, degreeProgram);
}; 

//Set variables
void Roster::add(string StudentID, string firstName, string lastName, string emailAddress, int age, int courseDays1, int courseDays2, int courseDays3, DegreeProgram degreeProgram)
{

		int daysPerCourse[3] = { courseDays1, courseDays2, courseDays3 };

		classRosterArray[++dataLine] = new Student(StudentID, firstName, lastName, emailAddress, age, daysPerCourse, degreeProgram);

}

//Remove student from studentData table
void Roster::remove(string StudentID)
{
		bool StudentFound = false;
		for (int i = 0; i < dataLine; ++i) {
			if (classRosterArray[i]->GetStudentID() == StudentID) {

				//Found the student and will now remove them by moving elements up
				StudentFound = true;
				for (int j = 0; j < dataLine; ++j) {
					classRosterArray[j] = classRosterArray[j + 1];
				}
				dataLine--;
				cout << "Student with " << StudentID << " was removed from roster!" << endl;
			}
		}

		if (StudentFound == false) {
			cout << "Student ID was not found!" << endl;
		}
}

//Print studentData
void Roster::printAll() 
{
	for (int i = 0; i <= dataLine; ++i) {
			classRosterArray[i]->print();
		}
}

//Get the average of days it took to complete a single class for each student
void Roster::printAverageDaysInCourse(string StudentID) 
{
	int  maxDays = 3;
	float avgDaysPerCourse = 0.0;

	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == StudentID) {
			int* daysPerCourse = classRosterArray[i]->GetDaysPerCourse();
			for (int j = 0; j < maxDays; j++) {
				avgDaysPerCourse += daysPerCourse[j];
			}
			
			cout << "Student ID: " << classRosterArray[i]->GetStudentID() << ", has an average of " << (avgDaysPerCourse / maxDays) << "days per course." << endl;
		}
	}
}

//Check if email is valid
void Roster::printInvalidEmails() 
{
	for (int i = 0; i < numStudents; ++i)
	{
		string email = classRosterArray[i]->GetEmailAddress();
		
		if ((email.find('@') == string::npos ) || (email.find('.') == string::npos) || (email.find(' ') != string::npos))
		{
			cout << email << " is not a valid email." << endl;
		}
	}
}

//Print student information for a degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < numStudents; ++i) 
	{
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
		}
	}
}

//Delete roster
Roster::~Roster()
{
	for (int i = 0; i < dataLine; ++i) 
	{
		delete classRosterArray[i];
	}
}