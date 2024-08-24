class Solution {
public:
    int solve(int r1, int c1, int r2, int c2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp) {
        if(r1 >= n || c1 >= m || r2 >= n || c2 >= m || c1 < 0 || c2 < 0) return -1e9;

        if(r1 == n - 1 && r2 == n - 1) {
            if (c1 == c2) return grid[r1][c1];
            return grid[r1][c1] + grid[r2][c2];
        }
        if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];
        int maxi = INT_MIN;
        for (int i = -1; i < 2; i++) {
            for(int j = -1; j < 2; j++) {
                int ans;
                if(c1 == c2 && r1 == r2)
                    ans = grid[r1][c1] + solve(r1 + 1, c1 + i, r2 + 1, c2 + j, n, m, grid, dp);
                else
                    ans = grid[r1][c1] + grid[r2][c2] + solve(r1 + 1, c1 + i, r2 + 1, c2 + j, n, m, grid, dp);

                maxi = max(maxi, ans); 
            }
        }
        return dp[r1][c1][r2][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = size(grid[0]);
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, -1))));
        return solve(0, 0, 0, m - 1,n, m, grid, dp);
    }
};