#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
	Node() : data(0), previousLink(NULL), nextLink(NULL) {}
    Node (int theData, Node *previous, Node *next)
            : data(theData), nextLink(next), previousLink(previous) {}
    Node *getNextLink( ) const { return nextLink; }
    Node *getPreviousLink( ) const { return previousLink; }
    int getData( ) const { return data; }
    void setData(int theData) { data = theData; }
    void setNextLink(Node *pointer) { nextLink = pointer; }
    void setPreviousLink(Node *pointer) { previousLink = pointer; }
	~Node(){}
private:
    int data;
    Node *nextLink;
    Node *previousLink;
};


class DoublyList
{
public:
	DoublyList(); 	

	void insertBack(int newData);

	void print() const;
	void reversePrint() const;

	void destroyList();
	~DoublyList();

	// Function declaration
	void switchEveryTwo();

private:
    Node *first;	
    Node *last;		
	int count;		
};

#endif