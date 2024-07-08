// Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
public:
    int findTheWinner(int n, int k) {
        // Create a vector to represent the circle of friends
        vector<int> friends(n);
        for (int i = 0; i < n; ++i) {
            friends[i] = i + 1;
        }

        int currentIndex = 0;  // Start from the first friend

        // Continue until only one friend is left in the circle
        while (friends.size() > 1) {
            // Calculate the index of the friend who will lose the game
            currentIndex = (currentIndex + k - 1) % friends.size();
            // Remove the friend who loses the game
            friends.erase(friends.begin() + currentIndex);
        }

        // Return the last friend remaining in the circle
        return friends[0];
    }
};
