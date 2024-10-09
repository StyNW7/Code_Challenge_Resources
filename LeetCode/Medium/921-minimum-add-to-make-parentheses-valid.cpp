// Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int open = 0, close = 0;

        for (char c : s){
            if (c == '(') open++;
            else if (c == ')' && open >= 1) open--;
            else close++;
        }

        return open + close;

    }
};
