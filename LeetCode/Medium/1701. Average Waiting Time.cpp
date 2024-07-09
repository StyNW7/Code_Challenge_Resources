// Link: https://leetcode.com/problems/average-waiting-time/

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double totalWaitTime = 0;
        int chefAvailableTime = 0;  // Chef starts as idle at time 0

        for (int i = 0; i < n; ++i) {
            int arrivalTime = customers[i][0];
            int orderTime = customers[i][1];

            // Determine when the chef can start preparing this order
            int startPreparationTime = max(arrivalTime, chefAvailableTime);

            // Chef starts preparing the order at startPreparationTime
            int finishTime = startPreparationTime + orderTime;

            // Calculate waiting time for the customer
            int waitingTime = finishTime - arrivalTime;
            totalWaitTime += waitingTime;

            // Update when the chef will be available next
            chefAvailableTime = finishTime;
        }

        // Calculate average waiting time
        double averageWaitTime = totalWaitTime / n;
        return averageWaitTime;
    }
};
