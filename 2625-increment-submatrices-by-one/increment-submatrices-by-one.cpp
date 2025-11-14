class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        for (auto it : queries) {
            int x1 = it[0];
            int y1 = it[1];
            int x2 = it[2];
            int y2 = it[3];

            arr[x1][y1]++;
            if(x2 + 1 < n) arr[x2 + 1][y1]--;
            if(y2 + 1 < n) arr[x1][y2 + 1]--;
            if(x2 + 1 < n && y2 + 1 < n) arr[x2 + 1][y2 + 1]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a = i? arr[i - 1][j]: 0;
                int l = j? arr[i][j - 1]:0;
                int d = (i && j) ? arr[i - 1][j - 1]:0;

                arr[i][j] += a + l - d;
            }
        }

        return arr;
    }
};