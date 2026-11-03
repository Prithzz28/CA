
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dushyant() {
    int cap = 16, sz = 16;
    ll costA = 0, costB = 0;

    for (int i = 0; i < 30; i++) {
        sz--;
        costA++;

        if (sz <= cap / 2) {
            cap /= 2;
            costA += sz;
        }

        sz++;
        costA++;
    }

    cap = 16;
    sz = 16;

    for (int i = 0; i < 30; i++) {
        sz--;
        costB++;

        if (sz <= cap / 4) {
            cap /= 2;
            costB += sz;
        }

        sz++;
        costB++;
    }

    cout << "Policy A Total Cost: " << costA << endl;
    cout << "Policy A Average: " << (double)costA / 30 << endl;

    cout << "Policy B Total Cost: " << costB << endl;
    cout << "Policy B Average: " << (double)costB / 30 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dushyant();
    return 0;
}
