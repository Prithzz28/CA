
#include <bits/stdc++.h>
using namespace std;

int n;
int a[20][20];
int color[20];

bool safe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (a[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool solve(int v, int m) {
    if (v == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (safe(v, c)) {
            color[v] = c;

            if (solve(v + 1, m))
                return true;

            color[v] = 0;
        }
    }
    return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int ans = -1;

    for (int m = 1; m <= n; m++) {
        fill(color, color + n, 0);

        if (solve(0, m)) {
            ans = m;
            break;
        }
    }

    if (ans == -1) {
        cout << "No coloring exists\n";
        return 0;
    }

    cout << "Minimum colors required = " << ans << '\n';
    cout << "Color assignment:\n";

    for (int i = 0; i < n; i++)
        cout << "Vertex " << i << " -> Color "
             << color[i] << '\n';

    bool valid = true;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] && color[i] == color[j])
                valid = false;
        }
    }

    cout << (valid ? "Valid coloring\n" : "Invalid coloring\n");
    return 0;
}
