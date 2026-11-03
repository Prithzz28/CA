
#include <bits/stdc++.h>
using namespace std;

int n;
int a[20][20];
int path[20];

bool solve(int pos) {
    if (pos == n)
        return a[path[n - 1]][path[0]] == 1;

    for (int v = 1; v < n; v++) {
        if (a[path[pos - 1]][v] == 1) {
            bool used = false;

            for (int i = 0; i < pos; i++) {
                if (path[i] == v)
                    used = true;
            }

            if (!used) {
                path[pos] = v;

                if (solve(pos + 1))
                    return true;

                path[pos] = -1;
            }
        }
    }

    return false;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    fill(path, path + n, -1);
    path[0] = 0;

    if (n >= 3 && solve(1)) {
        cout << "Hamiltonian Cycle exists:\n";

        for (int i = 0; i < n; i++)
            cout << path[i] << " -> ";

        cout << path[0] << '\n';
    } else {
        cout << "No Hamiltonian Cycle exists\n";
    }

    return 0;
}
