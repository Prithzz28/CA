#include <bits/stdc++.h>
using namespace std;
//O(N)
int main()
{
  long long X, Y, s, T;
  cin >> X >> Y >> s >> T;
  long long ans = 0;
  for (long long i = X; i <= X + s; i++)
  {
    if (i < 0)
      continue;
    long long ly = max(0LL, Y), ry = Y + s;
    ry = min(ry, T - i);
    if (ry >= ly)
      ans += ry - ly + 1;
  }
  cout << ans<<endl;
}

