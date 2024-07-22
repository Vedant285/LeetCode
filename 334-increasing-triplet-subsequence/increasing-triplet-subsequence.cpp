class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = size(nums);
        if (n < 3) {
            return false;
        } 
        int f = INT_MAX, s = INT_MAX;
        for (int i = 0; i < n ; i++) {
            if (nums[i] <= f) {
                f = nums[i];
            }
            else if (nums[i] <= s) {
                s = nums[i];
            }
            else {
                return true;
            }
        }
        return false;
    }
};