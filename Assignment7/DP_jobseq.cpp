#include <bits/stdc++.h>
using namespace std;

struct Job {
    int t, d, p;
};

int main() {
    int n;
    cin >> n;

    vector<Job> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].t >> a[i].d >> a[i].p;

    int N = 1 << n;
    vector<long long> dp(N, LLONG_MAX);
    vector<int> par(N, -1);

    dp[0] = 0;

    vector<int> time(N, 0);

    for (int mask = 1; mask < N; mask++) {
        int b = __builtin_ctz(mask);
        time[mask] = time[mask ^ (1 << b)] + a[b].t;
    }

    for (int mask = 0; mask < N; mask++) {
        if (dp[mask] == LLONG_MAX)
            continue;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                continue;

            int nmask = mask | (1 << i);
            long long cost = dp[mask];

            if (time[nmask] > a[i].d)
                cost += a[i].p;

            if (cost < dp[nmask]) {
                dp[nmask] = cost;
                par[nmask] = i;
            }
        }
    }

    int mask = N - 1;
    vector<int> ans;

    while (mask) {
        int x = par[mask];
        ans.push_back(x + 1);
        mask ^= (1 << x);
    }

    reverse(ans.begin(), ans.end());

    cout << dp[N - 1] << '\n';

    for (int x : ans)
        cout << x << ' ';

    cout << '\n';
}