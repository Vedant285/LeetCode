class Solution {
public:
    int solve(TreeNode* root, int &maxi) {
        if (root == NULL) return 0;
        int lh = max(0, solve(root->left, maxi));
        int rh = max(0, solve(root->right, maxi));
        maxi = max(maxi, lh + rh + root->val);
        return (max(lh, rh) + root->val);
    }
    int maxPathSum(TreeNode* root) {
       int maxi = INT_MIN;
       int k = solve(root, maxi);
       return maxi;   
    }
};