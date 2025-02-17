#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;


//section D1 - Define Student Class
class Student {
public:
	//D2d - Constructor
			Student();
			Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysPerCourse, DegreeProgram degreeProgram);
			~Student();

			//D2a - Accessors 
			string GetStudentID();
			string GetFirstName();
			string GetLastName();
			string GetEmailAddress();
			int GetAge();
			int* GetDaysPerCourse();
			DegreeProgram GetDegreeProgram();

			// D2b - Mutators
			void SetStudentID(string studentID);
			void SetFirstName(string firstName);
			void SetLastName(string lastName);
			void SetEmailAddress(string emailAddress);
			void SetAge(int age);
			void SetDaysPerCourse(int courseDays1, int courseDays2, int courseDays3);
			void SetDegreeProgram(DegreeProgram degreeProgram);

			//Section D2e - print
			void print(); 

private:
			string studentID;
			string firstName;
			string lastName;
			string emailAddress;
			const static int numCourses = 3;
			int daysPerCourse[numCourses];
			int age;
			DegreeProgram degreeProgram;
};

#endif