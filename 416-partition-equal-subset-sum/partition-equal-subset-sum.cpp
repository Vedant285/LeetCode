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
        vector<vector<int>>dp(n + 1, vector<int>((sum/2) + 1, -1));
        return solve(n - 1, sum / 2, nums, dp);
    }
};