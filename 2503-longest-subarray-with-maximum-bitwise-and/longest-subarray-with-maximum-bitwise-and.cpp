class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0, len = 0;
        int x = max_element(nums.begin(), nums.end()) - nums.begin();
        int curr = nums[x];
        for (int i = x; i < nums.size(); i++) {
            if(nums[i] == curr) {
                len++;
            }
            else {
                len = 0;
            }
            maxi = max(maxi, len);
        }

        return maxi;
    }
};