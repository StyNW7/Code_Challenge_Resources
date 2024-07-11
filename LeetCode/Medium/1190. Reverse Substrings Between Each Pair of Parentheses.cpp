// Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        std::stack<char> st;

        for (char ch : s) {
            if (ch == ')') {
                // If we find a closing parenthesis, pop and collect characters until we find an opening parenthesis
                std::string temp;
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                // Pop the opening parenthesis
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                // Push the reversed string back onto the stack
                for (char t_ch : temp) {
                    st.push(t_ch);
                }
            } else {
                // Push all other characters, including opening parentheses
                st.push(ch);
            }
        }

        // Collect the result from the stack
        std::string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        // The characters are in reverse order because of stack's LIFO nature, so reverse the result
        std::reverse(result.begin(), result.end());

        return result;
    }
};
