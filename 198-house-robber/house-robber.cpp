class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        if(idx < 0) {
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx] + solve(idx - 2, nums, dp);
        int nottake = solve(idx - 1, nums, dp);
        return dp[idx] = max(take, nottake);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
};