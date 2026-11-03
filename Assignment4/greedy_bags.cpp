#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> bags(n);

    for(int i = 0; i < n; i++)
    {
        cin >> bags[i];
    }

    int capacity;
    cin >> capacity;

    sort(bags.begin(), bags.end());

    int totalWeight = 0;
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(totalWeight + bags[i] <= capacity)
        {
            totalWeight += bags[i];
            count++;
        }
        else
        {
            break;
        }
    }

    cout << "Maximum number of bags = " << count << endl;
    cout << "Total weight = " << totalWeight << " kg" << endl;

    return 0;
}