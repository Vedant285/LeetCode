class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = size(nums);
        int t = -1;
        for (int i = n - 1; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
                t = i - 1;
                break;
            }
        }
        if(t == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = n - 1; i > t; i--) {
            if(nums[i] > nums[t]) {
                swap(nums[i], nums[t]);
                break;
            }
        }
        reverse(nums.begin() + t + 1, nums.end());
    }
};