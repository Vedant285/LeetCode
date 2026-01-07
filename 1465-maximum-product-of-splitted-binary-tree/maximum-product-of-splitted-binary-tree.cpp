class Solution {
public:
    vector<long long>temp;
    int solve(TreeNode* root){
        if(!root) return 0;

        int l = solve(root->left);
        int r = solve(root->right);
        int currsum  = l + r + root->val;
        temp.push_back(currsum); 
        return currsum;
    }
    int maxProduct(TreeNode* root) {
        long long totsum = solve(root);
        long long maxi = INT_MIN;
        for (auto &it : temp) {
            long long sum = it * (totsum - it);
            maxi = max(maxi*1LL, sum);
        }   
        int mod = 1e9 + 7;
        return (int)(maxi%mod);
    }
};