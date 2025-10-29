#include <iostream>
#include <cmath>  
using namespace std;

int main() {
    double zero = 0.0;

    double smallestPositive = nextafter(zero, 1.0);

    cout << smallestPositive << endl;

    return 0;
}
