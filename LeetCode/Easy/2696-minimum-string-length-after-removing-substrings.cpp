// Link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

class Solution {
public:
    int minLength(string s) {
        
        stack <char> stack;

        for (int i = 0; i < s.length(); i++){
            char curr = s[i];
            if (stack.empty()){
                stack.push(curr);
                continue;
            }
            if (curr == 'B' && stack.top() == 'A') stack.pop();
            else if (curr == 'D' && stack.top() == 'C') stack.pop();
            else stack.push(curr);
        }

        return stack.size();

    }
};
