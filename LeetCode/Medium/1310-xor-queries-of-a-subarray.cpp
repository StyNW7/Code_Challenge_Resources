// Link: https://leetcode.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
    
        // Step 1: Create a prefix XOR array
        vector<int> prefixXOR(n);
        prefixXOR[0] = arr[0];
        
        for (int i = 1; i < n; ++i) {
            prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
        }
        
        // Step 2: Answer each query using the prefix XOR array
        vector<int> result;
        
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            
            // XOR from left to right is prefixXOR[right] ^ prefixXOR[left - 1]
            if (left == 0) {
                result.push_back(prefixXOR[right]);
            } else {
                result.push_back(prefixXOR[right] ^ prefixXOR[left - 1]);
            }
        }
        
        return result;
    }
};
