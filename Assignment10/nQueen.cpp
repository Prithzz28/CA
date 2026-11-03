
#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];
int cnt = 0;

bool safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return false;

        if (col - (row - i) >= 0 &&
            board[i][col - (row - i)])
            return false;

        if (col + (row - i) < n &&
            board[i][col + (row - i)])
            return false;
    }
    return true;
}

void solve(int row) {
    if (row == n) {
        cnt++;
        cout << "\nSolution " << cnt << ":\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << (board[i][j] ? "Q " : ". ");
            cout << '\n';
        }
        return;
    }

    for (int col = 0; col < n; col++) {
        if (safe(row, col)) {
            board[row][col] = 1;
            solve(row + 1);
            board[row][col] = 0;
        }
    }
}

int main() {
    n = 8;
    solve(0);
    cout << "\nTotal solutions = " << cnt << '\n';
    return 0;
}
