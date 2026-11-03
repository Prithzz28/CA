#include <bits/stdc++.h>
using namespace std;

struct Surgery {
    int s, e, p, id;
};

struct State {
    vector<int> endTime;
    long long value;
    vector<pair<int,int>> schedule;
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<Surgery> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].e >> a[i].p;
        a[i].id = i + 1;
    }

    sort(a.begin(), a.end(), [](Surgery x, Surgery y) {
        return x.s < y.s;
    });

    map<vector<int>, pair<long long, vector<pair<int,int>>>> dp;

    vector<int> start(k, 0);
    dp[start] = {0, {}};

    for (auto x : a) {
        vector<pair<vector<int>, pair<long long, vector<pair<int,int>>>>> cur;

        for (auto &it : dp) {
            vector<int> times = it.first;
            long long val = it.second.first;
            auto schedule = it.second.second;

            for (int r = 0; r < k; r++) {
                if (times[r] <= x.s) {
                    vector<int> nt = times;
                    nt[r] = x.e;

                    auto ns = schedule;
                    ns.push_back({x.id, r + 1});

                    if (!dp.count(nt) || dp[nt].first < val + x.p) {
                        cur.push_back({nt, {val + x.p, ns}});
                    }
                }
            }
        }

        for (auto &x : cur) {
            if (!dp.count(x.first) || dp[x.first].first < x.second.first)
                dp[x.first] = x.second;
        }
    }

    long long best = 0;
    vector<pair<int,int>> ans;

    for (auto &it : dp) {
        if (it.second.first > best) {
            best = it.second.first;
            ans = it.second.second;
        }
    }

    cout << best << '\n';

    for (auto &[id, room] : ans)
        cout << id << " " << room << '\n';
}