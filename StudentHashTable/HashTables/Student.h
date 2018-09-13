#pragma once
using namespace std;
class CStudent
{
private:
	int _studentID;
	string _name;
	string _surname;
	int _gpa;

public:
	CStudent();
	~CStudent();
	CStudent(int id, string name, string surname, int gpa);
	friend istream& operator>>(istream& is, CStudent& student);
	friend ostream& operator<<(ostream& os, CStudent& student);
	bool operator==(const CStudent& student) const;
	bool operator!=(const CStudent& student) const;
	bool operator<(const CStudent& student) const;
	int Hash();
	void Display();
};