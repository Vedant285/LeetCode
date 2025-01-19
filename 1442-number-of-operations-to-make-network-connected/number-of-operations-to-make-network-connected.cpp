class dsu{
public:
    vector<int>parent, rank;
    dsu(int n) {
        parent.resize(n, 0);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUp(int u) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = findUp(parent[u]);
    }

    void Union(int u, int v) {
        
        int pu = findUp(u);
        int pv = findUp(v);

        if(pu == pv) {
            return;
        }

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans = 0;
        dsu obj(n);
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            if(obj.findUp(u) == obj.findUp(v)) {
                ans++;
            }
            else {
                obj.Union(u, v);
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if(obj.parent[i] == i) cnt++;
        }
       return cnt - 1 <= ans? cnt - 1: -1;
    }
};