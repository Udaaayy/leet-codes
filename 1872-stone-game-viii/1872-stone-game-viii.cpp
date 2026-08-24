#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Step 1: Calculate prefix sums in-place
        std::vector<long long> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + stones[i];
        }

        // Base case: If the player takes all stones up to index n-1, 
        // the score difference is pref[n-1] as no stones are left.
        long long max_diff = pref[n - 1];

        // Step 2: Iterate backward from n - 2 down to 1
        // Note: x > 1, so the player must choose at least 2 stones (index >= 1)
        for (int i = n - 2; i >= 1; --i) {
            max_diff = std::max(max_diff, pref[i] - max_diff);
        }

        return max_diff;
    }
};