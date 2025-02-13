#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>>pq;
        for (auto it : nums) pq.push(it);
        int ans = 0;

        while (pq.size() >= 2 && pq.top() < k) {
            ll a = pq.top();
            pq.pop();
            ll b = pq.top();
            pq.pop();
            ans++;
            ll t = min(a, b)*2 + max(a, b);
            pq.push(t);
        }

        return ans;
    }
};