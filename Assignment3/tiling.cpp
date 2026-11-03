/*
T(n)=O(n^2)
T(n)=4T(n/2)+O(1)
*/


#include <iostream>
using namespace std;

int tile = 0;

void solve(int arr[][100], int r, int c, int n, int mr, int mc) {
    if (n == 2) {
        int t = ++tile;

        for (int i = r; i < r + 2; i++) {
            for (int j = c; j < c + 2; j++) {
                if (arr[i][j] == 0)
                    arr[i][j] = t;
            }
        }
        return;
    }

    int mid = n / 2;
    int x = r + mid;
    int y = c + mid;

    if (mr < x && mc < y) {
        int t = ++tile;

        arr[x - 1][y] = t;
        arr[x][y - 1] = t;
        arr[x][y] = t;

        solve(arr, r, c, mid, mr, mc);
        solve(arr, r, y, mid, x - 1, y);
        solve(arr, x, c, mid, x, y - 1);
        solve(arr, x, y, mid, x, y);
    }
    else if (mr < x && mc >= y) {
        int t = ++tile;

        arr[x - 1][y - 1] = t;
        arr[x][y - 1] = t;
        arr[x][y] = t;

        solve(arr, r, c, mid, x - 1, y - 1);
        solve(arr, r, y, mid, mr, mc);
        solve(arr, x, c, mid, x, y - 1);
        solve(arr, x, y, mid, x, y);
    }
    else if (mr >= x && mc < y) {
        int t = ++tile;

        arr[x - 1][y - 1] = t;
        arr[x - 1][y] = t;
        arr[x][y] = t;

        solve(arr, r, c, mid, x - 1, y - 1);
        solve(arr, r, y, mid, x - 1, y);
        solve(arr, x, c, mid, mr, mc);
        solve(arr, x, y, mid, x, y);
    }
    else {
        int t = ++tile;

        arr[x - 1][y - 1] = t;
        arr[x - 1][y] = t;
        arr[x][y - 1] = t;

        solve(arr, r, c, mid, x - 1, y - 1);
        solve(arr, r, y, mid, x - 1, y);
        solve(arr, x, c, mid, x, y - 1);
        solve(arr, x, y, mid, mr, mc);
    }
}

int main() {
    int n;
    cin >> n;

    int arr[100][100] = {0};

    int mr, mc;
    cin >> mr >> mc;

    arr[mr][mc] = -1;

    solve(arr, 0, 0, n, mr, mc);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == -1)
                cout << "X ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}