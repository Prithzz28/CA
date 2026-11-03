/*
time: O(n log n)
recursion eq: T(n)=2T(n/2)+O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> merge(vector<pair<int, int>> a,vector<pair<int, int>> b) {
    vector<pair<int, int>> ans;

    int i = 0, j = 0;
    int h1 = 0, h2 = 0;

    while (i < a.size() && j < b.size()) {
        int x;

        if (a[i].first < b[j].first) {
            x = a[i].first;
            h1 = a[i].second;
            i++;
        }
        else if (a[i].first > b[j].first) {
            x = b[j].first;
            h2 = b[j].second;
            j++;
        }
        else {
            x = a[i].first;
            h1 = a[i].second;
            h2 = b[j].second;
            i++;
            j++;
        }

        int h = max(h1, h2);

        if (ans.empty() || ans.back().second != h)
            ans.push_back({x, h});
    }

    while (i < a.size()) {
        if (ans.empty() || ans.back().second != a[i].second)
            ans.push_back(a[i]);
        i++;
    }

    while (j < b.size()) {
        if (ans.empty() || ans.back().second != b[j].second)
            ans.push_back(b[j]);
        j++;
    }

    return ans;
}

vector<pair<int, int>> solve(vector<vector<int>>& arr, int l, int r) {
    if (l == r) {
        vector<pair<int, int>> ans;

        ans.push_back({arr[l][0], arr[l][1]});
        ans.push_back({arr[l][2], 0});

        return ans;
    }

    int mid = l + (r - l) / 2;

    vector<pair<int, int>> a = solve(arr, l, mid);
    vector<pair<int, int>> b = solve(arr, mid + 1, r);

    return merge(a, b);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    vector<pair<int, int>> ans = solve(arr, 0, n - 1);

    for (auto x : ans) {
        cout << "(" << x.first << ", " << x.second << ") ";
    }

    return 0;
}