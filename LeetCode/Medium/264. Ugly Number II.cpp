// Link: https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        // Min-heap to store ugly numbers in ascending order
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seen; // To avoid duplicates
        
        // Initial ugly number
        minHeap.push(1);
        seen.insert(1);
        
        long currentUgly = 1;
        vector<int> primes = {2, 3, 5};
        
        // Generate ugly numbers until we reach the nth one
        for (int i = 0; i < n; ++i) {
            currentUgly = minHeap.top();
            minHeap.pop();
            
            // Generate new ugly numbers by multiplying with primes
            for (int prime : primes) {
                long newUgly = currentUgly * prime;
                if (seen.find(newUgly) == seen.end()) {
                    minHeap.push(newUgly);
                    seen.insert(newUgly);
                }
            }
        }
        
        return currentUgly; // The nth ugly number
    }
};
