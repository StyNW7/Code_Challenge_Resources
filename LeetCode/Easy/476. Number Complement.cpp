// Link: https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        // Edge case where num is 0 (though constraints say num >= 1)
        if (num == 0) return 1;

        // Initialize the mask
        int mask = 1;
        
        // Create the mask with all bits set to 1 that cover all bits of num
        while (mask < num) {
            mask = (mask << 1) | 1;
        }

        // The complement is num XOR mask
        return num ^ mask;
    }
};
