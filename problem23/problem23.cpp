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

class Solution {
public:
    // Helper: Merge two sorted linked lists (Standard iterative approach)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Attach any remaining nodes
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        
        return dummy.next;
    }

    // Helper: Divide and conquer logic
    ListNode* partitionAndMerge(vector<ListNode*>& lists, int start, int end) {
        // Base case: only one list
        if (start == end) {
            return lists[start];
        }
        
        // Divide
        int mid = start + (end - start) / 2;
        
        // Conquer
        ListNode* left = partitionAndMerge(lists, start, mid);
        ListNode* right = partitionAndMerge(lists, mid + 1, end);
        
        // Combine
        return mergeTwoLists(left, right);
    }

    // Main Function
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return partitionAndMerge(lists, 0, lists.size() - 1);
    }
};