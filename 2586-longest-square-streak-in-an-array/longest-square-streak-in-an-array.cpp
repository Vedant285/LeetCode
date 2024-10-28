#define ll long long
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<ll> st;
        for (auto it : nums) st.insert(it);

        int ans = 0;
        for (auto it : nums) {
            int tempCount = 0;
            ll curr = it;
            while (st.find(curr) != st.end()) {
                tempCount++;
                curr *= curr;
            }
            ans = max(ans, tempCount);
        }
        return ans > 1 ? ans: -1;
    }
};