class Solution {
public:
    int coinChange(vector<int>& arr, int amount) {
        int n = arr.size();
        vector<long long>prev(amount + 1), curr(amount + 1);

        for (int t = 0; t <= amount; t++) {
            if(t % arr[0] == 0) prev[t] = t/arr[0];
            else prev[t] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int take = 1e9;
                if(arr[i] <= t) take = 1 + curr[t - arr[i]];
                int nottake = prev[t];
                curr[t] = min(take, nottake);
            }
            prev = curr;
        }

        return prev[amount] >= 1e9? -1: prev[amount];
    }
};