class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int cnt = 0;
        for (int i = 0 ; i < nums.size(); i++) {
            cnt += nums[i];
            if (cnt > maxi) {
                maxi = cnt;
            }
            if (cnt < 0) {
                cnt = 0;
            }
        }
        return maxi;
    }
};