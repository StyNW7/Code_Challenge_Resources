// Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1}; // Not enough nodes to have critical points
        }

        std::vector<int> criticalPoints;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next != NULL) {
            ListNode* next = curr->next;
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                criticalPoints.push_back(index);
            }
            prev = curr;
            curr = next;
            index++;
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1}; // Fewer than two critical points
        }

        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDistance = std::min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }

        return {minDistance, maxDistance};
    }
};
