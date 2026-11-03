#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> start(n), end(n);

    for (int i = 0; i < n; i++)
        cin >> start[i] >> end[i];

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    int rooms = 0, ans = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;
            ans = max(ans, rooms);
            i++;
        }
        else {
            rooms--;
            j++;
        }
    }

    cout << "Minimum meeting rooms = " << ans << endl;
}