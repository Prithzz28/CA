#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

//T(n)=2T(n/2)+O(nlogn), O(nlog^2n)
struct Point {
    int x, y;
};

double dist(Point a, Point b) {
    double x = a.x - b.x;
    double y = a.y - b.y;

    return sqrt(x * x + y * y);
}

double solve(vector<Point>& arr, int l, int r) {
    if (r - l <= 2) {
        double ans = 1e9;

        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                ans = min(ans, dist(arr[i], arr[j]));
            }
        }

        sort(arr.begin() + l, arr.begin() + r + 1,
             [](Point a, Point b) {
                 return a.y < b.y;
             });

        return ans;
    }

    int mid = l + (r - l) / 2;
    int x = arr[mid].x;

    double left = solve(arr, l, mid);
    double right = solve(arr, mid + 1, r);

    double ans = min(left, right);

    sort(arr.begin() + l, arr.begin() + r + 1,
         [](Point a, Point b) {
             return a.y < b.y;
         });

    vector<Point> temp;

    for (int i = l; i <= r; i++) {
        if (abs(arr[i].x - x) < ans)
            temp.push_back(arr[i]);
    }

    for (int i = 0; i < temp.size(); i++) {
        for (int j = i + 1; j < temp.size(); j++) {
            if (temp[j].y - temp[i].y >= ans)
                break;

            ans = min(ans, dist(temp[i], temp[j]));
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<Point> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr.begin(), arr.end(), [](Point a, Point b) {
        return a.x < b.x;
    });

    double ans = solve(arr, 0, n - 1);

    cout << fixed << setprecision(2);
    cout << "Minimum distance = " << ans;

    return 0;
}