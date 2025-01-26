class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        int curr = 0;
        int ans = 0;

        for (int i = 1; i < nums.size(); i++) {
            curr += nums[i - 1];
            sum -= nums[i - 1];
            if(abs(curr - sum) % 2 == 0) ans++;
        }

        return ans;
    }
};