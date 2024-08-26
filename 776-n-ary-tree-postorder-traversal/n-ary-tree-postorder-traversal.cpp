class Solution {
     vector<int> output;
void tra(Node* root){
    if(root==NULL)return;
    for(auto node:root->children)
        tra(node);
    output.push_back(root->val);
}
    
    
    
public:
    vector<int> postorder(Node* root) {
        tra(root);
        return output;
    }
};