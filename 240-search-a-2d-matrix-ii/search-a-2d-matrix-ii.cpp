class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = size(matrix), m = size(matrix[0]);
        int l = 0, h = m - 1;
        while (l < n && h >= 0) {
            if (matrix[l][h] == target) {
                return true;
            }
            else if (matrix[l][h] < target) {
                l++;
            }
            else {
                h--;
            }
        }
        return false;
    }
};