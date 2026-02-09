/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Base case: empty list
        if (!head) return nullptr;
        // Base case: single element
        if (!head->next) return new TreeNode(head->val);
        
        // Find the middle using fast/slow pointers
        // We also need the node BEFORE the middle to break the list
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 'slow' is now the middle node. Disconnect the left half.
        if (prev) prev->next = nullptr;
        
        // Create the root from the middle element
        TreeNode* root = new TreeNode(slow->val);
        
        // Recurse:
        // Left child gets the head of the now-shortened left half
        root->left = sortedListToBST(head);
        // Right child gets the node after 'slow'
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};