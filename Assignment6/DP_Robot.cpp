#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<long long>> dp(m, vector<long long>(n, 0));

    if(grid[0][0] == 1 || grid[m-1][n-1] == 1) {
        cout << 0;
        return 0;
    }

    dp[0][0] = 1;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1)
                continue;

            if(i > 0)
                dp[i][j] += dp[i-1][j];

            if(j > 0)
                dp[i][j] += dp[i][j-1];
        }
    }

    cout << dp[m-1][n-1];

    return 0;
}