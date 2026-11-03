#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
  for(int i = 0; i < n; i++)
        cin >> coins[i];
    const int INF = 1e9;
    vector<int> mn(amount + 1, INF);
    mn[0] = 0;
    for(int i = 1; i <= amount; i++) {
        for(int coin : coins) {
            if(coin <= i && mn[i - coin] != INF) {
                mn[i] = min(mn[i], mn[i - coin] + 1);
            }
        }
    }
    vector<long long> ways(amount + 1, 0);
    ways[0] = 1;

    for(int coin : coins) {
        for(int i = coin; i <= amount; i++) {
            ways[i] += ways[i - coin];
        }
    }
    if(mn[amount] == INF)
        cout << "Minimum coins: -1\n";
    else
        cout << "Minimum coins: " << mn[amount] << '\n';

    cout << "Number of ways: " << ways[amount] << '\n';

    return 0;
}