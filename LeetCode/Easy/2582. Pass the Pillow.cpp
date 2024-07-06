// Link: https://leetcode.com/problems/pass-the-pillow/description/

class Solution {
public:
    int passThePillow(int n, int time) {
        int position = 1; // Start at the first person
        bool forward = true; // Direction: true means forward, false means backward

        for (int t = 0; t < time; ++t) {
            if (forward) {
                position++;
                if (position == n) forward = false;
            } 
            else {
                position--;
                if (position == 1) forward = true;
            }
        }

        return position;
    }
};
