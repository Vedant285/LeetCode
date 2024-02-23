class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int curr=target-nums[i];
            if(mp.find(curr)!=mp.end()){
                return {i,mp[curr]};
            }
            mp[nums[i]]=i;
        }
        return {};

    }
};