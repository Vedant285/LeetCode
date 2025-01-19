class Solution {
public:
    int n;
    int maxProfit(vector<int>& arr) {
        n = arr.size();
        vector<vector<int>>dp(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int bos = 1; bos >= 0; bos--) {
                if(bos == 0) {
                    dp[i][bos] = max(-arr[i] + dp[i + 1][1], dp[i + 1][0]);
                }
                else dp[i][bos] = max(arr[i] + dp[i + 1][0], dp[i + 1][1]);
            }
        }

        return dp[0][0];
    }
};