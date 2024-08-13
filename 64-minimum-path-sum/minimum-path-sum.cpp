class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return grid[i][j];
        int t1 = INT_MAX, t2 = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        if(i > 0) t1 = grid[i][j] + solve(i - 1, j, grid, dp);
        if(j > 0) t2 = grid[i][j] + solve(i, j - 1, grid, dp);
        return dp[i][j] = min(t1, t2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));
        return solve(n - 1, m - 1, grid, dp);
    }
};