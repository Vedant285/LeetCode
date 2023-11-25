class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int pref=0;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int l=pref;
            int r=sum-pref-nums[i];
            res[i]=(nums[i]*i)-l+r-(nums[i]*(n-i-1));
            pref+=nums[i];
        }
        return res;
    }
};