class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l= 0, r = nums.size();
        int a = -1, b = -1;

        while (l < r) {
            int mid = (l + r)/2;
            if(nums[mid] == target) {
                a = mid;
                r = mid;
            }
            else if(nums[mid] > target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r)/2;
            if(nums[mid] == target) {
                b = mid;
                l = mid + 1;
            }
            else if(nums[mid] > target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return {a, b};
    }
};