#include <iostream>
#include <vector>
using namespace std;
//T(n)=7T(n/2)+O(n^2)
vector<vector<int>> add(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];

    return c;
}

vector<vector<int>> sub(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] - b[i][j];

    return c;
}

vector<vector<int>> solve(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();

    if (n == 1) {
        return {{a[0][0] * b[0][0]}};
    }

    int mid = n / 2;

    vector<vector<int>> a11(mid, vector<int>(mid));
    vector<vector<int>> a12(mid, vector<int>(mid));
    vector<vector<int>> a21(mid, vector<int>(mid));
    vector<vector<int>> a22(mid, vector<int>(mid));

    vector<vector<int>> b11(mid, vector<int>(mid));
    vector<vector<int>> b12(mid, vector<int>(mid));
    vector<vector<int>> b21(mid, vector<int>(mid));
    vector<vector<int>> b22(mid, vector<int>(mid));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + mid];
            a21[i][j] = a[i + mid][j];
            a22[i][j] = a[i + mid][j + mid];

            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + mid];
            b21[i][j] = b[i + mid][j];
            b22[i][j] = b[i + mid][j + mid];
        }
    }

    vector<vector<int>> p1 = solve(add(a11, a22), add(b11, b22));
    vector<vector<int>> p2 = solve(add(a21, a22), b11);
    vector<vector<int>> p3 = solve(a11, sub(b12, b22));
    vector<vector<int>> p4 = solve(a22, sub(b21, b11));
    vector<vector<int>> p5 = solve(add(a11, a12), b22);
    vector<vector<int>> p6 = solve(sub(a21, a11), add(b11, b12));
    vector<vector<int>> p7 = solve(sub(a12, a22), add(b21, b22));

    vector<vector<int>> c11 = add(sub(add(p1, p4), p5), p7);
    vector<vector<int>> c12 = add(p3, p5);
    vector<vector<int>> c21 = add(p2, p4);
    vector<vector<int>> c22 = add(sub(add(p1, p3), p2), p6);

    vector<vector<int>> c(n, vector<int>(n));

    for (int i = 0; i < mid; i++) {
        for (int j = 0; j < mid; j++) {
            c[i][j] = c11[i][j];
            c[i][j + mid] = c12[i][j];
            c[i + mid][j] = c21[i][j];
            c[i + mid][j + mid] = c22[i][j];
        }
    }

    return c;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    vector<vector<int>> c = solve(a, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    return 0;
}
/*
\(M_1 = (A_{11} + A_{22})(B_{11} + B_{22})\)\(M_2 = (A_{21} + A_{22})B_{11}\)\(M_3 = A_{11}(B_{12} - B_{22})\)\(M_4 = A_{22}(B_{21} - B_{11})\)\(M_5 = (A_{11} + A_{12})B_{22}\)\(M_6 = (A_{21} - A_{11})(B_{11} + B_{12})\)\(M_7 = (A_{12} - A_{22})(B_{21} + B_{22})\)*/