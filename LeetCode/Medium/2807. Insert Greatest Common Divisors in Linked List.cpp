/ Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;  // If list is empty or has only one node, return the list as is.

        ListNode* curr = head;
        while (curr && curr->next) {
            // Calculate the GCD of current node value and next node value
            int gcdVal = gcd(curr->val, curr->next->val);
            
            // Create a new node with the GCD value
            ListNode* gcdNode = new ListNode(gcdVal);
            
            // Insert this new node between curr and curr->next
            gcdNode->next = curr->next;
            curr->next = gcdNode;
            
            // Move to the next pair (skip the gcdNode)
            curr = gcdNode->next;
        }

        return head;  // Return the modified list
    }
};
