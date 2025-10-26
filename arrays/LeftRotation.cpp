#include <iostream>
#include <vector>
using namespace std;

vector<int> rotLeft(vector<int> a, int d) {
    int n = a.size();
    d = d % n;
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        int newIndex = (i + n - d) % n;
        result[newIndex] = a[i];
    }
    return result;
}


int main() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> result = rotLeft(a, d);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;