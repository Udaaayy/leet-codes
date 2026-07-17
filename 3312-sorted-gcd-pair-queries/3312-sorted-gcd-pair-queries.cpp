class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
      int maxNum = *std::max_element(nums.begin(), nums.end());
        
        // Count the frequency of each number in nums
        std::vector<long long> count(maxNum + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        
        // exactPairs[i] will store the number of pairs with GCD exactly equal to i
        std::vector<long long> exactPairs(maxNum + 1, 0);
        for (int i = 1; i <= maxNum; ++i) {
            long long multiples = 0;
            for (int j = i; j <= maxNum; j += i) {
                multiples += count[j];
            }
            // Number of pairs where both elements are multiples of i
            exactPairs[i] = multiples * (multiples - 1) / 2;
        }
        
        // Inclusion-exclusion: subtract pairs with larger multiples to get exact GCD counts
        for (int i = maxNum; i >= 1; --i) {
            for (int j = 2 * i; j <= maxNum; j += i) {
                exactPairs[i] -= exactPairs[j];
            }
        }
        
        // Build a prefix sum array of the exact pair counts
        std::vector<long long> prefixSum(maxNum + 1, 0);
        for (int i = 1; i <= maxNum; ++i) {
            prefixSum[i] = prefixSum[i - 1] + exactPairs[i];
        }
        
        std::vector<int> ans;
        ans.reserve(queries.size());
        
        // Answer each query using binary search (upper_bound)
        for (long long q : queries) {
            auto it = std::upper_bound(prefixSum.begin(), prefixSum.end(), q);
            ans.push_back(std::distance(prefixSum.begin(), it));
        }
        
        return ans;
    }
};