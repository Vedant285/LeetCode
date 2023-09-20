class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[sum]=i;
        }
        if(sum<x)return -1;
        int rem=sum-x;
        int ans=INT_MIN;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int fsum=sum-rem;
            if(mp.find(fsum)!=mp.end()){
                int idx=mp[fsum];
                ans=max(ans,i-idx);
            }
        }
        
        return ans==INT_MIN?-1:n-ans;
    }
};