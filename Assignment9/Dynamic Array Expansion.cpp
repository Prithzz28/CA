
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dushyant() {
    int n;
    cin >> n;

    int cap = 1, sz = 0;
    ll total = 0;
    vector<int> v(cap);

    cout << "Operation\tActual Cost\tTotal Cost\tAmortized Cost\n";

    for (int i = 1; i <= n; i++) {
        int cost = 1;

        if (sz == cap) {
            cap *= 2;
            vector<int> temp(cap);

            for (int j = 0; j < sz; j++) {
                temp[j] = v[j];
            }

            v = temp;
            cost += sz;
        }

        v[sz] = i;
        sz++;
        total += cost;

        double amortized = (double)total / i;

        cout << "Insert " << i << "\t\t"
             << cost << "\t\t"
             << total << "\t\t"
             << fixed << setprecision(2)
             << amortized << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dushyant();
    return 0;
}
