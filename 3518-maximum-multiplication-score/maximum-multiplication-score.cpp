#define ll long long int
int mod = 1e9;
class Solution {
public:

    ll check(int i, int j, vector<int>& a, vector<int>& b, vector<vector<ll>> &dp) {
        if(i < 0 ) {
            return 0;
        }
        if(j < 0) return -1e9;
        if(dp[i][j] != -1e9) return dp[i][j];

        ll take =(a[i]*1LL * b[j]*1LL) + check(i - 1, j - 1, a, b, dp);
        ll nottake = check(i, j - 1, a, b, dp);

        return dp[i][j] = max(take, nottake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1e9));

        for (int j = 0; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ll take =(a[i - 1]*1LL * b[j - 1]*1LL) + dp[i - 1][j - 1];
                ll nottake = dp[i][j - 1];
                dp[i][j] = max(take, nottake);
            }
        }

        return dp[n][m];
    }
};