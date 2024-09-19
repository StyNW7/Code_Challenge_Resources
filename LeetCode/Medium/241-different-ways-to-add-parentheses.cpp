// Link: https://leetcode.com/problems/different-ways-to-add-parentheses/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        
        vector <int> ans;

        for (int i = 0; i < expression.size(); i++){

            char operation = expression[i];

            if (operation == '+' || operation == '-' || operation == '*'){

                vector <int> s1 = diffWaysToCompute(expression.substr(0,i));
                vector <int> s2 = diffWaysToCompute(expression.substr(i+1));

                for (int a : s1){
                    for(int b : s2){
                        if (operation == '+') ans.push_back(a+b);
                        else if (operation == '-') ans.push_back(a-b);
                        else if (operation == '*') ans.push_back(a*b);
                    }
                }

            }
        }

        if (ans.empty()) ans.push_back(stoi(expression));
        return ans;

    }
};
