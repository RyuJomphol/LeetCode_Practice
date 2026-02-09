#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size() - 1);
    }

private:
    int divideAndConquer(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];

        int mid = left + (right - left) / 2;

        // Recursive cases: max is in left or right half
        int leftMax = divideAndConquer(nums, left, mid);
        int rightMax = divideAndConquer(nums, mid + 1, right);
        
        // Crossing case: max spans across the midpoint
        int crossMax = maxCrossingSum(nums, left, mid, right);

        return max({leftMax, rightMax, crossMax});
    }

    int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
        int leftSum = INT_MIN;
        int currentSum = 0;
        // Search from mid to the left
        for (int i = mid; i >= left; i--) {
            currentSum += nums[i];
            leftSum = max(leftSum, currentSum);
        }

        int rightSum = INT_MIN;
        currentSum = 0;
        // Search from mid+1 to the right
        for (int i = mid + 1; i <= right; i++) {
            currentSum += nums[i];
            rightSum = max(rightSum, currentSum);
        }

        return leftSum + rightSum;
    }
};