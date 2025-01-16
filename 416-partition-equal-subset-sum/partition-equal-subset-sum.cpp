class Solution {
public:
    bool solve(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) 
    {
        if(sum == 0) return 1;
        if(i == 0) {
            if(arr[i] == sum) return 1;
            return 0;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int take = (arr[i] <= sum) ? solve(i - 1, sum - arr[i], arr, dp): 0;
        int nottake = solve(i - 1, sum, arr, dp);
        return dp[i][sum] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum %2 != 0) return 0;
        sum /= 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(n - 1, sum, nums, dp);
    }
};