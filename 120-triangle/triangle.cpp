class Solution {
public:
    int solve(int i, int j, int n,vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if(j < 0 || i < 0 || j >= n || i >= n) return 1e9;
        if(i == n - 1) {
            return arr[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int a = arr[i][j] + solve(i + 1, j, n, arr, dp);
        int c = arr[i][j] + solve(i + 1, j + 1, n, arr, dp);
        return dp[i][j] = min(a, c);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, 0, n, triangle, dp);
    }
};