#include <vector>
#include <algorithm>
#include <ctime>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // We want the (k-1)th index in a descending-sort logic
        // OR the (n-k)th index in an ascending-sort logic.
        // Let's target the index: target = nums.size() - k
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

private:
    int quickSelect(std::vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];

        // Randomize pivot to avoid O(n^2)
        int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(nums, left, right, pivotIndex);

        if (pivotIndex == k) {
            return nums[k];
        } else if (pivotIndex > k) {
            return quickSelect(nums, left, pivotIndex - 1, k);
        } else {
            return quickSelect(nums, pivotIndex + 1, right, k);
        }
    }

    int partition(std::vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue = nums[pivotIndex];
        // Move pivot to the end
        std::swap(nums[pivotIndex], nums[right]);
        int storeIndex = left;

        for (int i = left; i < right; i++) {
            if (nums[i] < pivotValue) {
                std::swap(nums[i], nums[storeIndex]);
                storeIndex++;
            }
        }
        // Move pivot to its final place
        std::swap(nums[storeIndex], nums[right]);
        return storeIndex;
    }
};