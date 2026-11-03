#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u] |= 1 << v;
        adj[v] |= 1 << u;
    }

    vector<int> difficulty(n);

    for (int i = 0; i < n; i++)
        cin >> difficulty[i];

    int N = 1 << n;

    vector<int> independent(N, 0);

    for (int mask = 1; mask < N; mask++) {
        int b = __builtin_ctz(mask);
        int prev = mask ^ (1 << b);

        independent[mask] = independent[prev] &&
                             ((adj[b] & prev) == 0);
    }

    vector<int> color(N, n + 1), par(N, -1);

    color[0] = 0;

    for (int mask = 1; mask < N; mask++) {
        for (int sub = mask; sub; sub = (sub - 1) & mask) {
            if (independent[sub]) {
                if (color[mask ^ sub] + 1 < color[mask]) {
                    color[mask] = color[mask ^ sub] + 1;
                    par[mask] = sub;
                }
            }
        }
    }

    int slots = color[N - 1];

    vector<int> groups;

    int mask = N - 1;

    while (mask) {
        int sub = par[mask];
        groups.push_back(sub);
        mask ^= sub;
    }

    reverse(groups.begin(), groups.end());

    int k = groups.size();

    vector<int> slot(n);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (groups[i] & (1 << j))
                slot[j] = i;
        }
    }

    long long penalty = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(slot[i] - slot[j]) == 1)
                penalty += 1LL * difficulty[i] * difficulty[j];
        }
    }

    cout << slots << '\n';

    for (int i = 0; i < n; i++)
        cout << i + 1 << " " << slot[i] + 1 << '\n';

    cout << penalty << '\n';
}