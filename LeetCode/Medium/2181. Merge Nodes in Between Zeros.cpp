// Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);  // Create a dummy node to simplify the list creation
        ListNode* current = dummy;  // Pointer to build the new list
        ListNode* iterator = head->next;  // Start from the first node after the initial zero
        int sum = 0;

        while (iterator) {
            if (iterator->val == 0) {
                if (sum > 0) {
                    current->next = new ListNode(sum);
                    current = current->next;
                    sum = 0;  // Reset sum after creating a new node
                }
            } else {
                sum += iterator->val;  // Accumulate the sum of values between zeros
            }
            iterator = iterator->next;
        }

        ListNode* result = dummy->next;  // Get the head of the new list
        delete dummy;  // Clean up the dummy node
        return result;
    }
};
