#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, start;
    cin >> n >> start;

    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    int N = 1 << n;
    const long long INF = 1e18;

    vector<vector<long long>> dp(N, vector<long long>(n, INF));
    vector<vector<int>> par(N, vector<int>(n, -1));

    dp[1 << start][start] = 0;

    for (int mask = 0; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (dp[mask][u] == INF)
                continue;

            for (int v = 0; v < n; v++) {
                if (mask & (1 << v))
                    continue;

                int nmask = mask | (1 << v);

                long long cost = dp[mask][u] + dist[u][v];

                if (cost < dp[nmask][v]) {
                    dp[nmask][v] = cost;
                    par[nmask][v] = u;
                }
            }
        }
    }

    int full = N - 1;
    long long ans = INF;
    int last = -1;

    for (int i = 0; i < n; i++) {
        long long cost = dp[full][i] + dist[i][start];

        if (cost < ans) {
            ans = cost;
            last = i;
        }
    }

    vector<int> path;

    int mask = full;
    int cur = last;

    while (cur != -1) {
        path.push_back(cur);
        int prev = par[mask][cur];
        mask ^= 1 << cur;
        cur = prev;
    }

    reverse(path.begin(), path.end());

    cout << ans << '\n';

    for (int x : path)
        cout << x + 1 << ' ';

    cout << start + 1 << '\n';
}