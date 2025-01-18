class Solution {
public:
    int solve(int i, int t, vector<int>& arr) {
        if(i < 0) {
            return t == 0;
        }

        int p = solve(i - 1, t - arr[i], arr);
        int n = solve(i - 1, t + arr[i], arr);
        return p + n;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n - 1, target, nums);
    }
};