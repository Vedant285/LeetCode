// Minimum Depth of Binary Tree solution

class Solution {
    public int minDepth(TreeNode root) {
        if(root==null)return 0;
        int n=minDepth(root.left);
        int m=minDepth(root.right);
        if(n==0 || m==0)return 1+m+n;
        return Math.min(n,m)+1;
    }
}
