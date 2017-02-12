/*
	Fazeli, Bijan
	Lauguico, Nicolo Marco

	CS A200
	February 12, 2017

	Lab 2
*/

#include "DoublyList.h"

// Function pseudocode
/**
func switchEveryTwo
	If there are two or more nodes
		if the size of the list is even
			Switch every other node (starting with the first node) with the next node
		else
			Bring the last node to the front of the list and switch every other node (starting with the second node)
			with the next node.
*/

// Function definition
void DoublyList::switchEveryTwo()
{
	Node * temp = first;
	if (count == 2)
	{
		first = last;
		first->setNextLink(temp);
		first->setPreviousLink(NULL);
		last = temp;
		last->setPreviousLink(first);
		last->setNextLink(NULL);
	}
	else if (count >= 2)
	{
		if (count % 2 != 0)		// Check to see if the list has odd elements, then bring the last node to the front
		{
			temp->setPreviousLink(last);
			last->getPreviousLink()->setNextLink(nullptr);

			last->setNextLink(first);
			last = last->getPreviousLink();

			temp->getPreviousLink()->setPreviousLink(nullptr);
			first = temp->getPreviousLink();
		}
		while (temp != NULL)	// Loop through the list
		{
			if (temp == first)		// Swap the first two nodes
			{
				temp->setPreviousLink(temp->getNextLink());
				temp->getPreviousLink()->setPreviousLink(NULL);
				temp->setNextLink(temp->getNextLink()->getNextLink());
				temp->getPreviousLink()->setNextLink(temp);
				temp->getNextLink()->setPreviousLink(temp);

				first = temp->getPreviousLink();
			}
			else if (temp->getNextLink() != last)		// Swap every other node in the middle
			{
				temp->getPreviousLink()->setNextLink(temp->getNextLink());
				temp->getNextLink()->setPreviousLink(temp->getPreviousLink());
				temp->setPreviousLink(temp->getNextLink());
				temp->setNextLink(temp->getPreviousLink()->getNextLink());
				temp->getPreviousLink()->setNextLink(temp);
				temp->getNextLink()->setPreviousLink(temp);
			}
			else		// Swap the last two nodes
			{
				temp->getPreviousLink()->setNextLink(temp->getNextLink());
				temp->getNextLink()->setPreviousLink(temp->getPreviousLink());
				temp->setPreviousLink(temp->getNextLink());
				temp->getPreviousLink()->setNextLink(temp);
				temp->setNextLink(nullptr);

				last = temp;
			}
			temp = temp->getNextLink();
		}
	}
}
