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
        int result=0;
        for(int i=idx;i<n;i++){
            int a=solve(0,nums,target-nums[i],dp);
            result+=a;
        }
        return dp[idx][target]=result;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};