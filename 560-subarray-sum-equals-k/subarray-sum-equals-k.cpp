class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currSum = 0;
        int len = 0;

        for (auto &it : nums) {
            currSum += it;
            if(mp.count(currSum - k)) len += mp[currSum - k];
            mp[currSum]++;
        }
        return len;
    }
};