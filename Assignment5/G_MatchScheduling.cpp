#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), [](auto x, auto y) {
        return x.second < y.second;
    });

    int lastEnd = -1;
    vector<pair<int,int>> ans;

    for (auto [start, end] : a) {
        if (start >= lastEnd) {
            ans.push_back({start, end});
            lastEnd = end;
        }
    }

    cout << "Selected matches:\n";

    for (auto [start, end] : ans)
        cout << start << " " << end << endl;

    cout << "Maximum matches = " << ans.size() << endl;
}