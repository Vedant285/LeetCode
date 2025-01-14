class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        for (int idx = 1; idx <= n; idx++) {
            int take = nums[idx - 1];
            if(idx - 2 >= 0) take += dp[idx - 2];
            int nottake = dp[idx - 1];
            dp[idx] = max(take, nottake);

        }
        return dp[n];
    }
};