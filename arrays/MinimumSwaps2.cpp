#include <iostream>
#include <vector>
using namespace std;

int minimumSwaps(vector<int> arr) {
    int n = arr.size();
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        while (arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] - 1]);
            swaps++;
        }
    }

    return swaps;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << minimumSwaps(arr) << endl;
    return 0;
}