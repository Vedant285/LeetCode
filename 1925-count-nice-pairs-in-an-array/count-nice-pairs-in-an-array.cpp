class Solution {
public:
    int rev(int n){
        int ans=0;
        while(n){
            int ldx=n%10;
            ans=ans*10+ldx;
            n/=10;
        }
        return ans;
    }    
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-rev(nums[i]);
        }
        int result=0;
        int mod=1e9+7;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            result=(result+mp[nums[i]])%mod;
            mp[nums[i]]++;
        }
        return result;
    }
};