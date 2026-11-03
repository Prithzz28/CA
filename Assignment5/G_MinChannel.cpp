#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> channel(m);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            channel[i].push_back(x);
        }
    }

    set<int> uncovered;

    for (int i = 1; i <= n; i++)
        uncovered.insert(i);

    vector<int> ans;

    while (!uncovered.empty()) {
        int best = -1;
        int mx = 0;

        for (int i = 0; i < m; i++) {
            int cnt = 0;

            for (int x : channel[i]) {
                if (uncovered.count(x))
                    cnt++;
            }

            if (cnt > mx) {
                mx = cnt;
                best = i;
            }
        }

        if (best == -1) {
            cout << "All segments cannot be covered" << endl;
            return 0;
        }

        ans.push_back(best + 1);

        for (int x : channel[best])
            uncovered.erase(x);
    }

    cout << "Selected channels: ";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    cout << "Number of channels = " << ans.size() << endl;
}