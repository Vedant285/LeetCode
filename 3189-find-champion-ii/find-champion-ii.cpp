class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        for (auto it : edges) {
            vis[it[1]]++;
        }
        int ans = 0, ch = 0;
        for (int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                ans = i;;
                ch++;
            }
        }
        return ch == 1? ans : -1;
    }
};