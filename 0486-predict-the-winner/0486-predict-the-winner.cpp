class Solution {
    private:
    int memo[23][23];

    int solve(int i, int j, const std::vector<int>& nums) {
        // Base case: Only one element left
        if (i == j) {
            return nums[i];
        }

        // Return cached result if already computed
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        // Choice 1: Pick start element
        int pickLeft = nums[i] - solve(i + 1, j, nums);
        // Choice 2: Pick end element
        int pickRight = nums[j] - solve(i, j - 1, nums);

        return memo[i][j] = std::max(pickLeft, pickRight);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // Base case: If size is even, Player 1 can always force a win
        if (n % 2 == 0) return true;

        // Initialize memoization table with -1
        std::fill(&memo[0][0], &memo[0][0] + 23 * 23, -1);

        return solve(0, n - 1, nums) >= 0;
    }
};