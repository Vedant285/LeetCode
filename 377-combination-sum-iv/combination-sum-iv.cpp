class Solution {
public:
    int n;
    int solve(int idx,vector<int>& nums, int target,vector<vector<int>>&dp){
        if(target==0){
            return 1;
        }
        if(idx==n || target<0){
            return 0;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int take=solve(0,nums,target-nums[idx],dp);
        int nott=solve(idx+1,nums,target,dp);
        return dp[idx][target]=take+nott;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};