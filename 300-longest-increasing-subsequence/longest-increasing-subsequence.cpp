class Solution {
public:
    int solve(int i, int prev, vector<int>& nums) {
        if(i == nums.size()) return 0;

        int nottake = 0 + solve(i + 1, prev, nums);
        int take = INT_MIN;
        if(prev == -1 || nums[i] > nums[prev]) take = 1 + solve(i + 1, i, nums);
        return max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n =  nums.size();
        vector<vector<int>>dp (n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int nottake = dp[i + 1][prev + 1];
                int take = 0;
                if(prev == -1 || nums[i] > nums[prev]) take = 1 + dp[i + 1][i + 1];
                dp[i][prev + 1] = max(take, nottake);
            }
        }
        return dp[0][0];
    }
};