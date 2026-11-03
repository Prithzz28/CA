#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> p(n);

    for (auto &x : p)
        cin >> x;

    vector<vector<long long>> dp(n, vector<long long>(n));
    vector<vector<int>> root(n, vector<int>(n));

    vector<long long> pref(n + 1);

    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + p[i];

    for (int i = 0; i < n; i++) {
        dp[i][i] = p[i];
        root[i][i] = i;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;

            dp[l][r] = LLONG_MAX;

            long long sum = pref[r + 1] - pref[l];

            for (int k = l; k <= r; k++) {
                long long left = (k > l ? dp[l][k - 1] : 0);
                long long right = (k < r ? dp[k + 1][r] : 0);

                long long cur = left + right + sum;

                if (cur < dp[l][r]) {
                    dp[l][r] = cur;
                    root[l][r] = k;
                }
            }
        }
    }

    cout << dp[0][n - 1] << '\n';

    function<void(int,int,int)> print = [&](int l, int r, int parent) {
        if (l > r)
            return;

        int k = root[l][r];

        cout << "Key " << k + 1 << " Parent ";

        if (parent == -1)
            cout << "NULL";
        else
            cout << parent + 1;

        cout << '\n';

        print(l, k - 1, k);
        print(k + 1, r, k);
    };

    print(0, n - 1, -1);
}