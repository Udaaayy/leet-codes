class Solution {
public:
    int findGCD(vector<int>& nums) {
        // Find the minimum and maximum values in the array
        int min_val = *std::min_element(nums.begin(), nums.end());
        int max_val = *std::max_element(nums.begin(), nums.end());
        
        // Return the greatest common divisor using the built-in std::gcd (C++17)
        return std::gcd(min_val, max_val);
    }
};