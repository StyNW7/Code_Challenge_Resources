// Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long n = skill.size();

        sort(skill.begin(), skill.end());

        long long totalSkill = skill[0] + skill[n-1];
        long long chemistrySum = 0;

        for (long long i = 0; i < n / 2; ++i) {
            long long currentTeamSkill = skill[i] + skill[n - 1 - i];
            
            if (currentTeamSkill != totalSkill) {
                return -1;
            }

            chemistrySum += skill[i] * skill[n - 1 - i];
        }

        return chemistrySum;
    }
};
