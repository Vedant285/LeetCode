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
    string st;
    void helper(TreeNode* root){
        if(!root){
            return ;
        }
        st+=to_string(root->val);
        if(root->left || root->right){
            st+="(";
            helper(root->left);
            st+=")";

            if(root->right){
                st+="(";
                helper(root->right);
                st+=")";
            }
        }
    }
    string tree2str(TreeNode* root) {
        helper(root);
        return st;
        
    }
};