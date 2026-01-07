class Solution {
public:
    int maxProduct(TreeNode* root) {
        
        vector<TreeNode*> st;
        st.push_back(root);
        vector<TreeNode*>post;
        while (!st.empty()) {
            TreeNode* it = st.back();
            st.pop_back();
            if(it->left) st.push_back(it->left);
            if(it->right) st.push_back(it->right);
            post.push_back(it);
        }
        vector<long long>temp;
        unordered_map<TreeNode*, long long>mp;
        
        reverse(post.begin(), post.end());
        for (auto it : post) {
            long long currsum = it->val;
            if(it->left) currsum += mp[it->left];
            if(it->right) currsum += mp[it->right];

            mp[it] = currsum;
            temp.push_back(currsum);
        }


        long long maxi = 0, totsum = mp[root];
        for (auto &it : temp) {
            long long sum = it * (totsum - it);
            //maxi = max(maxi, sum);
            if(sum > maxi) maxi = sum;
        }   
        int mod = 1e9 + 7;
        return (int)(maxi%mod);
    }
};