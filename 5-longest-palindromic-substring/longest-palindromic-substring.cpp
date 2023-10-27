class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int maxi = 1;
        int start = 0;

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
                start = i;
                maxi = 2;
            } else {
                dp[i][i + 1] = 0;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1] != 0) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    if (dp[i][j] > maxi) {
                        maxi = dp[i][j];
                        start = i;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return s.substr(start, maxi);
    }
};
