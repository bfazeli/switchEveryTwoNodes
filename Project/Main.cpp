/***********************************************

	Class DoublyList

************************************************/

#include "DoublyList.h"

#include <iostream>
using namespace std;

int main()
{
	DoublyList l;
	for (int i = 0; i < 21; i++)
	{
		l.insertBack(i);
	}
	l.print();
	l.switchEveryTwo();
	l.print();
	l.reversePrint();


	cout << endl;
	system("Pause");
	return 0;
}

