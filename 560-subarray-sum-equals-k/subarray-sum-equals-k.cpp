class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans = 0;
        int pre = 0;
        mp[0] = 1;
        for (auto it: nums) {
            pre += it;
            int rest = pre - k;
            ans += mp[rest];
            mp[pre] ++;
        }
        return ans;
    }
};