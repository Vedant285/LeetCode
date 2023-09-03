class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void solve(int idx,vector<int>& candidates, int target,vector<int>& temp){
        if(idx>=n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[idx]<=target){
            temp.push_back(candidates[idx]);
            solve(idx,candidates,target-candidates[idx],temp);
            temp.pop_back();
        }
        solve(idx+1,candidates,target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>temp;
        solve(0,candidates,target,temp);
        return ans;
    }
};