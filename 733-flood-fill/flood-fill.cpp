class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];
        if(prev == color) return image;
        queue<pair<int, int>> pq;
        int n = image.size(), m = image[0].size();

        pq.push({sr, sc});
        while (!pq.empty()) {
            auto it = pq.front();
            pq.pop();
            int i = it.first;
            int j = it.second;

            image[i][j] = color;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};

            for (int k = 0; k < 4; k++) {
                int newr = i + dr[k];
                int newc = j + dc[k];
                if(newr >= 0 && newc >= 0 && newr < n && newc < m && image[newr][newc] == prev) {
                    pq.push({newr, newc});
                }
            }
        }
        return image;
    }
};