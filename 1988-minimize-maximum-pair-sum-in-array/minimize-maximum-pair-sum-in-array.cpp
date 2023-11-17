class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        vector<int>maxi;
        while(i<j){
            int a=nums[i]+nums[j];
            maxi.push_back(a);
            i++;
            j--;
        }
        return (*max_element(maxi.begin(),maxi.end()));
    }
};