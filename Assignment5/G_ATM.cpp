#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> den(n);

    for (int i = 0; i < n; i++)
        cin >> den[i];

    int amount;
    cin >> amount;

    sort(den.begin(), den.end());

    vector<int> ans;

    for (int i = n - 1; i >= 0; i--) {
        while (amount >= den[i]) {
            amount -= den[i];
            ans.push_back(den[i]);
        }
    }

    if (amount != 0) {
        cout << "Amount cannot be formed" << endl;
        return 0;
    }

    cout << "Notes: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    cout << "Minimum notes = " << ans.size() << endl;
}