#define ll long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, ll>> pq;
        pq.push({root, 0});
        ll ans = 0;

        while (!pq.empty()) {
            ll mini = pq.front().second;
            ll f, l;
            ll n = pq.size();

            for (ll i = 0; i < n; i++) {
                auto it = pq.front();
                pq.pop();
                ll t = it.second - mini;
                if(i == 0) f = t;
                if(i == n - 1) l = t;
                if(it.first->left) pq.push({it.first->left, 2 * t + 1});
                if(it.first->right) pq.push({it.first->right, 2 * t + 2});
            }

            ans = max(ans, l - f + 1);
        }

        return ans;
    }
};