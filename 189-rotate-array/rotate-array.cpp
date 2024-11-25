class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(begin(nums), end(nums));
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.begin() + k);
        
    }
};