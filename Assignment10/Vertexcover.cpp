
#include <bits/stdc++.h>
using namespace std;

int n;
int a[20][20];

vector<int> approxCover() {
    vector<int> cover(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] && !cover[i] && !cover[j]) {
                cover[i] = 1;
                cover[j] = 1;
            }
        }
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (cover[i])
            ans.push_back(i);
    }

    return ans;
}

int optimalCover() {
    int best = n;

    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = __builtin_popcount((unsigned)mask);

        if (cnt >= best)
            continue;

        bool valid = true;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i][j] &&
                    !(mask & (1 << i)) &&
                    !(mask & (1 << j))) {
                    valid = false;
                    break;
                }
            }

            if (!valid)
                break;
        }

        if (valid)
            best = cnt;
    }

    return best;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<int> ans = approxCover();

    cout << "Approximate Vertex Cover: ";

    for (int v : ans)
        cout << v << " ";

    cout << "\nApproximate size = " << ans.size() << '\n';

    bool valid = true;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] &&
                find(ans.begin(), ans.end(), i) == ans.end() &&
                find(ans.begin(), ans.end(), j) == ans.end()) {
                valid = false;
            }
        }
    }

    cout << (valid ? "Valid vertex cover\n"
                   : "Invalid vertex cover\n");

    if (n <= 20) {
        int opt = optimalCover();

        cout << "Optimal size = " << opt << '\n';
        cout << "Approximation ratio = "
             << fixed << setprecision(2)
             << (opt ? (double)ans.size() / opt : 1.0)
             << '\n';
    }

    return 0;
}
