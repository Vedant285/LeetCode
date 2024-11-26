class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        long long exp = n * (n + 1)/2;
        return exp - sum; 
    }
};