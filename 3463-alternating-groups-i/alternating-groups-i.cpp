class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (i == 0) {
                if (arr[i] != arr[i + 1] && arr[i] != arr[n - 1]) {
                    ans ++;
                }
            }
            else if (i == n-1) {
                if (arr[i] != arr[i - 1] && arr[i] != arr[0]) {
                    ans ++;
                }
            }
            else {
                if (arr[i] != arr[i+1] && arr[i] != arr[i - 1]) {
                    ans ++;
                }
            }
        }
        return ans;
    }
};