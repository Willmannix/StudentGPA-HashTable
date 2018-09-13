#pragma once
#include "OrderedLinkedList.h"
using namespace std;


const int MAX_ITEMS = 10;
//CStudent empty(-1, "", "", 0);
//CStudent deleted(-2, "", "", 0);


class CHashTable
{
public:
	CHashTable();
	~CHashTable();
private:
	int _items;
	OrderedList<CStudent> *_table[MAX_ITEMS];
	
public:
	void InsertItem(CStudent item);
	void RetrieveItem(CStudent& student, bool& found);
	void DeleteItem(CStudent stud, bool& deleted);
	int GetNumOfElements();
	void MakeEmpty();
	void Print();
};

