#include <bits/stdc++.h>
using namespace std;
//O(n)
bool compare(string a, string b) {
    string sa = a;
    string sb = b;

    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    return sa < sb;
}

int main() {
    vector<string> arr = {"cat", "dog", "tac", "god", "act"};

    sort(arr.begin(), arr.end(), compare);

    for (string s : arr)
        cout << s << " ";
}