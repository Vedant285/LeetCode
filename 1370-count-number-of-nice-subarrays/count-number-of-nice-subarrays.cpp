class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int pre = 0, ans = 0;
        mp[0] = 1;
        for (auto it : nums) {
            pre += (it % 2);
            int diff = pre - k;
            ans += mp[diff];
            mp[pre]++;
        }
        return ans;
    }
};