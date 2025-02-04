class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int t = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(i == 0 || nums[i - 1] < nums[i]) {
                t += nums[i];
            }
            else {
                ans = max(ans, t);
                t = nums[i];
            }
        }
        ans = max(ans, t);
        return ans;
    }
};