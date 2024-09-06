class Solution {
    vector<vector<int>> ans;
    vector<int>temp;
    void dfs(int node,vector<int> adj[],vector<vector<int>>& graph,int n)
    {
        temp.push_back(node);
        if(node==n-1)
        {
            ans.push_back(temp);
        }
        for(auto it: adj[node])
        {
            dfs(it,adj,graph,n);
        }
        temp.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto it: graph[i])
            {
                adj[i].push_back(it);
            }
        }
        dfs(0,adj,graph,n);
        return ans;
        
    }
};