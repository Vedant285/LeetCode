class Solution {
public:
    int solve(int idx, vector<int>& nums, int curr) {
        if (idx == nums.size()) {
            return curr;
        }
        int a = solve(idx+1,nums, nums[idx]^curr);
        int b = solve(idx+1,nums,curr);
        return a+b;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0,nums,0);
    }
};