
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

stack<int> st;
ll credit = 0;
ll total = 0;

void push(int x) {
    st.push(x);
    credit++;
    total += 2;

    cout << "Push " << x
         << " | Actual: 1"
         << " | Amortized: 2"
         << " | Credit: " << credit << "\n";
}

void pop() {
    if (st.empty()) {
        cout << "Stack is empty\n";
        return;
    }

    int x = st.top();
    st.pop();
    credit--;
    total += 0;

    cout << "Pop " << x
         << " | Actual: 1"
         << " | Amortized: 0"
         << " | Credit: " << credit << "\n";
}

void multipop(int k) {
    int cnt = 0;

    while (k > 0 && !st.empty()) {
        st.pop();
        credit--;
        cnt++;
        k--;
    }

    cout << "Multipop removed: " << cnt
         << " | Credit: " << credit << "\n";
}

void dushyant() {
    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            push(x);
        } else if (op == "pop") {
            pop();
        } else if (op == "multipop") {
            int k;
            cin >> k;
            multipop(k);
        }
    }

    cout << "Remaining stack size: " << st.size() << "\n";
    cout << "Credit bank: " << credit << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dushyant();
    return 0;
}
