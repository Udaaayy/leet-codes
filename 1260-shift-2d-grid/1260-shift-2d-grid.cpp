class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Effective shifts needed
        k = k % total;
        
        std::vector<std::vector<int>> result(m, std::vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Convert 2D index (i, j) to 1D index
                int old1DIndex = i * n + j;
                
                // Calculate new 1D index after shifting k positions
                int new1DIndex = (old1DIndex + k) % total;
                
                // Convert 1D index back to 2D coordinates (newRow, newCol)
                int newRow = new1DIndex / n;
                int newCol = new1DIndex % n;
                
                result[newRow][newCol] = grid[i][j];
            }
        }
        
        return result;
    }
};