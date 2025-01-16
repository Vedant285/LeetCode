class Solution {
public:
    bool canPartition(vector<int>& arr) {
        long long s = accumulate(arr.begin(), arr.end(), 0);
        if(s %2 != 0) return 0;
        s /= 2;
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(s + 1, 0));

        for (int sum = 0; sum <= s; sum++) {
            if(arr[0] == sum) dp[0][sum] = 1;
        }


        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= s; sum++) {
                    int take = (arr[i] <= sum) ? dp[i - 1][sum - arr[i]]: 0;
                    int nottake = dp[i - 1][sum];
                    dp[i][sum] = take || nottake;
            }
        }

        return dp[n - 1][s];
    }
};