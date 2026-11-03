#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++)
    {
        int size;
        cin >> size;

        pq.push(size);
    }

    int totalCost = 0;

    while(pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int merged = first + second;

        totalCost += merged;

        pq.push(merged);

        cout << "Merged "
             << first << " + " << second
             << " = " << merged << endl;
    }

    cout << "Minimum Total Merge Cost = "
         << totalCost << endl;

    return 0;
}