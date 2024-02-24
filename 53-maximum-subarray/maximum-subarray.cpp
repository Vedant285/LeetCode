class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxi=LONG_MIN;
        long long sum=0;
        for(auto it:nums){
            sum+=it;
            if(sum>maxi){
                maxi=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};