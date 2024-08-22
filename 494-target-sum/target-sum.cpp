class Solution {
public:
    int cnt = 0;
    void solve(int i, vector<int>& nums, int target, int ans){
        if(i == nums.size()) {
            if(target == ans) cnt++;
            return;
        }

        solve(i + 1, nums, target, ans + nums[i]);
        solve(i + 1, nums, target, ans - nums[i]);
    } 
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = size(nums);
        solve(0, nums, target, 0);
        return cnt;
    }
};