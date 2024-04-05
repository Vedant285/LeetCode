class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int s=0,e=0,z=0;
        while(e<n){
            if(nums[e]==0)z++;
            while(z>k){
                if(nums[s]==0){
                    z--;
                }
                s++;
            }
            if(z<=k){
                maxi=max(maxi,e-s+1);
            }
            e++;
        }
        return maxi;
    }
};