class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> vis(n, 1);
        for (auto it : restricted) {
            vis[it] = 0;
        }
        vector<int>adj [n];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        q.push(0);
        vis[0] = 0;
        int ans = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (vis[it] == 1) {
                    q.push(it);
                    vis[it] = 0;
                    ans++;
                }
            }
        }
        return ans;
    }
};