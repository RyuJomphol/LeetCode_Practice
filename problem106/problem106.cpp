/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int, int> inMap; // To find root index in O(1)
    int postIdx;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Map values to indices for quick lookup in the inorder array
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        // Start from the end of the postorder array
        postIdx = postorder.size() - 1;
        
        return solve(postorder, 0, inorder.size() - 1);
    }

    TreeNode* solve(vector<int>& postorder, int inStart, int inEnd) {
        // Base case: if the range is invalid, return null
        if (inStart > inEnd) return nullptr;

        // The current root is at postIdx in the postorder array
        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        // Find where this root is in the inorder array
        int mid = inMap[rootVal];

        // Recursively build the RIGHT subtree first (crucial for postorder)
        root->right = solve(postorder, mid + 1, inEnd);
        
        // Recursively build the LEFT subtree
        root->left = solve(postorder, inStart, mid - 1);

        return root;
    }
};