class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[high]) {
                // The minimum element is in the right half
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                // The minimum element is at mid or in the left half
                high = mid;
            } else {
                // Handle duplicate: safely reduce the search space
                high--;
            }
        }
        
        return nums[low];
    }
};