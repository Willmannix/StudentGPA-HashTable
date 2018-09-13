#include "stdafx.h"
#include "Student.h"
#include "HashTable.h"


CHashTable::CHashTable()
	:_items(0)
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		_table[i] = new OrderedList < CStudent > ;
	}
}


CHashTable::~CHashTable()
{
	MakeEmpty();
}





void CHashTable::InsertItem(CStudent item)
{
	int location = item.Hash();
	if (_table[location] == nullptr)
		_table[location] = new OrderedList<CStudent>;
	if (!(_table[location]->IsFull()))
	{
		_table[location]->InsertItem(item);
		_items++;
	}
	
}
void CHashTable::DeleteItem(CStudent stud, bool& deleted)
{
	int location = stud.Hash();
	if (_table[location] != nullptr)
		if (_table[location]->DeleteItem(stud))
		{
			_items--;
			deleted = true;
		}
		
		else
			deleted = false;
}

void CHashTable::RetrieveItem(CStudent& item, bool& found)
{
	int location = item.Hash();
	if (_table[location] != nullptr)
		_table[location]->RetrieveItem(item, found);
	else
		found = false;
}

int CHashTable::GetNumOfElements()
{
	//int total = 0;
	//for (int i = 0; i < MAX_ITEMS; i++)
	//{
	//	if (_table[i]!=nullptr)
	//		total += _table[i]->LengthIs();
	//}
	return _items;
}
void CHashTable::MakeEmpty()
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (_table[i] != nullptr)
			_table[i]->MakeEmpty();
		delete _table[i];
		_table[i] = nullptr;
	}
}
void CHashTable::Print()
{
	for (int i = 0; i < MAX_ITEMS; i++)
	{
		if (_table[i] != nullptr)
			_table[i]->PrintList();
	}
}