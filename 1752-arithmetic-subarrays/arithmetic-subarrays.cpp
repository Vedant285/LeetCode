class Solution {
public:
    bool check(vector<int>&nums){
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int d=nums[1]-nums[0];
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]!=d){
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        int n=l.size();
        for(int i=0;i<n;i++){
            int s=l[i];
            int e=r[i];
            vector<int>temp(nums.begin()+s,nums.begin()+e+1);
            bool isap=check(temp);
            ans.push_back(isap);
        }
        return ans;
    }
};