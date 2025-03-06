class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(); long long tot = (n * n);
        long long sum = tot * (tot + 1)/2;
        unordered_map<int, int>mp;
        
        long long currsum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                currsum += grid[i][j];
                mp[grid[i][j]]++;
            }
        }
        int rep =  0;
        for (auto it : mp) {
            if(it.second == 2) {
                rep = it.first;
                break;
            }
        }
        currsum -= rep;
        return {rep, static_cast<int>(sum - currsum)};
    }
};