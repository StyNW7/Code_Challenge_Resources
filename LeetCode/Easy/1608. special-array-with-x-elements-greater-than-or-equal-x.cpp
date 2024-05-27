// Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i=1;i<=n;i++)
        {
            int count = 0;
            for(int j=n-1;j>=0;j--)
            {
                if(nums[j] >= i)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            if(count == i)
            {
                return i;
            }
        }
        return -1;
    }
};
