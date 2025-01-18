class Solution {
public: 
    int change(int amount, vector<int>& arr) {
        int n = arr.size();
        //long long mod = 2e9 + 7;
        vector<vector<double>>dp(n, vector<double>(amount+1, 0));
        
        for (int i = 0; i <= amount; i++) {
            if(i % arr[0] == 0) dp[0][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                
                double ta = (arr[i] <= t)? dp[i][t - arr[i]]: 0;
                double nt = dp[i - 1][t];
                dp[i][t] = (ta + nt);
            }
        }

        return (int)dp[n - 1][amount];
    }
};