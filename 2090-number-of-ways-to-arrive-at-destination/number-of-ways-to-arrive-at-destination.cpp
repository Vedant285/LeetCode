class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long,long>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long,long >,vector<pair<long , long>>,greater<pair<long ,long >>>pq;
        vector<long>dis(n,LONG_MAX),ways(n,0);
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod=(int)(1e9+7);
        while(!pq.empty()){
            long long dist=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long adjnode=it.first;
                long long ed=it.second;
                if(dist+ed < dis[adjnode]){
                    dis[adjnode]=dist+ed;
                    pq.push({dist+ed,adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(dist+ed==dis[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};