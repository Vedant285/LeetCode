class Solution {
public:
    int longestPalindromeSubseq(string a) {
        string b = a;
        int n = a.size();
        reverse(b.begin(), b.end());    
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <=n; j++) {
                int t = 0, nt = 0;
                if(a[i - 1] == b[j - 1]) t = 1 + dp[i - 1][j - 1];
                nt = max(dp[i - 1][j], dp[i][j - 1]);

                dp[i][j] = max(t, nt);
            }
        }
        
        return dp[n][n];
    }
};