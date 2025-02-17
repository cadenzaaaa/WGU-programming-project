#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"
using namespace std;


//E1 Define Roster class
class Roster {
private:
	int dataLine = -1;
	const static int numStudents = 5;
public:
		~Roster();
		Student* classRosterArray[numStudents];
		void add(string StudentID, string firstName, string lastName, string emailAddress, int age, int courseDays1, int courseDays2, int courseDays3, DegreeProgram degreeProgram);
		void remove(string StudentID);
		void printAverageDaysInCourse(string StudentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);
		void printAll();
		void parseStudentData(string studentData);
};

#endif