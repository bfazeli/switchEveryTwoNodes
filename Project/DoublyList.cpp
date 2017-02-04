#include "DoublyList.h"

DoublyList::DoublyList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

void DoublyList::insertBack(int newData)
{
	Node *newNode = new Node(newData, last, nullptr);

	if (first == nullptr)
	{
		first = newNode;
	}
	else
	{
		last->setNextLink(newNode);
		newNode->setPreviousLink(last);
	}

	last = newNode;

	++count;
}

void DoublyList::print() const
{
	if (count == 0)
		cerr << "List is empty. Cannot print." << endl;
	else
	{
		Node *temp = first;

		while (temp != nullptr)
		{
			cout << temp->getData() << " ";
			temp = temp->getNextLink();
		}
		cout << endl;
	}
}

void DoublyList::reversePrint() const
{
	if (count == 0)
		cerr << "List is empty. Cannot print." << endl;
	else
	{
		Node *temp = last;

		while (temp != nullptr)
		{
			cout << temp->getData() << " ";
			temp = temp->getPreviousLink();
		}
		cout << endl;
	}
}

void DoublyList::destroyList()
{
	Node *temp = first;

	while (first != nullptr)
	{
		first = first->getNextLink();
		delete temp;
		temp = first;
	}

	count = 0;
}

DoublyList::~DoublyList()
{
	destroyList();
}
