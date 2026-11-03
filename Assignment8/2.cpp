#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>

const ll INF = 1e18;

void dushyant() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

struct Edge {
    int u, v;
    ll w;
};

ll solve() {
    int n;
    cin >> n;

    vector<Edge> edges;
    int mx = 0;

    for (int i = 0; i < n; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;

        edges.push_back({u, v, w});
        mx = max(mx, max(u, v));
    }

    vector<vector<pair<int, pll>>> g(mx + 1);

    for (int i = 0; i < n; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        ll w = edges[i].w;

        g[u].push_back({v, {w, i}});
        g[v].push_back({u, {w, i}});
    }

    ll ans = INF;

    for (int rem = 0; rem < n; rem++) {
        int s = edges[rem].u;
        int e = edges[rem].v;
        ll w = edges[rem].w;

        vll dist(mx + 1, INF);

        priority_queue<pll, vector<pll>, greater<pll>> pq;

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;

            for (auto it : g[u]) {
                int v = it.first;
                ll wt = it.second.first;
                int id = it.second.second;

                if (id == rem) continue;

                if (d + wt < dist[v]) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[e] != INF) {
            ans = min(ans, dist[e] + w);
        }
    }

    return ans;
}

int main() {
    dushyant();

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << '\n';
    }

    return 0;
}