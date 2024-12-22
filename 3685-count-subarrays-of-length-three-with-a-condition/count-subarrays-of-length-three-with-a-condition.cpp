class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            double a = nums[i] + nums[i + 2];
            if((double)nums[i + 1] / 2 == a ) ans++;
        }
        return ans;
    }
};