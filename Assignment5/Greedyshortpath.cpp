#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int s, h;
    cin >> s >> h;

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest delay = " << dist[h] << endl;

    vector<int> path;

    for (int x = h; x != -1; x = parent[x])
        path.push_back(x);

    reverse(path.begin(), path.end());

    cout << "Path: ";

    for (int x : path)
        cout << x << " ";

    cout << endl;
}