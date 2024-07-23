class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxi = 0;
        int l = 0, r = 0, zero = 0;
        while (r < nums.size()) {
            if (nums[r] == 0) zero++;
            if (zero > k) {
                if(nums[l] == 0) {
                    zero--;
                }
                l++;
            }
            if(zero <= k) {
                maxi = max(maxi, r - l + 1);
            }
            r++;
        }
        return maxi;
    }
};