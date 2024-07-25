// Link: https://leetcode.com/problems/sort-an-array/description/

void merge(std::vector<int>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArr[i] = nums[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = nums[mid + 1 + j];
    
    // Merge the temporary arrays back into nums[left..right]
    int i = 0;
    int j = 0;
    int k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            nums[k] = leftArr[i];
            ++i;
        } else {
            nums[k] = rightArr[j];
            ++j;
        }
        ++k;
    }
    
    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        nums[k] = leftArr[i];
        ++i;
        ++k;
    }
    
    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        nums[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Function to implement merge sort
void mergeSort(std::vector<int>& nums, int left, int right) {
    if (left < right) {
        // Find the middle point
        int mid = left + (right - left) / 2;
        
        // Sort the first and second halves
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        
        // Merge the sorted halves
        merge(nums, left, mid, right);
    }
}

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
