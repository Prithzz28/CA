#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>

using namespace std;

struct Edge {
    int u;
    int v;
    long long w;
};

const long long INF = LLONG_MAX;

long long solve() {
    int N;
    cin >> N;

    vector<Edge> edges;
    vector<vector<pair<int, pair<long long, int>>>> graph;

    int maxVertex = 0;


    for (int i = 0; i < N; i++) {
        int u, v;
        long long w;

        cin >> u >> v >> w;

        edges.push_back({u, v, w});

        maxVertex = max(maxVertex, max(u, v));
    }

   
    graph.resize(maxVertex + 1);

    for (int i = 0; i < N; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        long long w = edges[i].w;


        graph[u].push_back({v, {w, i}});
        graph[v].push_back({u, {w, i}});
    }

    long long answer = INF;

  
    for (int removed = 0; removed < N; removed++) {

        int start = edges[removed].u;
        int end = edges[removed].v;
        long long edgeWeight = edges[removed].w;

        vector<long long> dist(maxVertex + 1, INF);

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        // Start Dijkstra
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {

            long long currentDistance = pq.top().first;
            int current = pq.top().second;

            pq.pop();


            if (currentDistance != dist[current])
                continue;

     
            for (auto next : graph[current]) {

                int neighbour = next.first;
                long long weight = next.second.first;
                int edgeID = next.second.second;

           
                if (edgeID == removed)
                    continue;

                if (dist[current] + weight < dist[neighbour]) {

                    dist[neighbour] =
                        dist[current] + weight;

                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        
        if (dist[end] != INF) {

            long long cycleLength =
                dist[end] + edgeWeight;

            answer = min(answer, cycleLength);
        }
    }

    return answer;
}

int main() {


    int T;
    cin >> T;

    while (T--) {

        long long answer = solve();

        cout << answer << endl;
    }

    return 0;
}
