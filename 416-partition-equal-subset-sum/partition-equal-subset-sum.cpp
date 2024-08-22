class Solution {
public:
    bool solve(int i, int k, vector<int>& nums, vector<vector<int>>& dp) {
        
        if(i == 0) {
            if(k == 0) return true;
            return nums[0] == k;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int nottake = solve(i - 1, k, nums, dp);
        int take = false;
        if(nums[i] <= k) take = solve(i - 1, k - nums[i], nums, dp);
        return dp[i][k] = nottake | take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        int n = size(nums);
        int k = sum / 2;
        vector<vector<bool>>dp(n, vector<bool>(k + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        if(nums[0] <= k) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                int nottake = dp[i - 1][j];
                int take = false;
                if(nums[i] <= j) take = dp[i - 1][j - nums[i]];
                dp[i][j] = nottake | take;
            }
        }
        return dp[n - 1][k];
    }
};