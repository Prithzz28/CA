#include <bits/stdc++.h>
// O(n)
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> A(m + n), B(n);
    for (int i = 0; i < m; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0)
    {
        if (i >= 0 && A[i] > B[j])
            A[k--] = A[i--];
        else
            A[k--] = B[j--];
    }
    for (int x : A)
        cout << x << " ";
}