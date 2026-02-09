#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return {};
        return divideAndConquer(buildings, 0, buildings.size() - 1);
    }

private:
    vector<vector<int>> divideAndConquer(vector<vector<int>>& buildings, int left, int right) {
        if (left == right) {
            return {{buildings[left][0], buildings[left][2]}, {buildings[left][1], 0}};
        }
        
        int mid = left + (right - left) / 2;
        vector<vector<int>> leftSkyline = divideAndConquer(buildings, left, mid);
        vector<vector<int>> rightSkyline = divideAndConquer(buildings, mid + 1, right);
        
        return merge(leftSkyline, rightSkyline);
    }

    vector<vector<int>> merge(vector<vector<int>>& l1, vector<vector<int>>& l2) {
        vector<vector<int>> result;
        int h1 = 0, h2 = 0;
        int i = 0, j = 0;

        while (i < l1.size() && j < l2.size()) {
            int x;
            if (l1[i][0] < l2[j][0]) {
                x = l1[i][0];
                h1 = l1[i][1];
                i++;
            } else if (l1[i][0] > l2[j][0]) {
                x = l2[j][0];
                h2 = l2[j][1];
                j++;
            } else {
                x = l1[i][0];
                h1 = l1[i][1];
                h2 = l2[j][1];
                i++;
                j++;
            }

            int maxHeight = max(h1, h2);
            // Only add the point if it changes the current skyline height
            if (result.empty() || result.back()[1] != maxHeight) {
                result.push_back({x, maxHeight});
            }
        }

        // Append remaining points
        while (i < l1.size()) result.push_back(l1[i++]);
        while (j < l2.size()) result.push_back(l2[j++]);

        return result;
    }
};