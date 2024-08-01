// Link: https://leetcode.com/problems/number-of-senior-citizens/description/

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
    
        for (const std::string& detail : details) {
            // Extract age from characters at index 11 and 12
            std::string ageStr = detail.substr(11, 2);
            int age = std::stoi(ageStr);
            
            // Check if age is greater than 60
            if (age > 60) {
                count++;
            }
        }
        
        return count;
    }
};
