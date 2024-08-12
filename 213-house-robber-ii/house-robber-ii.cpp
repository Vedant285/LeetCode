class Solution {
public:
    int solve(int idx, vector<int>& nums, vector<int>& dp) {
        if(idx == 0) return nums[0];
        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx];
        if (idx > 1) {
            take = nums[idx] + solve(idx - 2, nums, dp);
        }
        int nottake = solve(idx - 1, nums, dp);
        return dp[idx] = max(take, nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp(n, -1), dp2(n, -1);
        vector<int>a1;
        vector<int> a2;

        for (int i = 0; i < n; i++) {
            if (i != 0) a1.push_back(nums[i]);
            if (i != n - 1) a2.push_back(nums[i]);
        }
        return max(solve(a1.size() - 1, a1, dp), solve(a2.size() - 1, a2, dp2));
    }
};
