/*
Recurrence: T(n)=2T(n-1)+1
Time: O(2^n)
*/
#include <iostream>
using namespace std;

void hanoi(int n, char s, char a, char d)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << s << " to " << d << endl;
        return;
    }
    hanoi(n - 1, s, d, a);

    cout << "Move disk " << n << " from " << s << " to " << d << endl;

    hanoi(n - 1, a, s, d);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}