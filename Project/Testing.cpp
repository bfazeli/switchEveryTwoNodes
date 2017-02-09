#include "Testing.h"

#include <iostream>
#include <vector>
using namespace std;

vector< vector<int>> v = { { 1, 2 },
{ 1, 2, 3, 4 },
{ 1, 2, 3, 4, 5, 6 },
{ 1, 2, 3, 4, 5, 6, 7, 8 },
{ 1, 2, 3 },
{ 1, 2, 3, 4, 5 },
{ 1, 2, 3, 4, 5, 6, 7 , 8, 9 },
{ 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85 },
{ 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90 },
};

void test_cases()
{
	int sizeV = static_cast<int>(v.size());

	for (int i = 0; i < sizeV; ++i)
	{
		DoublyList list;
		int elements = static_cast<int>(v[i].size());

		for (int j = 0; j < elements; ++j)
			list.insertBack(v[i].at(j));

		cout << "List: ";
		list.print();
		cout << "Switch...\n";
		list.switchEveryTwo();
		cout << "New list: ";
		list.print();
		cout << "Reverse list: ";
		list.reversePrint();

		cout << "\n----------------------------------------\n";
	}
}