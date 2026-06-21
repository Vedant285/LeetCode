class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = *max_element(costs.begin(), costs.end());
        vector<int>cnt(maxi + 1, 0);
        for (auto &it : costs) {
            cnt[it]++;
        }   
        int ans = 0;
        for (int i = 0; i <= maxi; i++) {
            while (coins >= i && cnt[i] > 0) {
                ans++;
                coins -= i;
                cnt[i]--;
            }
        }
        return ans;
    }
};