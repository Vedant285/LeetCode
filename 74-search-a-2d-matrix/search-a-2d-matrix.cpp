class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        long long l = 0, h = (n * m -1);
        while (l <= h) {
            int mid = l + (h - l)/2;
            int i = mid/m, j = mid%m;
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] < target) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return false;
    }
};