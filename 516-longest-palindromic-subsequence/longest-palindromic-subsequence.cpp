class Solution {
public:
    int solve(int i, int j, string &a, string &b, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int t = 0, nt = 0;
        if(a[i] == b[j]) t = 1 + solve(i - 1, j - 1, a, b, dp);
        nt = max(solve(i - 1, j, a, b, dp), solve(i, j - 1, a, b, dp));

        return dp[i][j] = max(t, nt);
    }
    int longestPalindromeSubseq(string s) {
        string b = s;
        int n = s.size();
        reverse(b.begin(), b.end());    
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(n - 1, n - 1, s, b, dp);
    }
};