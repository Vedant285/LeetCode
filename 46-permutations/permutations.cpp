class Solution {
public:
    vector<vector<int>>ans;
    void check(int idx,vector<int>& nums) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i<nums.size(); i++) {
            swap(nums[idx],nums[i]);
            check(idx+1,nums);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        check(0,nums);
        return ans;
    }
};