#include <iostream>
#include <queue>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    while (true)
    {
        cout << "Commands:\n";
        cout << "\t1. Insert element\n";
        cout << "\t2. Show heap\n";
        cout << "\t3. Show top\n";

        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the number:\t";
            cin >> n;
            pq.push(n);
            break;
        case 2:
            cout << "Heap size is " << pq.size() << endl;
            cout << "Heap is ";
            while (!pq.empty())
            {
                cout << pq.top() << "\t";
                pq.pop();
            }

            cout << endl;
            break;
        case 3:
            cout << pq.top() << endl;
            break;
        default:
            break;
        }
    }
}