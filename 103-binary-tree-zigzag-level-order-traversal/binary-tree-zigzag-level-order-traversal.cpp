/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> pq;
        pq.push(root);
        bool check = true;
        while (!pq.empty()) {
            int n = pq.size();
            vector<int>temp(n);

            for (int i = 0; i < n; i++) {
                TreeNode* node = pq.front();
                pq.pop();
                int idx = check == true? i : n - i - 1;
                temp[idx] = node->val;
                if(node->left) pq.push(node->left);
                if(node->right) pq.push(node->right);
            }
            ans.push_back(temp);
            check = !check;
        }
        return ans;
    }
};