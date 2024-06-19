// Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution {
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int mid) {
        long long bouquets = 0;
        long long flowers = 0;
        
        for (long long day : bloomDay) {
            if (day <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
            if (bouquets >= m) {
                return true;
            }
        }
        return false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if (n < (long long)m * k) {
            return -1; // Not enough flowers to make m bouquets
        }
        
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
