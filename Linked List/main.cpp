#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> list;
	
	while (1)
	{
		int k = 0;
		while (1)
		{
			cin>>k;
			if (k == -1) break;
			list.AddNode(k);
		}
		
		cout<<"Press 1 to display list\n";
		cin>>k;
		if (k == 1) list.PrintList();
	}
}
