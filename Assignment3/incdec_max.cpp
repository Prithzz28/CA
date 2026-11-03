#include <iostream>
using namespace std;
//O(N)
int findMaximum(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) {
           
            low = mid + 1;
        }
        else {
          
            high = mid;
        }
    }

    return arr[low];
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum element = " << findMaximum(arr, n);

    return 0;
}