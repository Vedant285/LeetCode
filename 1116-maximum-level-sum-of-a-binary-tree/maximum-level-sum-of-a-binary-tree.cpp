class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = 0;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            int sum = 0;
            level++;
            while (sz--) {
                auto it = q.front();
                q.pop();
                sum += it->val;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            if(sum > maxi) {
                maxi = sum;
                ans = level;
            }
        }
        return ans;
    }
};