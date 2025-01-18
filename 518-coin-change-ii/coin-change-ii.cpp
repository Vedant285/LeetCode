class Solution {
public: 
    int change(int amount, vector<int>& arr) {
        int n = arr.size();
        //long long mod = 2e9 + 7;
        vector<double>prev(amount+1, 0), curr(amount + 1, 0);
        
        for (int i = 0; i <= amount; i++) {
            if(i % arr[0] == 0) prev[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                
                double ta = (arr[i] <= t)? curr[t - arr[i]]: 0;
                double nt = prev[t];
                curr[t] = (ta + nt);
            }
            prev = curr;
        }

        return (int)prev[amount];
    }
};