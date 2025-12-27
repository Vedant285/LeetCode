class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> pq;
        pq.push(root);
        while (!pq.empty()) {
            int sz = pq.size();
            vector<int>temp;
            for (int i = 0; i < sz; i++) {
                auto it = pq.front();
                pq.pop();
                temp.push_back(it->val);
                if(it->left) {
                    pq.push(it->left);
                }
                if(it->right) {
                    pq.push(it->right);
                }
            }ans.push_back(temp);
        }
        return ans;
    }
};