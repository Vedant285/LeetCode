#define pi pair<int, int>
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        unordered_map<int, pi>mp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }
        vector<int>r(n, m), c(m, n);
        
        for (int i = 0; i < arr.size(); i++) {
            int it = arr[i];
            int nr = mp[it].first;
            int nc = mp[it].second;
            r[nr]--;
            c[nc]--;
            if(r[nr] == 0 || c[nc] == 0) return i;
        }
        return -1;
    }
};