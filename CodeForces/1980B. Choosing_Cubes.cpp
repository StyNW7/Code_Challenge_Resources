// Link: https://codeforces.com/contest/1980/problem/B

#include <bits/stdc++.h>

using namespace std;

int main() {
    int test;
    scanf("%d", &test);
    
    for (int i = 0; i < test; i++) {
        int size, fav, removed;
        scanf("%d %d %d", &size, &fav, &removed);
        
        vector<int> nums(size);
        int favNum = -1;
        
        vector<int> hash(101, 0);
        
        for (int x = 0; x < size; x++) {
            scanf("%d", &nums[x]);
            hash[nums[x]]++;
            if (x == fav - 1) favNum = nums[x];
        }
        
        bool ans = false;
        int count = 0;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        for (int y = 0; y < removed; y++) {
            if (nums[y] == favNum) {
                ans = true;
                count++;
            }
        }
        
        if (ans && count == hash[favNum]) printf("YES\n");
        else if (ans) printf("MAYBE\n");
        else printf("NO\n");
    }
    
    return 0;
    
}
 
