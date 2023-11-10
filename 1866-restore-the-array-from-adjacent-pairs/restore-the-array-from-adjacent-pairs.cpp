class Solution {
public:
    vector<int>ans;
    void dfs(int idx,int prev,unordered_map<int,vector<int>>&adj){
        ans.push_back(idx);
        for(auto it:adj[idx]){
            if(it!=prev){
                dfs(it,idx,adj);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>adj;
        for(auto it:adjacentPairs){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int prev=-1;
        for(auto it:adj){
            if(it.second.size()==1){
                prev=it.first;
                break;
            }
        }
        dfs(prev,INT_MIN,adj);
        return ans;
    }
};