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
    unordered_map<int, int> inorder_map;
    int pre_idx = 0;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map inorder values to their indices for O(1) lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        
        return arrayToTree(preorder, 0, inorder.size() - 1);
    }

    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        // Base case: if there are no elements to construct the tree
        if (left > right) return nullptr;

        // Select the pre_idx element as the root and increment it
        int root_val = preorder[pre_idx++];
        TreeNode* root = new TreeNode(root_val);

        // Find the index of the root in inorder array to split into subtrees
        int root_inorder_idx = inorder_map[root_val];

        // Recursively build the left and right subtrees
        // Important: build left first because preorder visits left before right
        root->left = arrayToTree(preorder, left, root_inorder_idx - 1);
        root->right = arrayToTree(preorder, root_inorder_idx + 1, right);

        return root;
    }
};