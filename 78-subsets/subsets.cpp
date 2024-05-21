class Solution {
public:
    void solve(int idx, vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[idx]);
        solve(idx+1,ans,nums,temp);
        temp.pop_back();
        solve(idx+1,ans,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,ans,nums,temp);
        return ans;
    }
};