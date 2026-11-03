#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    long long waiting = 0;
    long long totalWaiting = 0;

    cout << "Order: ";

    for (int x : a) {
        cout << x << " ";
        totalWaiting += waiting;
        waiting += x;
    }

    cout << endl;

    cout << "Total waiting time = " << totalWaiting << endl;

    cout << "Average waiting time = "
         << (double)totalWaiting / n << endl;
}