#include <iostream>
using namespace std;

int maxSubarraySum(vector<int>& arr) {
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int x : arr) {
        currentSum += x;

        maxSum = max(maxSum, currentSum);

        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};

    cout << "Maximum subarray sum: " << maxSubarraySum(arr) << endl;

    return 0;
}