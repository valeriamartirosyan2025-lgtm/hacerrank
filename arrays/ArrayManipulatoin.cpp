#include <iostream>
#include <vector>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);

    for (auto q : queries) {
        int a = q[0];
        int b = q[1];
        int k = q[2];

        arr[a - 1] += k;
        if (b < n) arr[b] -= k;
    }
    long max_val = 0;
    long current = 0;
    for (int i = 0; i < n; i++) {
        current += arr[i];
        if (current > max_val) max_val = current;
    }
    return max_val;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> queries(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    cout << arrayManipulation(n, queries) << endl;
    return 0;
}