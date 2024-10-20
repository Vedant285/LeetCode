class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;
        queue<pair<TreeNode*, pair<int, int>>>pq;
        pq.push({root, {0, 0}});

        while(!pq.empty()) {
            auto node = pq.front();
            pq.pop();
            TreeNode* data = node.first;
            int x = node.second.first;
            int y = node.second.second;

            mp[x][y].insert(data->val);

            if(data->left) {
                pq.push({data->left, {x - 1, y + 1}});
            }
            if(data->right) {
                pq.push({data->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto it : mp) {
            vector<int> temp;
            for (auto k : it.second) {
                temp.insert(temp.end(), k.second.begin(), k.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};