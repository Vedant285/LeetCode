class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }

        vector<vector<int>> ans(n);
        
        function<void(int, int)> dfs = [&](int node, int ancestor) {
            for (int parent : adj[node]) {
                if (find(ans[ancestor].begin(), ans[ancestor].end(), parent) == ans[ancestor].end()) {
                    ans[ancestor].push_back(parent);
                    dfs(parent, ancestor);
                }
            }
        };

        for (int i = 0; i < n; ++i) {
            dfs(i, i);
            sort(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};
