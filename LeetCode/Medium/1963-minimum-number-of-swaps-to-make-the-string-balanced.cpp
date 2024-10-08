// Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/

class Solution {
public:
    int minSwaps(string s) {
        
        int swap = 0, notBalance = 0;

        for (char bracket : s){
            if (bracket == ']'){
                if (notBalance == 0) swap++,notBalance++;
                else notBalance--;
            }
            else notBalance++;
        }

        return swap;

    }
};
