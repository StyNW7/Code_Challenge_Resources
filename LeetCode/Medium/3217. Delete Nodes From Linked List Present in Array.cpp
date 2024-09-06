https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/// Link: 

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Store the values to be removed in a set for O(1) lookup.
        unordered_set<int> numSet(nums.begin(), nums.end());

        // Create a dummy node to handle edge cases.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;

        // Traverse the linked list.
        while (current->next != NULL) {
            if (numSet.count(current->next->val)) {
                // Remove the node by skipping it.
                ListNode* nodeToDelete = current->next;
                current->next = current->next->next;
                delete nodeToDelete; // Free the memory.
            } else {
                current = current->next; // Move to the next node.
            }
        }

        // Return the new head of the list.
        ListNode* newHead = dummy->next;
        delete dummy; // Free the dummy node memory.
        return newHead;
    }
};
