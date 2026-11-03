#include <bits/stdc++.h>
using namespace std;
//O(mlogn)
int main()
{
  int m, n, t;
  cin >> m >> n;
  vector<vector<int>> a(m, vector<int>(n));
  for (auto &r : a)
    for (int &x : r)
      cin >> x;
  cin >> t;
  for (auto &r : a)
  {
    auto it = lower_bound(r.begin(), r.end(), t);
    if (it != r.end() && *it == t)
    {
      cout << "true";
      return 0;
    }
  }
  cout << "false";
}