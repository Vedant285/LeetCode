class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long maxi = 0;
        long long sum = 0;
        int i = 0, n = nums.size();
        int j = 0;
        while (i < n) {
            mp[nums[i]]++;
            sum += nums[i];

            while(mp[nums[i]] > 1 || i - j + 1 > k ) {
                mp[nums[j]]--;
                sum -= nums[j];
                if(mp[nums[j]] == 0) mp.erase(nums[j]);
                j++;
            }
            if(i - j + 1 == k) maxi = max(maxi, sum);
            i++;
        }
        return maxi;
    }
};