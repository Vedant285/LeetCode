class Solution {
public:
    int solve(int i, int j, string s, string t) {
        if(i < 0 || j < 0) return 0;

        if(s[i] == t[j]) 
            return 1 + solve(i - 1, j - 1, s, t);

        return max(solve(i - 1, j, s, t), solve(i, j - 1, s, t));
    }
    int minInsertions(string s) {
        int n = s.size();
        string k = s;
        reverse(k.begin(), k.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++)  dp[i][0] = 0;
        for (int i = 0; i <= n; i++)  dp[0][i] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(s[i - 1] == k[j - 1]) 
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else dp[i][j] = max(dp[i - 1][j],  dp[i][j - 1]);
            }
        }
        return n - dp[n][n];
    }
};