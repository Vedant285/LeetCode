class Solution {
public:

    int solve(vector<vector<int>>& grid, int prev, int i, int j, vector<vector<int>>&dp) {

        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
        int curr = grid[i][j];

        if(prev >= curr) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = 1 + max({solve(grid, curr, i + 1, j + 1, dp), solve(grid, curr, i, j + 1, dp), solve(grid, curr, i - 1, j + 1, dp)});
       
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = INT_MIN;
        for (int i = 0; i < grid.size(); i++)
            ans = max(ans, solve(grid, -1, i, 0, dp));
        return ans - 1;
    }
};