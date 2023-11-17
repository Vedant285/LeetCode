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
    bool solve(TreeNode* r,TreeNode* l){
        if(r==NULL && l==NULL)return true;
        if(r==NULL && l!=NULL || r!=NULL && l==NULL)return false;
        bool a=solve(r->left,l->right);
        bool b=solve(r->right,l->left);
        //if(a && b)return true;
        return (r->val==l->val) &&(a && b);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};