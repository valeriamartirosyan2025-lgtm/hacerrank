#include <iostream>
#include <vector>
using namespace std;

int findSingleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num; 
    }
    return result;
}

int main() {
    vector<int> nums;
    cout << findSingleNumber(nums) << endl; 

    return 0;
}