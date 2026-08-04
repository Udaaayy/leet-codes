#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<int> findMissingElements(std::vector<int>& nums) {
        if (nums.empty()) return {};

        // 1. Find the minimum and maximum elements in nums
        int min_val = nums[0];
        int max_val = nums[0];
        
        std::unordered_set<int> present_nums;
        for (int num : nums) {
            min_val = std::min(min_val, num);
            max_val = std::max(max_val, num);
            present_nums.insert(num);
        }

        // 2. Iterate through the range [min_val, max_val] and collect missing numbers
        std::vector<int> result;
        for (int i = min_val; i <= max_val; ++i) {
            if (present_nums.find(i) == present_nums.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};