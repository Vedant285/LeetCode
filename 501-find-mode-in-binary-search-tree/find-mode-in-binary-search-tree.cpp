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
    unordered_map<int,int>mp;
    void countNum(TreeNode* root){
        if(!root){
            return;
        }
        countNum(root->left);
        mp[root->val]++;
        countNum(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        countNum(root);
        int maxi=0;
        for(auto it:mp){
            maxi=max(maxi,it.second);
        }
        vector<int>ans;
        for(auto it:mp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};