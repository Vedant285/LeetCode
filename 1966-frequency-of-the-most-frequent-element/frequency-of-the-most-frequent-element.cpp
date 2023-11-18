class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s=0;
        int res=0;
        int n=nums.size();
        long curr=0;
        for(int i=0;i<n;i++){
            long tar=nums[i];
            curr+=nums[i];
            if((i-s+1)*tar-curr>k){
                curr-=nums[s];
                s++;
            }
            res=max(res,i-s+1);
        }
        return res;
    }
};