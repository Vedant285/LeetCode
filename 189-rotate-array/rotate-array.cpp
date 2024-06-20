class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = size(nums);
        k %= n;
        int rst = n - k;
        reverse(nums.begin(), nums.begin() + rst);

        reverse(nums.begin() + rst , nums.end());
        reverse(nums.begin(), nums.end());

    }
};