// Link: https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        int n = arr1.size();

        unordered_set<int> set1;

        for (int i = 0; i < n; i++){
            int num = arr1[i];
            while (num){
                set1.insert(num);
                num /= 10;
            }
        }

        int min = INT_MIN;

        for (int j = 0; j < arr2.size(); j++){
            int x = arr2[j];
            string s2 = to_string(x);
            string ans = "";
            for (int a = 0; a < s2.size(); a++){
                ans = ans + s2[a];
                int y = stoi(ans);
                if (set1.find(y) != set1.end()){
                    int lenn = ans.size();
                    min = max(min, lenn);
                }
                else break;
            }
        }

        return (min == INT_MIN) ? 0 : min;

    }
};
