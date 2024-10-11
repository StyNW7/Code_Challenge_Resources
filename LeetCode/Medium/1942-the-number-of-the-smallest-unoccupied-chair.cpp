// Link: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

       int size = times.size();

       vector <pair<int, int>> arrivals;

       for (int i = 0; i < size; i++) arrivals.push_back({times[i][0], i});

       sort (arrivals.begin(), arrivals.end());

       priority_queue<int, vector<int>, greater<int>> availableChairs;

       for (int i = 0; i < size; i++) availableChairs.push(i);

       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingQueue;

       for (auto& arrival : arrivals){

            int arrivalTime = arrival.first;
            int friendIndex = arrival.second;

            while (!leavingQueue.empty() && leavingQueue.top().first <= arrivalTime){
                availableChairs.push(leavingQueue.top().second);
                leavingQueue.pop();
            }

            int chair = availableChairs.top();
            availableChairs.pop();

            if (friendIndex == targetFriend) return chair;

            leavingQueue.push({times[friendIndex][1], chair});

       }

       return -1;

    }
};
