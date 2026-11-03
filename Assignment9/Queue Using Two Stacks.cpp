
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dushyant() {
    stack<int> s1, s2;
    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "enqueue") {
            int x;
            cin >> x;
            s1.push(x);
        }
        else if (op == "dequeue") {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            if (!s2.empty()) {
                cout << "Dequeued: " << s2.top() << endl;
                s2.pop();
            }
            else {
                cout << "Queue is empty" << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dushyant();
    return 0;
}
