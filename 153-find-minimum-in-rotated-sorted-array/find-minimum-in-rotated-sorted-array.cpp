class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(nums[0] < nums[n - 1]) return nums[0];

        int l = 0, r = n - 1;
        int mini = INT_MAX;
        while (l <= r) {
            int mid = (l + r)/2;
            mini = min(mini, nums[mid]);

            if(nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid  - 1;
            }
        }
        return mini;
    }
};