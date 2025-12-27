class Solution {
public:
    int res = 0;
    int check(TreeNode* root) {
        if(!root) return 0;
        int l = check(root->left);
        int r = check(root->right);
        res = max(res, l + r + 1);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = check(root);
        return res - 1;
    }
};