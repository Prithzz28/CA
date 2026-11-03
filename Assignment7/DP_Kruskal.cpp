#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;

    DSU(int n) {
        p.resize(n);
        sz.assign(n, 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (sz[a] < sz[b])
            swap(a, b);

        p[b] = a;
        sz[a] += sz[b];

        return true;
    }
};

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (auto &[u, v, w] : edges) {
        cin >> u >> v >> w;
        --u;
        --v;
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    DSU dsu(n);

    long long cost = 0;
    vector<Edge> ans;

    for (auto e : edges) {
        if (dsu.unite(e.u, e.v)) {
            ans.push_back(e);
            cost += e.w;
        }
    }

    if ((int)ans.size() != n - 1) {
        cout << "Disconnected\n";

        map<int, vector<int>> components;

        for (int i = 0; i < n; i++)
            components[dsu.find(i)].push_back(i + 1);

        for (auto &[x, v] : components) {
            for (int node : v)
                cout << node << ' ';
            cout << '\n';
        }

        return 0;
    }

    cout << cost << '\n';

    for (auto [u, v, w] : ans)
        cout << u + 1 << " " << v + 1 << " " << w << '\n';
}