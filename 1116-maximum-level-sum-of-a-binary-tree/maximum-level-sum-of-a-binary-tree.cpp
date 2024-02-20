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
    int maxLevelSum(TreeNode* root) {
        int maxiL=0,level=0;
        int maxiP=INT_MIN;
        queue<TreeNode*>pq;
        pq.push(root);
        if(!root)return 0;
        while(!pq.empty()){
            level++;
            int curr=0;
            int n=pq.size();
            for(int i=0;i<n;i++){
                auto node=pq.front();
                pq.pop();
                curr+=node->val;
                if(node->left){
                    pq.push(node->left);
                }
                if(node->right){
                    pq.push(node->right);
                }
            }
            if(maxiP<curr){
                maxiP=curr;
                maxiL=level;
            }
            
        }
        return maxiL;
    }
};