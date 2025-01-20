class Solution {
public:
    int n;
    int solve(int i, int prev, vector<int>& arr, vector<vector<int>> &dp) {
        if(i == n) return 0;
        if(dp[i][prev+ 1] != -1) return dp[i][prev+ 1];
        int t = (prev == -1 || arr[i] > arr[prev])? 1 + solve(i + 1, i, arr, dp): INT_MIN;
        int nt = solve(i + 1, prev, arr, dp);
        return dp[i][prev+ 1] = max(t, nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n +1, -1));
        return solve(0, -1,  nums, dp);
    }
};