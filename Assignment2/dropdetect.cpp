#include <bits/stdc++.h>
//O(N)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a)
    cin >> i;
  int ans = 0, len = 1;
  for (int i = 1; i < n; i++)
  {
    if (a[i] < a[i - 1])
      len++;
    else
    {
      if (len >= 3)
        ans++;
      len = 1;
    }
  }
  if (len >= 3)
    ans++;
  cout << ans;
}