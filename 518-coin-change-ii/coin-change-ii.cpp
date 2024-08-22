class Solution {
public:
    int change(int amount, vector<int>& arr) {
        int n = arr.size();
        //vector<vector<long>> dp(n, vector<long>(amount + 1, 0));
        vector<int> prev(amount + 1, 0);
        for (int i = 0; i <= amount; i++) {
            if (i % arr[0] == 0) prev[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int nottake = prev[t];
                int take = 0;
                if (arr[i] <= t) take = prev[t - arr[i]];
                prev[t] = take + nottake;
            }
        }
        return prev[amount];
    }
};