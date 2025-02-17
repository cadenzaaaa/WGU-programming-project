
#include <string>
#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
using namespace std;

	//Section D1 - Student Class
	Student::Student()
	{
	}

	Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysPerCourse, DegreeProgram degreeProgram) 
	{
		this->studentID = studentID;
		this->firstName = firstName;
		this->lastName = lastName;
		this->emailAddress = emailAddress;
		this->age = age;
		this->daysPerCourse[0] = daysPerCourse[0];
		this->daysPerCourse[1] = daysPerCourse[1];
		this->daysPerCourse[2] = daysPerCourse[2];
		this->degreeProgram = degreeProgram;
	};

	//D2 Getters
	string Student::GetStudentID() {
		return studentID;
	};
	
	string Student::GetFirstName() {
		return firstName;
	};

	string Student::GetLastName() {
		return lastName;
	};

	string Student::GetEmailAddress() {
		return emailAddress;
	};

	int Student::GetAge() {
		return age;
	};

	int* Student::GetDaysPerCourse() {
		return daysPerCourse;
	};

	DegreeProgram Student::GetDegreeProgram() {
		return degreeProgram;
	};

	//D2 setters
	void Student::SetStudentID(string studentID) {
		this->studentID = studentID;
	};

	void Student::SetFirstName(string firstName) {
		this->firstName = firstName;
	};

	void Student::SetLastName(string lastName) {
		this->lastName = lastName;
	};

	void Student::SetEmailAddress(string emailAddress) {
		this->emailAddress = emailAddress;
	};

	void Student::SetAge(int age) {
		this->age = age;
	};

	void Student::SetDaysPerCourse(int courseDays1, int courseDays2, int courseDays3) {
		this->daysPerCourse[0] = daysPerCourse[0];
		this->daysPerCourse[1] = daysPerCourse[1];
		this->daysPerCourse[2] = daysPerCourse[2];
	};

	void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
		this->degreeProgram = degreeProgram;
	};

	//print
	void Student::print() {

		string degreeName = "Software";
		if (GetDegreeProgram() == DegreeProgram::NETWORK) degreeName = "Network";
		if (GetDegreeProgram() == DegreeProgram::SECURITY) degreeName = "Security";

		cout << /*No label needed*/   this->GetStudentID() << '\t';
		cout << "First Name: " << this->GetFirstName() << '\t';
		cout << "Last Name: " << this->GetLastName() << '\t';
		cout << "Age: " << this->GetAge() << '\t';
		cout << "daysInCourse: {" << this->daysPerCourse[0] << ',' << this->daysPerCourse[1] << ',' << this->daysPerCourse[2] << "} ";
		cout << "Degree Program: " << degreeName << endl;

	}

	Student::~Student() {}