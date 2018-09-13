
#include "stdafx.h"
#include "Student.h"
#include "HashTable.h"
#include <Windows.h>

using namespace std;
void DisplayMenu();
int Menu();
CHashTable* CreateHashTable(CHashTable *table);
void ClearHashTable(CHashTable *table);
void AddToHashTable(CHashTable *table);
void RemoveDataFromHT(CHashTable *table);
void PrintHashTable(CHashTable *table);
void SearchHashTable(CHashTable *table);
void ContinueOrExit(bool &exit, bool &another);
void LoadFromFile(CHashTable *table);
void gotoxy(int x, int y);

bool quitFlag = false;
int _tmain(int argc, _TCHAR* argv[])
{
	DisplayMenu();
	return 0;
}

void LoadFromFile(CHashTable *table)
{
	//
	//	to load students from file uncomment line 60
	//
	int id;
	string name, surname;
	ifstream infile("data2.txt");
	while (!infile.eof())
	{
		infile >> name >> surname >> id;
		table->InsertItem(CStudent(id, name, surname, 0));
	}
}


CHashTable* CreateHashTable(CHashTable *table)
{
	system("cls");
	if (table != nullptr)
	{
		cout << "\n\t\tThere is a Hash Table created\n\t\tGo and use it!";
		cin.get(); cin.get();
		return table;
	}
	else
	{
		CHashTable *table = new CHashTable();
		if (table != nullptr)
			cout << "\n\tGreat, table created!";
		cin.get(); cin.get();
		LoadFromFile(table);
		return table;
	}
	
	cin.get(); cin.get();
}


void ClearHashTable(CHashTable *table)
{
	system("cls");
	if (table == nullptr)
	{
		system("cls");
		cout << "\n\t\tThere is no Hash Table created\n\t\tGo and create it first!";
	}
	else
	{
		if (table->GetNumOfElements() != 0)
			table->MakeEmpty();
		if (table->GetNumOfElements() == 0)
			cout << "\n\tTable is now empty!";
	}
	cin.get(); cin.get();
	
}
void AddToHashTable(CHashTable *table)
{
	bool exit, another;

	if (table == nullptr)
	{
		system("cls");
		cout << "\n\t\tThere is no Hash Table created\n\t\tGo and create it first!";
		cin.get(); cin.get();
	}
	else
	{
		
		string name, surname;
		int id = 1, gpa;
		
		while (true)
		{
			system("cls");
			cout << "\n\t\tEnter Student Details\n";
			cout << "-------------------------------------------------------------------------------\n\n";
			cout << "\tPress 0 to cancel\n\n";
			exit = false;
			another = false;
			do
			{
				cout << "\tEnter student ID: ";
				cin >> id;

				if (id == 0)
					break;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}

				if (id < 10000 || id > 100000)
					cout << "\n\t\tStudent ID must be five digit number!\n";
			} while (id > 100000 || id < 10000);
			if (id == 0)
				break;
			cout << "\tEnter student name: ";
			cin >> name;
			if (name == "0")
				break;
			cout << "\tEnter student surname: ";
			cin >> surname;
			if (surname == "0")
				break;
			do
			{
				cout << "\tEnter student gpa: ";
				cin >> gpa;
				if (gpa == 0)
					break;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
				if (gpa < 0 || gpa > 100)
				{
					cout << "\n\t\tGPA is positive number between 0 and 100!\n";
				}

			} while (gpa < 0 || gpa > 100);
			if (gpa == 0)
				break;
			table->InsertItem(CStudent(id, name, surname, gpa));
			cout << "\n\tStudent successfully added.\n\tPress ENTER to add another student\n\tor ESC to exit.";
			Sleep(1000);
			
			ContinueOrExit(exit, another);
			if (exit)
				break;
		}
	}
}
void ContinueOrExit(bool &exit, bool &another)
{
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) < 0)
			exit = true;
		if (GetAsyncKeyState(VK_RETURN) < 0)
			another = true;
		if (exit || another)
			break;
		Sleep(100);
	}
}
void RemoveDataFromHT(CHashTable *table)
{
	system("cls");
	if (table == nullptr)
		cout << "\n\t\tThere is no Hash Table created\n\t\tGo and create it first!";
	else if (table->GetNumOfElements() == 0)
		cout << "\n\t\tThere are no records in the table";
	else
	{
		cout << "\n\t\tEnter Student Details\n";
		cout << "-------------------------------------------------------------------------------\n\n";
		cout << "\tPress 0 to cancel\n\n";
		int id;
		do
		{
			cout << "\tEnter student ID: ";
			cin >> id;

			if (id == 0)
				break;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}

			if (id < 10000 || id > 100000)
				cout << "\n\t\tStudent ID must be five digit number!\n";
		} while (id > 100000 || id < 10000);
		if (id == 0)
			return;
		CStudent stud(id, "", "", 0);
		bool found;
		table->RetrieveItem(stud, found);
		if (found)
		{
			cout << endl << endl << setw(8) << "ID" << setw(15) << "Name" << setw(15) << "Surname" << setw(10) << "Gpa" << endl;
			cout << "-------------------------------------------------------------------------------\n\n";
			cout << stud;
			cout << "\n\n\tAre you sure want to delete it? (y/n)";
			char choice;
			cin >> choice;
			if (choice != 'n' || choice != 'N')
			{
				bool deleted;
				table->DeleteItem(CStudent(id, "", "", 0), deleted);
				if (deleted)
					cout << "\n\tRecord Successfully Deleted";
			}
		}
		else
			cout << "\n\tThere is no student with such an ID";
		
		
	}
	cin.get(); cin.get();


}
void PrintHashTable(CHashTable *table)
{
	system("cls");
	
	if (table == nullptr)
		cout << "\n\t\tThere is no Hash Table created\n\t\tGo and create it first!";
	else if (table->GetNumOfElements() == 0)
		cout << "\n\t\tThere are no records in the table";
	else 
	{
		cout << endl << endl << setw(8) << "ID" << setw(15) << "Name" << setw(15) << "Surname" << setw(10) << "Gpa" << "\tTotal Records: " << table->GetNumOfElements()<< endl;
		cout << "-------------------------------------------------------------------------------\n\n";
		table->Print();
		gotoxy(0, 1);
	}
	cin.get(); cin.get();
}


void SearchHashTable(CHashTable *table)
{
	system("cls");
	if (table == nullptr)
	{
		cout << "\n\t\tThere is no Hash Table created\n\t\tGo and create it first!";
		cin.get(); cin.get();
	}
	else if (table->GetNumOfElements() == 0)
	{
		cout << "\n\t\tThere are no records in the table";
		cin.get(); cin.get();
	}
	else
	{
		bool exit, another;
		while (true)
		{
			system("cls");
			exit = false;
			another = false;
			cout << "\n\t\tEnter Student Details\n";
			cout << "-------------------------------------------------------------------------------\n\n";
			cout << "\tPress 0 to cancel\n\n";
			int id;
			do
			{
				cout << "\tEnter student ID: ";
				cin >> id;

				if (id == 0)
					break;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}

				if (id < 10000 || id > 100000)
					cout << "\n\t\tStudent ID must be five digit number!\n";
			} while (id > 100000 || id < 10000);
			if (id == 0)
				break;
			CStudent stud(id, "", "", 0);
			bool found;
			table->RetrieveItem(stud, found);
			if (found)
			{
				cout << endl << endl << setw(8) << "ID" << setw(15) << "Name" << setw(15) << "Surname" << setw(10) << "Gpa" << endl;
				cout << "-------------------------------------------------------------------------------\n\n";
				cout << stud;
			}
			else
				cout << "\n\tThere is no student with such an ID";
			cout << "\n\tPress ENTER to do another search\n\tor ESC to exit.";
			Sleep(1000);
			ContinueOrExit(exit, another);
			if (exit)
				break;
		}
	}
}

void DisplayMenu()
{
	CHashTable *table = nullptr;
	do
	{
		system("cls");
		switch (Menu())
		{
		case 1:
			table = CreateHashTable(table);
			break;
		case 2:
			ClearHashTable(table);
			break;
		case 3:
			AddToHashTable(table);
			break;
		case 4:
			RemoveDataFromHT(table);
			break;
		case 5:
			PrintHashTable(table);
			break;
		case 6:
			SearchHashTable(table);
			break;
		case 7:
			quitFlag = true;
			if (table!=nullptr)
			{
				table->MakeEmpty();
				delete table;
			}
			break;
		default:
			cout << "\n\tInvalid option!";
			cin.ignore(); cin.ignore();
		}
		
	} while (!quitFlag);

}
int Menu()
{
	int option;
	do{
		system("cls");
		cout << "\n\n\t1. Create Hash Table\n"
			<< "\t2. Clear Hash Table\n"
			<< "\t3. Add a Record\n"
			<< "\t4. Delete a Record\n"
			<< "\t5. Print all records\n"
			<< "\t6. Search for a record\n"
			<< "\n\t7. Quit\n"
			<< "\n\tYour option: ";

		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
	} while (cin.fail());

	return option;
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}