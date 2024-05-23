class Solution {
public:
    int cnt = 0;
    unordered_map<int,int>mp;
    void solve(int idx,vector<int>& nums,int n,int k){
        if (idx == n) {
            cnt ++;
            return;
        }
        if (mp[nums[idx]-k] == 0) {
            mp[nums[idx]]++;
            solve(idx+1, nums, n, k);
            mp[nums[idx]]--;
        }
        solve(idx+1, nums, n, k);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        solve(0,nums,n,k);
        return cnt-1;
    }
};