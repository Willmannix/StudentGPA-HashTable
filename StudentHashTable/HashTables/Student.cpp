#include "stdafx.h"
#include "Student.h"


CStudent::CStudent()
	: _studentID(0), _gpa(0), _name(""), _surname("")
{
}


CStudent::~CStudent()
{
}


CStudent::CStudent(int id, string name, string surname, int gpa)
	:_studentID(id), _name(name), _surname(surname), _gpa(gpa)
{
}


int CStudent::Hash()
{
	return (_studentID % 10);
}


void CStudent::Display()
{
	cout << setw(8) << _studentID << setw(15) << _name << setw(15) << _surname << setw(7) << _gpa << endl;
}
istream& operator>> (istream& is, CStudent& student)
{
	is >> student._studentID >> student._name >> student._surname >> student._gpa;
	return is;
}

ostream& operator<< (ostream& os, CStudent& student)
{
	os << setw(8) << student._studentID << setw(15) << student._name << setw(15) << student._surname << setw(10) << student._gpa << endl;
	return os;
}

bool CStudent::operator==(const CStudent& student) const
{
	//will check only student ID, since no two student will have same ID
	return (_studentID == student._studentID ? true : false);
}
bool CStudent::operator!=(const CStudent& student) const
{
	return (_studentID != student._studentID ? true : false);
}

bool CStudent::operator<(const CStudent& student) const
{
	return (_studentID < student._studentID ? true : false);
}
