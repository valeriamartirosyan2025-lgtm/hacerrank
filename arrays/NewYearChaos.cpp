#include <iostream>
#include <vector>
using namespace std;
void minimumBribes(vector<int> q) {
    int n = q.size();
    int bribes = 0;

    for (int i = 0; i < n; i++) {
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }

        for (int j = max(0, q[i] - 2); j < i; j++) {
            if (q[j] > q[i]) bribes++;
        }
    }

    cout << bribes << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> q(n);
        for (int i = 0; i < n; i++) {
            cin >> q[i];
        }
        minimumBribes(q);
    }

    return 0;
}