#include <iostream>
#include <vector>
using namespace std;

vector<int> find(vector<int>& nums) {
    int xorAll = 0;
    for (int num : nums) {
        xorAll ^= num;
    }

    int right = 1;
    while ((right & xorAll) == 0) {
        right <<= 1;
    }

    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & right) {
            num1 ^= num;
        }
        else {
            num2 ^= num; 
        }
    }

    return { num1, num2 };
}

int main() {
    vector<int> nums;
    vector<int> result = find(nums);

    cout  << result[0] << result[1] << endl; 

    return 0;
}