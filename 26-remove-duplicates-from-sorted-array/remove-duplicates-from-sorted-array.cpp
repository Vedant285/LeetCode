class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int r = 0, l = 0;
        while (l < size(nums)) {

            if (nums[l] != nums[r]) {
                r++;
                nums[r] = nums[l];
            }
            l++;
        }
        return r + 1;
    }
};