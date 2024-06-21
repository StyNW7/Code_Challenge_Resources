// Link: https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        // Calculate the initial number of satisfied customers (without using the technique)
        int satisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (!grumpy[i]) {
                satisfied += customers[i];
            }
        }
        
        // Calculate the maximum number of extra satisfied customers if the technique is used
        int maxExtraSatisfied = 0;
        int extraSatisfied = 0;
        
        // Initial window (first `minutes` elements)
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i]) {
                extraSatisfied += customers[i];
            }
        }
        maxExtraSatisfied = extraSatisfied;
        
        // Slide the window across the array
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i]) {
                extraSatisfied += customers[i];
            }
            if (grumpy[i - minutes]) {
                extraSatisfied -= customers[i - minutes];
            }
            maxExtraSatisfied = max(maxExtraSatisfied, extraSatisfied);
        }
        
        return satisfied + maxExtraSatisfied;
    }
};
