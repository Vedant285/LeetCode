class Graph {
public:
    vector<vector<pair<int,int>>>adj;
    int s;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        s=n;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            adj[u].push_back({v,wt});
        }
    }
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        adj[u].push_back({v,wt});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(s,1e9);
        pq.push({0,node1});
        dis[node1]=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int new_Node=it.first;
                int new_Wt=it.second;
                if(dis[node]+new_Wt<dis[new_Node]){
                    dis[new_Node]=dis[node]+new_Wt;
                    pq.push({dis[new_Node]+new_Wt,new_Node});
                }
            }
        }
        return dis[node2]==1e9?-1:dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */