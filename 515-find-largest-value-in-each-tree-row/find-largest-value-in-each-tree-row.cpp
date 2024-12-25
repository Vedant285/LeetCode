class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>pq;
        vector<int> ans;
        if(!root) return ans;
        pq.push(root);

        while (!pq.empty()) {
            int n = pq.size();
            int maxi = INT_MIN;

            for (int i = 0; i < n; i++) {
                auto it = pq.front();
                pq.pop();
                maxi = max(maxi, it->val);
                if(it->left) pq.push(it->left);
                if(it->right) pq.push(it->right);
            }

            ans.push_back(maxi);
        }

        return ans;        
    }
};