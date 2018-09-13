

template <class T>
struct Node
{
	T info;
	Node<T>* next;
};



template <class T>
class OrderedList
{
private:
	Node<T>* listFront;
	int length;
	Node<T>* currentPos;

public:
	OrderedList();
	~OrderedList();
	bool IsFull() const;
	int LengthIs() const;
	void MakeEmpty();
	void RetrieveItem(T& item, bool& found);
	void InsertItem(T item);
	bool DeleteItem(T item);
	void ResetList();
	void GetItemAtCurrPos(T& item);
	void MoveCurrPosNext();
	void GetNextItem(T& item);
	bool PrintList();
};

template <class T>
OrderedList<T>::OrderedList()
{
	currentPos = listFront = nullptr;
	length = 0;
}
 template <class T>
 OrderedList<T>::~OrderedList()
 {
	 MakeEmpty();
 }
 
template <class T>
bool OrderedList<T>::IsFull() const
{
	Node<T>* temp = new Node<T>();
	if (temp == nullptr)
		return true;
	else
	{
		delete temp;
		return false;
	}
}

template <class T>
int OrderedList<T>::LengthIs() const
{
	return length;
}

template <class T>
void OrderedList<T>::MakeEmpty()
{
	Node<T>* temp;
	while (listFront != nullptr)
	{
		temp = listFront;
		listFront = listFront->next;
		delete temp;
	}
	length = 0;
}

template <class T>
void OrderedList<T>::RetrieveItem(T& item, bool& found)
{
	Node<T>* location = listFront;
	bool moreToSearch = location != nullptr;
	found = false;

	while (moreToSearch && !found)
	{
		if (location->info < item)
		{
			location = location->next;
			moreToSearch = location != nullptr;
		}
		else if (location->info == item)
		{
			found = true;
			item = location->info;
		}
		else
		{
			moreToSearch = false;
		}
	}
}

template <class T>
void OrderedList<T>::InsertItem(T item)
{
	Node<T>* newNode = new Node<T>();
	Node<T>* predLoc = nullptr;
	Node<T>* location = listFront;

	newNode->info = item;

	bool moreToSearch = location != nullptr;
	while (moreToSearch)
	{
		if (location->info < item)
		{
			predLoc = location;
			location = location->next;
			moreToSearch = location != nullptr;
		}
		else
			moreToSearch = false;
	}
	//if first item in the list
	if (predLoc == nullptr)
	{
		newNode->next = listFront;
		listFront = newNode;
	}
	else
	{
		newNode->next = location;
		predLoc->next = newNode;
	}
	length++;
}

template <class T>
bool OrderedList<T>::DeleteItem(T item)
{
	Node<T>* predLoc = nullptr; 
	Node<T>* location = listFront;
	bool deleted = false, moreToSearch = location != nullptr;

	while (moreToSearch)
	{
		if (location->info < item)
		{
			predLoc = location;
			location = location->next;
			moreToSearch = location != nullptr;
		}
		else if (location->info == item)
		{
			if (predLoc != nullptr)
				predLoc->next = location->next;
			else
				listFront = location->next;
			delete location;
			location = listFront;
			length--;
			deleted = true;
		}
		else
			moreToSearch = false;
	}
	return deleted;
}

template <class T>
void OrderedList<T>::ResetList()
{
	currentPos = listFront;
}

template <class T>
void OrderedList<T>::GetItemAtCurrPos(T& item)
{
	if (currentPos != nullptr)
		item = currentPos->info;
	else
		cout << "List is empty\n";
}
template <class T>
void OrderedList<T>::GetNextItem(T& item)
{
	if (currentPos == nullptr)
		ResetList();

	currentPos = currentPos->next;
	item = currentPos->info;
}

template <class T>
bool OrderedList<T>::PrintList()
{
	if (listFront == nullptr)
		return false;
	else
	{
		Node<T>* temp = listFront;
		while (temp != nullptr)
		{
			cout << temp->info;
			temp = temp->next;
		}
	}
}
template <class T>
void OrderedList<T>::MoveCurrPosNext()
{
	if (currentPos != nullptr)
		currentPos = currentPos->next;
}