// Link: https://leetcode.com/problems/longest-palindrome/description/

class Solution {
public:
    int longestPalindrome(string s) {
        int alphabet[26] = {0};
        int alphabetUpper[26] = {0};
        for (int i = 0; i < s.length(); i++){
            if (s[i] >= 'a' && s[i] <= 'z') alphabet[s[i] - 'a']++;
            else if (s[i] >= 'A' && s[i] <= 'Z') alphabetUpper[s[i] - 'A']++;
        }
        bool count1 = false;
        int length = 0;
        for (int x = 0; x < 26; x++){
            if (alphabet[x] % 2 == 0) length += alphabet[x];
            else if (alphabet[x] % 2 == 1 && count1 == false){
                length += alphabet[x];
                count1 = true;
            }
            else if (alphabet[x] % 2 == 1 && alphabet[x] > 1) length += alphabet[x] - 1;

            if (alphabetUpper[x] % 2 == 0) length += alphabetUpper[x];
            else if (alphabetUpper[x] % 2 == 1 && alphabetUpper[x] > 1) length += alphabetUpper[x] - 1;
            else if (alphabetUpper[x] % 2 == 1 && count1 == false){
                length += alphabetUpper[x];
                count1 = true;
            }
        }
        return length;
    }
};
