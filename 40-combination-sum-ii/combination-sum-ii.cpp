class Solution {
public:
    void solve(int idx,vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&temp){

        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            temp.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],ans,temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,candidates,target,ans,ds);
        return ans;
    }
};