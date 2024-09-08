// Link: https://leetcode.com/problems/split-linked-list-in-parts/

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

// Helper function to get the length of the linked list.
int getLength(ListNode* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr); // Create a vector of size k initialized to nullptr.
        int totalLength = getLength(head); // Find the total length of the list.
        
        // Calculate the size of each part.
        int partSize = totalLength / k; // Base size of each part.
        int remainder = totalLength % k; // Extra nodes to distribute.

        ListNode* current = head;
        for (int i = 0; i < k && current != nullptr; ++i) {
            result[i] = current; // Assign the current node as the start of the i-th part.
            int currentPartSize = partSize + (remainder > 0 ? 1 : 0); // Add an extra node if remainder > 0.
            remainder--;

            // Move to the end of the current part.
            for (int j = 1; j < currentPartSize; ++j) {
                if (current != nullptr) {
                    current = current->next;
                }
            }

            // Cut the list.
            if (current != nullptr) {
                ListNode* nextPart = current->next;
                current->next = nullptr; // End the current part.
                current = nextPart; // Move to the next part.
            }
        }

        return result;
    }
};
