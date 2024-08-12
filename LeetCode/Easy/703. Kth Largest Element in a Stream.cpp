// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to store k largest elements
    int k;

public:
    // Constructor to initialize the object with k and nums
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            add(num);
        }
    }

    // Function to add a new value to the stream
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);  // Add directly if heap size is less than k
        } else if (val > minHeap.top()) {
            minHeap.pop();      // Remove the smallest
            minHeap.push(val);  // Add the new value
        }
        return minHeap.top();   // The k-th largest element
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
