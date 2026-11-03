#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, hub;
    cin >> n >> m >> hub;

    --hub;

    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> used(n, false);

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    dist[hub] = 0;
    pq.push({0, hub});

    long long cost = 0;
    vector<tuple<int,int,int>> edges;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (used[u])
            continue;

        used[u] = true;
        cost += d;

        if (parent[u] != -1)
            edges.push_back({parent[u], u, d});

        for (auto [v, w] : adj[u]) {
            if (!used[v] && w < dist[v]) {
                dist[v] = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cout << "Disconnected\n";
            return 0;
        }
    }

    cout << cost << '\n';

    for (auto [u, v, w] : edges)
        cout << u + 1 << " " << v + 1 << " " << w << '\n';
}