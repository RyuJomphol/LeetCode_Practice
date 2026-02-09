#include <vector>
#include <algorithm>

class Solution {
public:
    int countInRange(std::vector<int>& nums, int num, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    int majorityElementRec(std::vector<int>& nums, int lo, int hi) {
        // Base case: the only element in a range of size 1 is the majority element.
        if (lo == hi) {
            return nums[lo];
        }

        // Recurse on left and right halves of this range.
        int mid = lo + (hi - lo) / 2;
        int left = majorityElementRec(nums, lo, mid);
        int right = majorityElementRec(nums, mid + 1, hi);

        // If the two halves agree on the majority element, return it.
        if (left == right) {
            return left;
        }

        // Otherwise, count each element and return the "winner".
        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);

        return leftCount > rightCount ? left : right;
    }

    int majorityElement(std::vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }
};