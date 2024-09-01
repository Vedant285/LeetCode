class Solution {
public:
int N;
    class UnionFind{
        public:
            vector<int>parent;
            vector<int>rank;
            UnionFind(int n){
                parent.resize(n);
                rank.resize(n,0);
                for(int i=0;i<n;i++){
                    parent[i]=i;
                }
            }
            int find(int x){
                if(x==parent[x]){
                    return x;
                }
                return parent[x]=find(parent[x]);
            }
            bool Union(int x,int y){
                int x_parent=find(x);
                int y_parent=find(y);
                if(x_parent==y_parent){
                    return false;
                }
                if(rank[x_parent]>rank[y_parent]){
                    parent[y_parent]=x_parent;
                }
                else if(rank[x_parent]<rank[y_parent]){
                    parent[x_parent]=y_parent;
                }
                else{
                    parent[x_parent]=y_parent;
                    rank[y_parent]++;
                }
                return true;
            }
    };

    int kruskal(vector<vector<int>>&edges,int skip,int take){

        int sum=0;
        UnionFind uf(N);
        if(take!=-1){
            uf.Union(edges[take][0],edges[take][1]);
            sum+=edges[take][2];
        }
        for(int i=0;i<edges.size();i++){
            if(i==skip)
                continue;
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            int parent_u=uf.find(u);
            int parent_v=uf.find(v);
            if(parent_u!=parent_v){
                uf.Union(u,v);
                sum+=wt;
            }
        }
        for(int i=0;i<N;i++){
            if(uf.find(i)!=uf.find(0))
                return INT_MAX;
        }
        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N=n;
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        auto comperator=[&](auto &v1,auto &v2){
            return v1[2]<v2[2];
        };
        sort(edges.begin(),edges.end(),comperator);
        int MST_WEIGHT=kruskal(edges,-1,-1);
        vector<int>critical,pseudo;
        for(int i=0;i<edges.size();i++){
            if(kruskal(edges,i,-1)>MST_WEIGHT){
                critical.push_back(edges[i][3]);
            }
            else if(kruskal(edges,-1,i)==MST_WEIGHT){
                pseudo.push_back(edges[i][3]);
            }
        }
        return {critical,pseudo};
    }
};