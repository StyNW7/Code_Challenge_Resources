// Link: https://leetcode.com/problems/maximum-swap/description/

class Solution {
public:
    int maximumSwap(int num) {

        string str = to_string(num);
        int n = str.size();

        int index = -1;
        int swap1, swap2 = -1;

        for (int i = n-1; i >= 0; i--){

            if (index == -1 || str[i] > str[index]) index = i;
            else if (str[i] < str[index]){
                swap1 = i;
                swap2 = index;
            }

        }

        if (swap1 != -1 && swap2 != -1) swap(str[swap1], str[swap2]);

        return stoi(str);

    }
};
