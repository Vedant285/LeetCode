class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, l = 0, r = 0, n = size(nums), cnt = 0;
        unordered_map<int, int>mp;
        while (r < n) {
            cnt += nums[r];
            mp[nums[r]]++;

            while(mp[nums[r]] > 1) {
                mp[nums[l]]--;
                cnt -= nums[l];
                l++;
            }
            
            if(r - l + 1 == k){
                ans = max(ans, cnt);
                mp[nums[l]]--;
                cnt -= nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};