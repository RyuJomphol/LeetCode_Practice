/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // 1. Get the total length of the list
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        // 2. Bottom-up merge
        // step is the size of the sub-lists we are merging (1, 2, 4, 8...)
        for (int step = 1; step < length; step <<= 1) {
            ListNode* prev = &dummy;
            curr = dummy.next;

            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step); // curr now points to the start of the next pair
                
                prev->next = merge(left, right);
                
                // Move prev to the end of the merged part
                while (prev->next) {
                    prev = prev->next;
                }
            }
        }

        return dummy.next;
    }

private:
    // Splits the list and returns the head of the second part
    ListNode* split(ListNode* head, int n) {
        for (int i = 1; head && i < n; i++) {
            head = head->next;
        }
        
        if (!head) return nullptr;
        
        ListNode* second = head->next;
        head->next = nullptr; // Break the connection
        return second;
    }

    // Standard merge of two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};