// Link: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/

class Solution {
public:
int sumOfDigits(std::string num) {
    int sum = 0;
    for (char c : num) {
        sum += c - '0';  // Convert char to int and add to sum
    }
    return sum;
}
    int getLucky(string s, int k) {
        // Step 1: Convert string to integer representation
        std::string num = "";
        for (char c : s) {
            int value = c - 'a' + 1;  // Get the position in the alphabet
            num += std::to_string(value);  // Append the string representation of value
        }

        // Step 2: Perform the transformation k times
        for (int i = 0; i < k; ++i) {
            int sum = sumOfDigits(num);
            num = std::to_string(sum);
        }

        // Final result
        return std::stoi(num);
    }
};
