class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int maxi=INT_MIN;
        for(auto it:mp){
            if(it.second>maxi){
                maxi=it.second;
            }
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second==maxi){
                cnt+=maxi;
            }
        }
        return cnt;
    }
};