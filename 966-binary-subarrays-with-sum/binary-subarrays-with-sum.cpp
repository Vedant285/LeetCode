class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int ans = 0, pre = 0;
       unordered_map<int, int> mp;
        mp[0] = 1;

       for(auto it : nums) {
            pre += it;
            int diff = pre - goal;
            ans += mp[diff];
            mp[pre]++;
       }
        return ans;
    }
};