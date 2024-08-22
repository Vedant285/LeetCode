class Solution {
public:
    int coinChange(vector<int>& arr, int amo) {
        int n = arr.size();
        //vector<vector<int>> dp(n, vector<int>(amo + 1));
        vector<int> prev(amo + 1), curr(amo + 1);
        for (int i = 0; i <= amo; i++) {
            if(i % arr[0] == 0) prev[i] = i / arr[0];
            else prev[i] = 1e9;
        }
        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amo; t++) {

                int nottake = prev[t];
                int take = 1e9;
                if(arr[i] <= t) take = 1 + prev[t - arr[i]];

                prev[t] = min(take, nottake);
            }
            //prev = curr;
        }

        if (prev[amo] >= 1e9) return -1;
        return prev[amo];
    }
};