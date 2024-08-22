class Solution {
public:
    int solve(int i,int t, vector<int>& arr ) {
        if (i == 0) {
            return (t % arr[0] == 0);
        }
        int nottake = solve(i - 1, t, arr);
        int take = 0;
        if (arr[i] <= t) take = solve(i, t - arr[i], arr);
        return take + nottake;
    }
    int change(int amount, vector<int>& arr) {
        int n = arr.size();
        //vector<vector<long>> dp(n, vector<long>(amount + 1, 0));
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        for (int i = 0; i <= amount; i++) {
            if (i % arr[0] == 0) prev[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int nottake = prev[t];
                int take = 0;
                if (arr[i] <= t) take = curr[t - arr[i]];
                curr[t] = take + nottake;
            }
            prev = curr;
        }
        return prev[amount];
    }
};