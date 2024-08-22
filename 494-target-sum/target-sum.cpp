class Solution {
public:
    int cnt;
    void solve(int i, vector<int>& nums, int target){
        if(i < 0) {
            if(target == 0) cnt++;
            return;
        }

        solve(i - 1, nums, target + nums[i]);
        solve(i - 1, nums, target - nums[i]);
    } 
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = size(nums);
        solve(n - 1, nums, target);
        return cnt;
    }
};