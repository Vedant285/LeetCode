class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=(n*(n+1))/2;
        long long sum=0;
        for(auto it:nums){
            sum+=it;
        }
        return ans-sum;
    }
};