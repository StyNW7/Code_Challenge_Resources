// Link: https://leetcode.com/problems/replace-words/description/

class Solution {
public:
    vector<string> split(const string &s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> rootSet(dictionary.begin(), dictionary.end());
        vector<string> words = split(sentence, ' ');
        
        for (string &word : words) {
            string prefix = "";
            for (int i = 1; i <= word.length(); ++i) {
                prefix = word.substr(0, i);
                if (rootSet.find(prefix) != rootSet.end()) {
                    word = prefix;
                    break;
                }
            }
        }
        
        string result;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) result += " ";
            result += words[i];
        }
        
        return result;
    }
};
