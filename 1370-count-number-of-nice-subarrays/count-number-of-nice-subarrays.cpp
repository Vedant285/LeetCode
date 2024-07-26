class Solution {
public:
    int check(vector<int>& nums, int k){
        int l = 0, r = 0, ans = 0, cnt = 0;
        while (r < nums.size()) {
            cnt += (nums[r] & 1);
            while (cnt > k) {
                cnt -= (nums[l] & 1);
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return check(nums, k) - check(nums, k - 1);
    }
};