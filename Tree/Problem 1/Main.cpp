/*
Binary tree is stored in the array such that index of array represents node and value represents parent's index. 
You have given an array and you have to replace values of array with t^th parent of it. 
Root nodes parent will have -1 value and if t^th parent doesn't exist, then add -1.
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void replaceParentWithTthParent(int **arr, int length, int tParent)
{
	vector<int> storeTthParent(length, -2);
	int *finalArray = new int[length], *array = *arr;
	for (int i = 0; i < length; i++)
	{
		if (array[i] == -1)
		{
			finalArray[i] = array[i];
			continue;
		}

		if (storeTthParent[array[i]] != -2)
			finalArray[i] = storeTthParent[array[i]];
		int parentIndex = array[i], oldParent = array[i];
		for (int j = tParent; j > 1; j--)
		{
			if (parentIndex == -1)
				break;
			parentIndex = array[parentIndex];
		}

		finalArray[i] = parentIndex;
		storeTthParent[oldParent] = parentIndex;
	}

	*arr = finalArray;

	cout << "\nParent array is: \n";
	for (int i = 0; i < length; i++)
	{
		cout << i << "->" << storeTthParent[i] << "\n";
	}
}

int main()
{
	//ifstream infile("input.txt");
	int n, tParent;
	cin >> n;
	int *tree = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
	}

	//infile.close();
	cout << "Given array is: \n";
	for (int i = 0; i < n; i++)
	{
		cout << i << "->" << tree[i] << " \n";
	}

	cout << "\n\nReplace parent value with t^th parent = ";
	cin >> tParent;
	cout << tParent << endl;

	replaceParentWithTthParent(&tree, n, tParent);
	cout << "\nNew array is: \n";
	for (int i = 0; i < n; i++)
	{
		cout << i << "->" << tree[i] << " \n";
	}
}
