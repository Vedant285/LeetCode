class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt = 0;
        int pre = 0;
        mp[0] = 1;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            pre += nums[i];
            int diff = pre-k;
            
            cnt+=mp[diff];
            mp[pre]+=1;
        }
        return cnt;
    }
};