// Link: https://leetcode.com/problems/minimum-time-difference/

int timeToMinutes(const string &time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        vector<int> minutes;

        for (const string& time : timePoints) {
            minutes.push_back(timeToMinutes(time));
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        int n = minutes.size();

        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        int wrapAroundDiff = (1440 - minutes[n - 1] + minutes[0]);
        minDiff = min(minDiff, wrapAroundDiff);

        return minDiff;
    }
};
