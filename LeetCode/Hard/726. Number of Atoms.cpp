// Link: https://leetcode.com/problems/number-of-atoms/

class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<map<string, int>> stk;
        map<string, int> current;

        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                stk.push(current);
                current.clear();
                i++;
            } else if (formula[i] == ')') {
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplicity = i > start ? stoi(formula.substr(start, i - start)) : 1;
                
                if (!stk.empty()) {
                    map<string, int> top = stk.top();
                    stk.pop();
                    for (auto& [atom, count] : current) {
                        top[atom] += count * multiplicity;
                    }
                    current = top;
                }
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string atom = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count = i > start ? stoi(formula.substr(start, i - start)) : 1;
                current[atom] += count;
            }
        }
        
        vector<pair<string, int>> elements(current.begin(), current.end());
        sort(elements.begin(), elements.end());
        
        string result;
        for (const auto& [atom, count] : elements) {
            result += atom;
            if (count > 1) result += to_string(count);
        }
        
        return result;
    }
};
