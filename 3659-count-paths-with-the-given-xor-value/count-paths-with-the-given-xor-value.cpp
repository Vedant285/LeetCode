class Solution {
public:
    int mod = 1e9 + 7;
    int m, n;
    int solve(int i, int j, vector<vector<int>>& grid, int k, int temp, vector<vector<vector<int>>>& dp) {
        if(i >= m || j >= n) return 0;

        if(i == m - 1 && j == n - 1) {
            if((grid[i][j] ^ temp) == k) return 1;
            return 0;
        }
        if(dp[i][j][temp] != -1) return dp[i][j][temp];
        int down = solve(i, j + 1, grid, k, grid[i][j] ^ temp, dp) % mod;
        int left = solve(i + 1, j, grid, k, grid[i][j] ^ temp, dp) % mod; 
    
        return dp[i][j][temp] = (down + left) % mod;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        m= grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(17, -1)));
        return solve(0, 0, grid, k, 0, dp);    
        
    }
};