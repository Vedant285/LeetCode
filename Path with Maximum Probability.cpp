class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        vector<double>result(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double w=succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        result[start]=1;
        priority_queue<pair<int,double>>pq;
        pq.push({start,1.0});
        while(!pq.empty()){
            int node=pq.top().first;
            double prob=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjNode=it.first;
                double adjProb=it.second;
                if(result[adjNode]<adjProb*prob){
                    result[adjNode]=adjProb*prob;
                    pq.push({adjNode,result[adjNode]});
                }
            }
        }
        return result[end];
    }
};
