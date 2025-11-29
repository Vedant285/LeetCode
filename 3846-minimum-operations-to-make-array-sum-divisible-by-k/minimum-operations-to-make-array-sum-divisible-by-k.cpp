class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = accumulate(nums.begin(), nums.end(), 0);
        return cnt % k;
    }
};